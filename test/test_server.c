#include "unity.h"
#include "tcpServer.h"
#include "fff.h"

DEFINE_FFF_GLOBALS; 
FAKE_VALUE_FUNC(int, socket);
FAKE_VALUE_FUNC(int, accept);
FAKE_VALUE_FUNC(ssize_t, read);
FAKE_VALUE_FUNC(int, inet_pton);
FAKE_VALUE_FUNC(int, bind);
FAKE_VALUE_FUNC(int, listen);
FAKE_VALUE_FUNC(int, close);

void setUp(void) {

}

void tearDown(void) {

}

/**
 * @brief Se verifica que la funcion retorne SUCCESS en caso que se pueda crear un socket TCP en el sistema.
 * 
 */
void test_CreateSocket_ReturnsSuccessIfOk (void) {
    //seteo un valor para el parametro de salida testSocket.
    inetSocket_t testSocket = 0;
    //configro el mock de la funcion socket() de la libreria <sys/socket.h>. Se utiliza una valor >=0 que simula un socket descriptor valido.
    socket_fake.return_val = 1;
    //se verifica que la funcion retorne SUCCESS
    TEST_ASSERT_EQUAL(createSocket(&testSocket), SUCCESS);
}



/**
 * @brief Se verifica que la funcion retorne FAILURE en caso que no se pueda crear un socket TCP en el sistema.
 * 
 */
void test_CreateSocket_ReturnsFailureIfNotOk (void) {
    //seteo un valor para el parametro de salida testSocket.
    inetSocket_t testSocket = 0;
    //configro el mock de la funcion socket() de la libreria <sys/socket.h>. Se utiliza el valor -1 que simula un error en la creacion del socket.  
    socket_fake.return_val = -1;
    //se verifica que la funcion retorne FAILURE
    TEST_ASSERT_EQUAL(createSocket(&testSocket), FAILURE);
}



/**
 * @brief Se verifica que la funcion retorne SUCCESS en caso que se pueda aceptar una conexion en el socket TCP.
 * 
 */
void test_InetServerAcceptIncomingConnections_ReturnsSuccessIfAcceptedConnection (void) {
    //configro el mock de la funcion accept() de la libreria <sys/socket.h>. Se utiliza el valor 1 que simula la correcta creacion de un socket descriptor.
    accept_fake.return_val = 1;
    //se verifica que la funcion retorne SUCCESS
    TEST_ASSERT_EQUAL(InetServerAcceptIncomingConnections(), SUCCESS);   
}



/**
 * @brief Se verifica que la funcion retorne FAILURE en caso que no se pueda aceptar una conexion en el socket TCP.
 * 
 */
void test_InetServerAcceptIncomingConnections_ReturnsFailureIfFailedConnection (void) {
    //configro el mock de la funcion accept() de la libreria <sys/socket.h>. Se utiliza el valor -1 que simula un error en la creacion del socket.
    accept_fake.return_val = -1;
    //se verifica que la funcion retorne FAILURE
    TEST_ASSERT_EQUAL(InetServerAcceptIncomingConnections(), FAILURE);   
}



/**
 * @brief Se verifica que la funcion retorne SR_FAILURE en caso que se obtenga un error al intentar leer del socket usando la funcion read
 * 
 */
void test_ReadFromServerSocket_ReturnsFailureIfErrorOnSocketRead() {
    //creo un buffer como parametro de salida de la funcion
    char inputBuffer [50];
    //configuro el mock de la funcion para retornar el valor -1 que simula un error en la lectura desde el socket
    read_fake.return_val = (ssize_t) -1;
    //se verifica que la funcion retorne SR_FAILURE
    TEST_ASSERT_EQUAL(readFromServerSocket(inputBuffer), SR_FAILURE);
}



/**
 * @brief Se verifica que la funcion retorne SR_NOTHING en caso que la funcion read no reciba datos
 * 
 */
