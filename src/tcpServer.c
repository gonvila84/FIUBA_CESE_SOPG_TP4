#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <signal.h>
#include <stdlib.h>
#include "tcpServer.h"

#define UI_BE_VERBOSE										true
#define UI_BE_SILENT										false
#define RC_FAILURE											1
#define RC_SUCCESS											0

#define INET_SERVER_ADDRESS									"127.0.0.1"
#define INET_SERVER_PORT									10000
#define INET_SERVER_CONECTION_POOLING_IN_MICROSECONDS		300
#define INET_SERVER_READ_SOCKET_POOLING_IN_MICROSECONDS		600
#define INET_SERVER_WRITE_SOCKET_POOLING_IN_MICROSECONDS	600
#define INET_SERVER_NO_DATA_IN_THE_LINE						0
#define INET_SERVER_READ_ERROR_RC							-1
#define INET_SERVER_WRITE_ERROR_RC							-1
#define INET_CONNECTIONS_QUEUE_LENGTH						10

#define INET_BULB_COMMAND_SIZE								10




pthread_mutex_t	mutexIsClientConnected = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t	mutexIsInetServerDead = PTHREAD_MUTEX_INITIALIZER;



inetSocket_t acceptedConnectionSocket;
inetSocket_t originalConnectionSocket;
bool_t isClientConnected = false;
bool_t isSignalsCalled = false;
bool_t isInetServerDead = false;



operationStatus_t InetServerAcceptIncomingConnections ()
{
	struct sockaddr_in clientAddress;
	char clientIp[32];
	socklen_t addressLength = sizeof(struct sockaddr_in);

	printf ("> Waiting for a new connection to arrive.\n");

	acceptedConnectionSocket  = accept(originalConnectionSocket, (struct sockaddr *)&clientAddress,&addressLength);
	if ( acceptedConnectionSocket == -1)
	{
		printf ("> A failure was detected when trying to accept an incoming connection.\n");
		return FAILURE;
	}
		
	inet_ntop(AF_INET, &(clientAddress.sin_addr), clientIp, sizeof(clientIp));
	printf ("> A connection was accepted (IP: %s).\n",clientIp);

	return SUCCESS;
}



operationStatus_t createSocket(inetSocket_t * socketDescriptor)
{
	*socketDescriptor = socket(AF_INET,SOCK_STREAM, 0);
	if (-1 == *socketDescriptor)
	{
		return FAILURE;
	}
	return SUCCESS;
}



operationStatus_t configureServerSocket(inetSocket_t socket)
{
	struct sockaddr_in serverAddress;
	bzero((char*) &serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(INET_SERVER_PORT);
    
	if(inet_pton(AF_INET, INET_SERVER_ADDRESS, &(serverAddress.sin_addr))<=0)
    {
       	fprintf(stderr,"ERROR invalid server IP\r\n");
    	return FAILURE;
    }


	if (bind(socket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1)
	{
		close(socket);
		perror("listener: bind");
    	return FAILURE;
	}

	printf("> The new socket was successfully bound to the IP address %s.\n", INET_SERVER_ADDRESS);

	if (listen (socket, INET_CONNECTIONS_QUEUE_LENGTH) == -1)
  	{
    	perror("Error while listening");
    	return FAILURE;
  	}

	printf("> The new socket was successfully configured to listen on the IP address %s.\n", INET_SERVER_ADDRESS);
	
	return SUCCESS;
}



socketReadStatus_t readFromServerSocket(char * inetReadBuffer)
{
	ssize_t bytesRead = 0;
	inetReadBuffer[0]=0x00;
	printf("> The server is attempting to read from the socket.\n");
	bytesRead = read(acceptedConnectionSocket,inetReadBuffer,INET_BULB_COMMAND_SIZE);

	if (INET_SERVER_READ_ERROR_RC == bytesRead)
	{
		printf ("> FAILURE: Error while trying to read from the socket.\n");
		return SR_FAILURE;
	}

	if (INET_SERVER_NO_DATA_IN_THE_LINE == bytesRead)
	{
		return SR_NOTHING;
	}

	if (INET_SERVER_NO_DATA_IN_THE_LINE < bytesRead)
	{
		printf ("> Read function received the string: %s (%ld bytes)\n",inetReadBuffer, bytesRead);
		return SR_SUCCESS;
	}
}