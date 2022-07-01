#include <stdbool.h>

/**
 * @brief Enumeracion utilizada para reportar el exito o fracaso de las funciones del programa que asi lo requieran
 * 
 */
typedef enum {
	SUCCESS,
	FAILURE
} operationStatus_t;

typedef enum {
	SR_SUCCESS,
	SR_FAILURE,
	SR_NOTHING
} socketReadStatus_t;



typedef bool bool_t;

typedef int inetSocket_t;



/**
 * @brief Funcion utilizada para crear un socket
 * 
 * @param socketDescriptor Parametro utilizado para devolver el descriptor del socket
 * @return operationStatus_t (SUCCESS: El socket se creo con exito, FAILURE: Se produjeron errores durante la creacion del socket)
 */
operationStatus_t createSocket(inetSocket_t * socketDescriptor);



/**
 * @brief Funcion utilizada para configurar un socket, realizar el bind y configurarlo en modo listen
 * 
 * @param socket Provee el descriptor del socket para realizar la configuracion
 * @return operationStatus_t (SUCCESS: El socket se configuro con exito, FAILURE: Se produjeron errores durante la configuracion del socket)
 */
operationStatus_t configureServerSocket(inetSocket_t socket);



/**
 * @brief Funcion utilizada para leer un dato suministrado a traves del socket
 * 
 * @param inetReadBuffer Parametro utilizado para devolver al usuario el contenido de una transmision recibida en el socket
 * @return socketReadStatus_t (SUCCESS: La lectura se realizo con exito, FAILURE: Se produjeron errores durante la lectura, NOTHING: Se leyeron 0 bytes)
 */
socketReadStatus_t readFromServerSocket(char * inetReadBuffer);



/**
 * @brief Realiza el accept de una conexion entrante
 * 
 * @return operationStatus_t 
 */
operationStatus_t InetServerAcceptIncomingConnections (void);