void test_ReadFromServerSocket_ReturnsNothingIfNoDataReceived() {
    //creo un buffer como parametro de salida de la funcion
    char inputBuffer [50];
    //configuro el mock de la funcion para retornar el valor 0 que simula ausencia de datos en la lectura desde el socket
    read_fake.return_val = (ssize_t) 0;
    //se verifica que la funcion retorne SR_NOTHING
    TEST_ASSERT_EQUAL(readFromServerSocket(inputBuffer), SR_NOTHING);
}



/**
 * @brief Se verifica que la funcion retorne SR_SUCCESS en caso que la funcion read devuelva datos.
 * 
 */
void test_ReadFromServerSocket_ReturnsSucceesIfDataWasReceived() {
    //creo un buffer como parametro de salida de la funcion
    char inputBuffer [50];
    //configuro el mock de la funcion para retornar el valor 100 que simula presencia de datos en la lectura desde el socket
    read_fake.return_val = (ssize_t) 100;
    //se verifica que la funcion retorne SR_SUCCESS 
    TEST_ASSERT_EQUAL(readFromServerSocket(inputBuffer), SR_SUCCESS);
}



/**
 * @brief Se verifica que la funcion retorne FAILURE en caso que PTON falle
 * 
 */
void test_ConfigureServerSocket_ReturnsFailureIfPtonIsIncorrect() {
    //creo un socket como parametro de entrada de la funcion
    inetSocket_t socket = 1;
    //configuro el mock de la funcion para retornar el valor 0 que simula un valor invalido de la funcion
    inet_pton_fake.return_val = 0;
    //se verifica que la funcion retorne SUCCESS  
    TEST_ASSERT_EQUAL(configureServerSocket(socket), FAILURE);
}



/**
 * @brief Se verifica que la funcion retorne SUCCESS en caso que todas las funciones de configuracion sean exitosas
 * 
 */
void test_ConfigureServerSocket_ReturnsSuccessIfAllConditionsAreCorrect() {
    //creo un socket como parametro de entrada de la funcion
    inetSocket_t socket = 1;
    //configuro el mock de la funcion para retornar el valor 1 que simula un valor valido de la funcion
    inet_pton_fake.return_val = 1;
    //configuro el mock de la funcion para retornar el valor 1 que simula un valor valido de la funcion
    bind_fake.return_val = 1;
    //configuro el mock de la funcion para retornar el valor 0 que simula un valor valido de la funcion
    listen_fake.return_val = 0;
    //se verifica que la funcion retorne SUCCESS  
    TEST_ASSERT_EQUAL(configureServerSocket(socket), SUCCESS);  
}



/**
 * @brief Se verifica que la funcion retorne FAILURE en caso que la funcion bind() falle
 * 
 */
void test_ConfigureServerSocket_ReturnsFailureIfBindIsIncorrect() {
    //creo un socket como parametro de entrada de la funcion
    inetSocket_t socket = 1;
    //configuro el mock de la funcion para retornar el valor 1 que simula un valor valido de la funcion
    inet_pton_fake.return_val = 1;
    //configuro el mock de la funcion para retornar el valor -1 que simula un valor invalido de la funcion
    bind_fake.return_val = -1;
    //configuro el mock de la funcion para retornar el valor 0 que simula un valor valido de la funcion
    close_fake.return_val = 0;
    //se verifica que la funcion retorne SUCCESS  
    TEST_ASSERT_EQUAL(configureServerSocket(socket), FAILURE);  
}



/**
 * @brief Se verifica que la funcion retorne FAILURE en caso que la funcion listen() falle
 * 
 */
void test_ConfigureServerSocket_ReturnsFailureIfListenIsIncorrect() {
    //creo un socket como parametro de entrada de la funcion
    inetSocket_t socket = 1;
    //configuro el mock de la funcion para retornar el valor 1 que simula un valor valido de la funcion
    inet_pton_fake.return_val = 1;
    //configuro el mock de la funcion para retornar el valor 1 que simula un valor valido de la funcion
    bind_fake.return_val = 1;
    //configuro el mock de la funcion para retornar el valor -1 que simula un valor invalido de la funcion
    listen_fake.return_val = -1;
    //se verifica que la funcion retorne SUCCESS  
    TEST_ASSERT_EQUAL(configureServerSocket(socket), FAILURE);  
}