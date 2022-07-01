#include "src/fff.h"
#include "src/tcpServer.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


 fff_globals_t fff; ;

typedef struct socket_Fake { unsigned int call_count; unsigned int arg_history_len; unsigned int arg_histories_dropped; int return_val; int return_val_seq_len; int return_val_seq_idx; int * return_val_seq; int return_val_history[(50u)]; int custom_fake_seq_len; int custom_fake_seq_idx; int(*custom_fake)(void); int(**custom_fake_seq)(void); } socket_Fake; extern socket_Fake socket_fake; void socket_reset(void); int socket(void); socket_Fake socket_fake; int socket(void){ if(socket_fake.call_count < (50u)){ } else{ socket_fake.arg_histories_dropped++; } socket_fake.call_count++; if(fff.call_history_idx < (50u)) fff.call_history[fff.call_history_idx++] = (fff_function_t)socket;; if (socket_fake.custom_fake_seq_len){ if (socket_fake.custom_fake_seq_idx < socket_fake.custom_fake_seq_len){ int ret = socket_fake.custom_fake_seq[socket_fake.custom_fake_seq_idx++](); if ((socket_fake.call_count - 1) < (50u)) memcpy((void *)&socket_fake.return_val_history[socket_fake.call_count - 1], (const void *) &ret, sizeof(ret));; return ret; } else{ int ret = socket_fake.custom_fake_seq[socket_fake.custom_fake_seq_len-1](); if ((socket_fake.call_count - 1) < (50u)) memcpy((void *)&socket_fake.return_val_history[socket_fake.call_count - 1], (const void *) &ret, sizeof(ret));; return ret; return socket_fake.custom_fake_seq[socket_fake.custom_fake_seq_len-1](); } } if (socket_fake.custom_fake){ int ret = socket_fake.custom_fake(); if ((socket_fake.call_count - 1) < (50u)) memcpy((void *)&socket_fake.return_val_history[socket_fake.call_count - 1], (const void *) &ret, sizeof(ret));; return ret; return socket_fake.custom_fake(); } if (socket_fake.return_val_seq_len){ if(socket_fake.return_val_seq_idx < socket_fake.return_val_seq_len) { if ((socket_fake.call_count - 1) < (50u)) memcpy((void *)&socket_fake.return_val_history[socket_fake.call_count - 1], (const void *) &socket_fake.return_val_seq[socket_fake.return_val_seq_idx], sizeof(socket_fake.return_val_seq[socket_fake.return_val_seq_idx])); return socket_fake.return_val_seq[socket_fake.return_val_seq_idx++]; } if ((socket_fake.call_count - 1) < (50u)) memcpy((void *)&socket_fake.return_val_history[socket_fake.call_count - 1], (const void *) &socket_fake.return_val_seq[socket_fake.return_val_seq_len-1], sizeof(socket_fake.return_val_seq[socket_fake.return_val_seq_len-1])); return socket_fake.return_val_seq[socket_fake.return_val_seq_len-1]; } if ((socket_fake.call_count - 1) < (50u)) memcpy((void *)&socket_fake.return_val_history[socket_fake.call_count - 1], (const void *) &socket_fake.return_val, sizeof(socket_fake.return_val)); return socket_fake.return_val; } void socket_reset(void){ memset(&socket_fake, 0, sizeof(socket_fake)); socket_fake.arg_history_len = (50u); };

typedef struct accept_Fake { unsigned int call_count; unsigned int arg_history_len; unsigned int arg_histories_dropped; int return_val; int return_val_seq_len; int return_val_seq_idx; int * return_val_seq; int return_val_history[(50u)]; int custom_fake_seq_len; int custom_fake_seq_idx; int(*custom_fake)(void); int(**custom_fake_seq)(void); } accept_Fake; extern accept_Fake accept_fake; void accept_reset(void); int accept(void); accept_Fake accept_fake; int accept(void){ if(accept_fake.call_count < (50u)){ } else{ accept_fake.arg_histories_dropped++; } accept_fake.call_count++; if(fff.call_history_idx < (50u)) fff.call_history[fff.call_history_idx++] = (fff_function_t)accept;; if (accept_fake.custom_fake_seq_len){ if (accept_fake.custom_fake_seq_idx < accept_fake.custom_fake_seq_len){ int ret = accept_fake.custom_fake_seq[accept_fake.custom_fake_seq_idx++](); if ((accept_fake.call_count - 1) < (50u)) memcpy((void *)&accept_fake.return_val_history[accept_fake.call_count - 1], (const void *) &ret, sizeof(ret));; return ret; } else{ int ret = accept_fake.custom_fake_seq[accept_fake.custom_fake_seq_len-1](); if ((accept_fake.call_count - 1) < (50u)) memcpy((void *)&accept_fake.return_val_history[accept_fake.call_count - 1], (const void *) &ret, sizeof(ret));; return ret; return accept_fake.custom_fake_seq[accept_fake.custom_fake_seq_len-1](); } } if (accept_fake.custom_fake){ int ret = accept_fake.custom_fake(); if ((accept_fake.call_count - 1) < (50u)) memcpy((void *)&accept_fake.return_val_history[accept_fake.call_count - 1], (const void *) &ret, sizeof(ret));; return ret; return accept_fake.custom_fake(); } if (accept_fake.return_val_seq_len){ if(accept_fake.return_val_seq_idx < accept_fake.return_val_seq_len) { if ((accept_fake.call_count - 1) < (50u)) memcpy((void *)&accept_fake.return_val_history[accept_fake.call_count - 1], (const void *) &accept_fake.return_val_seq[accept_fake.return_val_seq_idx], sizeof(accept_fake.return_val_seq[accept_fake.return_val_seq_idx])); return accept_fake.return_val_seq[accept_fake.return_val_seq_idx++]; } if ((accept_fake.call_count - 1) < (50u)) memcpy((void *)&accept_fake.return_val_history[accept_fake.call_count - 1], (const void *) &accept_fake.return_val_seq[accept_fake.return_val_seq_len-1], sizeof(accept_fake.return_val_seq[accept_fake.return_val_seq_len-1])); return accept_fake.return_val_seq[accept_fake.return_val_seq_len-1]; } if ((accept_fake.call_count - 1) < (50u)) memcpy((void *)&accept_fake.return_val_history[accept_fake.call_count - 1], (const void *) &accept_fake.return_val, sizeof(accept_fake.return_val)); return accept_fake.return_val; } void accept_reset(void){ memset(&accept_fake, 0, sizeof(accept_fake)); accept_fake.arg_history_len = (50u); };

typedef struct read_Fake { unsigned int call_count; unsigned int arg_history_len; unsigned int arg_histories_dropped; ssize_t return_val; int return_val_seq_len; int return_val_seq_idx; ssize_t * return_val_seq; ssize_t return_val_history[(50u)]; int custom_fake_seq_len; int custom_fake_seq_idx; ssize_t(*custom_fake)(void); ssize_t(**custom_fake_seq)(void); } read_Fake; extern read_Fake read_fake; void read_reset(void); ssize_t read(void); read_Fake read_fake; ssize_t read(void){ if(read_fake.call_count < (50u)){ } else{ read_fake.arg_histories_dropped++; } read_fake.call_count++; if(fff.call_history_idx < (50u)) fff.call_history[fff.call_history_idx++] = (fff_function_t)read;; if (read_fake.custom_fake_seq_len){ if (read_fake.custom_fake_seq_idx < read_fake.custom_fake_seq_len){ ssize_t ret = read_fake.custom_fake_seq[read_fake.custom_fake_seq_idx++](); if ((read_fake.call_count - 1) < (50u)) memcpy((void *)&read_fake.return_val_history[read_fake.call_count - 1], (const void *) &ret, sizeof(ret));; return ret; } else{ ssize_t ret = read_fake.custom_fake_seq[read_fake.custom_fake_seq_len-1](); if ((read_fake.call_count - 1) < (50u)) memcpy((void *)&read_fake.return_val_history[read_fake.call_count - 1], (const void *) &ret, sizeof(ret));; return ret; return read_fake.custom_fake_seq[read_fake.custom_fake_seq_len-1](); } } if (read_fake.custom_fake){ ssize_t ret = read_fake.custom_fake(); if ((read_fake.call_count - 1) < (50u)) memcpy((void *)&read_fake.return_val_history[read_fake.call_count - 1], (const void *) &ret, sizeof(ret));; return ret; return read_fake.custom_fake(); } if (read_fake.return_val_seq_len){ if(read_fake.return_val_seq_idx < read_fake.return_val_seq_len) { if ((read_fake.call_count - 1) < (50u)) memcpy((void *)&read_fake.return_val_history[read_fake.call_count - 1], (const void *) &read_fake.return_val_seq[read_fake.return_val_seq_idx], sizeof(read_fake.return_val_seq[read_fake.return_val_seq_idx])); return read_fake.return_val_seq[read_fake.return_val_seq_idx++]; } if ((read_fake.call_count - 1) < (50u)) memcpy((void *)&read_fake.return_val_history[read_fake.call_count - 1], (const void *) &read_fake.return_val_seq[read_fake.return_val_seq_len-1], sizeof(read_fake.return_val_seq[read_fake.return_val_seq_len-1])); return read_fake.return_val_seq[read_fake.return_val_seq_len-1]; } if ((read_fake.call_count - 1) < (50u)) memcpy((void *)&read_fake.return_val_history[read_fake.call_count - 1], (const void *) &read_fake.return_val, sizeof(read_fake.return_val)); return read_fake.return_val; } void read_reset(void){ memset(&read_fake, 0, sizeof(read_fake)); read_fake.arg_history_len = (50u); };

typedef struct inet_pton_Fake { unsigned int call_count; unsigned int arg_history_len; unsigned int arg_histories_dropped; int return_val; int return_val_seq_len; int return_val_seq_idx; int * return_val_seq; int return_val_history[(50u)]; int custom_fake_seq_len; int custom_fake_seq_idx; int(*custom_fake)(void); int(**custom_fake_seq)(void); } inet_pton_Fake; extern inet_pton_Fake inet_pton_fake; void inet_pton_reset(void); int inet_pton(void); inet_pton_Fake inet_pton_fake; int inet_pton(void){ if(inet_pton_fake.call_count < (50u)){ } else{ inet_pton_fake.arg_histories_dropped++; } inet_pton_fake.call_count++; if(fff.call_history_idx < (50u)) fff.call_history[fff.call_history_idx++] = (fff_function_t)inet_pton;; if (inet_pton_fake.custom_fake_seq_len){ if (inet_pton_fake.custom_fake_seq_idx < inet_pton_fake.custom_fake_seq_len){ int ret = inet_pton_fake.custom_fake_seq[inet_pton_fake.custom_fake_seq_idx++](); if ((inet_pton_fake.call_count - 1) < (50u)) memcpy((void *)&inet_pton_fake.return_val_history[inet_pton_fake.call_count - 1], (const void *) &ret, sizeof(ret));; return ret; } else{ int ret = inet_pton_fake.custom_fake_seq[inet_pton_fake.custom_fake_seq_len-1](); if ((inet_pton_fake.call_count - 1) < (50u)) memcpy((void *)&inet_pton_fake.return_val_history[inet_pton_fake.call_count - 1], (const void *) &ret, sizeof(ret));; return ret; return inet_pton_fake.custom_fake_seq[inet_pton_fake.custom_fake_seq_len-1](); } } if (inet_pton_fake.custom_fake){ int ret = inet_pton_fake.custom_fake(); if ((inet_pton_fake.call_count - 1) < (50u)) memcpy((void *)&inet_pton_fake.return_val_history[inet_pton_fake.call_count - 1], (const void *) &ret, sizeof(ret));; return ret; return inet_pton_fake.custom_fake(); } if (inet_pton_fake.return_val_seq_len){ if(inet_pton_fake.return_val_seq_idx < inet_pton_fake.return_val_seq_len) { if ((inet_pton_fake.call_count - 1) < (50u)) memcpy((void *)&inet_pton_fake.return_val_history[inet_pton_fake.call_count - 1], (const void *) &inet_pton_fake.return_val_seq[inet_pton_fake.return_val_seq_idx], sizeof(inet_pton_fake.return_val_seq[inet_pton_fake.return_val_seq_idx])); return inet_pton_fake.return_val_seq[inet_pton_fake.return_val_seq_idx++]; } if ((inet_pton_fake.call_count - 1) < (50u)) memcpy((void *)&inet_pton_fake.return_val_history[inet_pton_fake.call_count - 1], (const void *) &inet_pton_fake.return_val_seq[inet_pton_fake.return_val_seq_len-1], sizeof(inet_pton_fake.return_val_seq[inet_pton_fake.return_val_seq_len-1])); return inet_pton_fake.return_val_seq[inet_pton_fake.return_val_seq_len-1]; } if ((inet_pton_fake.call_count - 1) < (50u)) memcpy((void *)&inet_pton_fake.return_val_history[inet_pton_fake.call_count - 1], (const void *) &inet_pton_fake.return_val, sizeof(inet_pton_fake.return_val)); return inet_pton_fake.return_val; } void inet_pton_reset(void){ memset(&inet_pton_fake, 0, sizeof(inet_pton_fake)); inet_pton_fake.arg_history_len = (50u); };

typedef struct bind_Fake { unsigned int call_count; unsigned int arg_history_len; unsigned int arg_histories_dropped; int return_val; int return_val_seq_len; int return_val_seq_idx; int * return_val_seq; int return_val_history[(50u)]; int custom_fake_seq_len; int custom_fake_seq_idx; int(*custom_fake)(void); int(**custom_fake_seq)(void); } bind_Fake; extern bind_Fake bind_fake; void bind_reset(void); int bind(void); bind_Fake bind_fake; int bind(void){ if(bind_fake.call_count < (50u)){ } else{ bind_fake.arg_histories_dropped++; } bind_fake.call_count++; if(fff.call_history_idx < (50u)) fff.call_history[fff.call_history_idx++] = (fff_function_t)bind;; if (bind_fake.custom_fake_seq_len){ if (bind_fake.custom_fake_seq_idx < bind_fake.custom_fake_seq_len){ int ret = bind_fake.custom_fake_seq[bind_fake.custom_fake_seq_idx++](); if ((bind_fake.call_count - 1) < (50u)) memcpy((void *)&bind_fake.return_val_history[bind_fake.call_count - 1], (const void *) &ret, sizeof(ret));; return ret; } else{ int ret = bind_fake.custom_fake_seq[bind_fake.custom_fake_seq_len-1](); if ((bind_fake.call_count - 1) < (50u)) memcpy((void *)&bind_fake.return_val_history[bind_fake.call_count - 1], (const void *) &ret, sizeof(ret));; return ret; return bind_fake.custom_fake_seq[bind_fake.custom_fake_seq_len-1](); } } if (bind_fake.custom_fake){ int ret = bind_fake.custom_fake(); if ((bind_fake.call_count - 1) < (50u)) memcpy((void *)&bind_fake.return_val_history[bind_fake.call_count - 1], (const void *) &ret, sizeof(ret));; return ret; return bind_fake.custom_fake(); } if (bind_fake.return_val_seq_len){ if(bind_fake.return_val_seq_idx < bind_fake.return_val_seq_len) { if ((bind_fake.call_count - 1) < (50u)) memcpy((void *)&bind_fake.return_val_history[bind_fake.call_count - 1], (const void *) &bind_fake.return_val_seq[bind_fake.return_val_seq_idx], sizeof(bind_fake.return_val_seq[bind_fake.return_val_seq_idx])); return bind_fake.return_val_seq[bind_fake.return_val_seq_idx++]; } if ((bind_fake.call_count - 1) < (50u)) memcpy((void *)&bind_fake.return_val_history[bind_fake.call_count - 1], (const void *) &bind_fake.return_val_seq[bind_fake.return_val_seq_len-1], sizeof(bind_fake.return_val_seq[bind_fake.return_val_seq_len-1])); return bind_fake.return_val_seq[bind_fake.return_val_seq_len-1]; } if ((bind_fake.call_count - 1) < (50u)) memcpy((void *)&bind_fake.return_val_history[bind_fake.call_count - 1], (const void *) &bind_fake.return_val, sizeof(bind_fake.return_val)); return bind_fake.return_val; } void bind_reset(void){ memset(&bind_fake, 0, sizeof(bind_fake)); bind_fake.arg_history_len = (50u); };

typedef struct listen_Fake { unsigned int call_count; unsigned int arg_history_len; unsigned int arg_histories_dropped; int return_val; int return_val_seq_len; int return_val_seq_idx; int * return_val_seq; int return_val_history[(50u)]; int custom_fake_seq_len; int custom_fake_seq_idx; int(*custom_fake)(void); int(**custom_fake_seq)(void); } listen_Fake; extern listen_Fake listen_fake; void listen_reset(void); int listen(void); listen_Fake listen_fake; int listen(void){ if(listen_fake.call_count < (50u)){ } else{ listen_fake.arg_histories_dropped++; } listen_fake.call_count++; if(fff.call_history_idx < (50u)) fff.call_history[fff.call_history_idx++] = (fff_function_t)listen;; if (listen_fake.custom_fake_seq_len){ if (listen_fake.custom_fake_seq_idx < listen_fake.custom_fake_seq_len){ int ret = listen_fake.custom_fake_seq[listen_fake.custom_fake_seq_idx++](); if ((listen_fake.call_count - 1) < (50u)) memcpy((void *)&listen_fake.return_val_history[listen_fake.call_count - 1], (const void *) &ret, sizeof(ret));; return ret; } else{ int ret = listen_fake.custom_fake_seq[listen_fake.custom_fake_seq_len-1](); if ((listen_fake.call_count - 1) < (50u)) memcpy((void *)&listen_fake.return_val_history[listen_fake.call_count - 1], (const void *) &ret, sizeof(ret));; return ret; return listen_fake.custom_fake_seq[listen_fake.custom_fake_seq_len-1](); } } if (listen_fake.custom_fake){ int ret = listen_fake.custom_fake(); if ((listen_fake.call_count - 1) < (50u)) memcpy((void *)&listen_fake.return_val_history[listen_fake.call_count - 1], (const void *) &ret, sizeof(ret));; return ret; return listen_fake.custom_fake(); } if (listen_fake.return_val_seq_len){ if(listen_fake.return_val_seq_idx < listen_fake.return_val_seq_len) { if ((listen_fake.call_count - 1) < (50u)) memcpy((void *)&listen_fake.return_val_history[listen_fake.call_count - 1], (const void *) &listen_fake.return_val_seq[listen_fake.return_val_seq_idx], sizeof(listen_fake.return_val_seq[listen_fake.return_val_seq_idx])); return listen_fake.return_val_seq[listen_fake.return_val_seq_idx++]; } if ((listen_fake.call_count - 1) < (50u)) memcpy((void *)&listen_fake.return_val_history[listen_fake.call_count - 1], (const void *) &listen_fake.return_val_seq[listen_fake.return_val_seq_len-1], sizeof(listen_fake.return_val_seq[listen_fake.return_val_seq_len-1])); return listen_fake.return_val_seq[listen_fake.return_val_seq_len-1]; } if ((listen_fake.call_count - 1) < (50u)) memcpy((void *)&listen_fake.return_val_history[listen_fake.call_count - 1], (const void *) &listen_fake.return_val, sizeof(listen_fake.return_val)); return listen_fake.return_val; } void listen_reset(void){ memset(&listen_fake, 0, sizeof(listen_fake)); listen_fake.arg_history_len = (50u); };

typedef struct close_Fake { unsigned int call_count; unsigned int arg_history_len; unsigned int arg_histories_dropped; int return_val; int return_val_seq_len; int return_val_seq_idx; int * return_val_seq; int return_val_history[(50u)]; int custom_fake_seq_len; int custom_fake_seq_idx; int(*custom_fake)(void); int(**custom_fake_seq)(void); } close_Fake; extern close_Fake close_fake; void close_reset(void); int close(void); close_Fake close_fake; int close(void){ if(close_fake.call_count < (50u)){ } else{ close_fake.arg_histories_dropped++; } close_fake.call_count++; if(fff.call_history_idx < (50u)) fff.call_history[fff.call_history_idx++] = (fff_function_t)close;; if (close_fake.custom_fake_seq_len){ if (close_fake.custom_fake_seq_idx < close_fake.custom_fake_seq_len){ int ret = close_fake.custom_fake_seq[close_fake.custom_fake_seq_idx++](); if ((close_fake.call_count - 1) < (50u)) memcpy((void *)&close_fake.return_val_history[close_fake.call_count - 1], (const void *) &ret, sizeof(ret));; return ret; } else{ int ret = close_fake.custom_fake_seq[close_fake.custom_fake_seq_len-1](); if ((close_fake.call_count - 1) < (50u)) memcpy((void *)&close_fake.return_val_history[close_fake.call_count - 1], (const void *) &ret, sizeof(ret));; return ret; return close_fake.custom_fake_seq[close_fake.custom_fake_seq_len-1](); } } if (close_fake.custom_fake){ int ret = close_fake.custom_fake(); if ((close_fake.call_count - 1) < (50u)) memcpy((void *)&close_fake.return_val_history[close_fake.call_count - 1], (const void *) &ret, sizeof(ret));; return ret; return close_fake.custom_fake(); } if (close_fake.return_val_seq_len){ if(close_fake.return_val_seq_idx < close_fake.return_val_seq_len) { if ((close_fake.call_count - 1) < (50u)) memcpy((void *)&close_fake.return_val_history[close_fake.call_count - 1], (const void *) &close_fake.return_val_seq[close_fake.return_val_seq_idx], sizeof(close_fake.return_val_seq[close_fake.return_val_seq_idx])); return close_fake.return_val_seq[close_fake.return_val_seq_idx++]; } if ((close_fake.call_count - 1) < (50u)) memcpy((void *)&close_fake.return_val_history[close_fake.call_count - 1], (const void *) &close_fake.return_val_seq[close_fake.return_val_seq_len-1], sizeof(close_fake.return_val_seq[close_fake.return_val_seq_len-1])); return close_fake.return_val_seq[close_fake.return_val_seq_len-1]; } if ((close_fake.call_count - 1) < (50u)) memcpy((void *)&close_fake.return_val_history[close_fake.call_count - 1], (const void *) &close_fake.return_val, sizeof(close_fake.return_val)); return close_fake.return_val; } void close_reset(void){ memset(&close_fake, 0, sizeof(close_fake)); close_fake.arg_history_len = (50u); };



void setUp(void) {



}



void tearDown(void) {



}











void test_CreateSocket_ReturnsSuccessIfOk (void) {



    inetSocket_t testSocket = 0;



    socket_fake.return_val = 1;



    UnityAssertEqualNumber((UNITY_INT)((createSocket(&testSocket))), (UNITY_INT)((SUCCESS)), (

   ((void *)0)

   ), (UNITY_UINT)(32), UNITY_DISPLAY_STYLE_INT);

}















void test_CreateSocket_ReturnsFailureIfNotOk (void) {



    inetSocket_t testSocket = 0;



    socket_fake.return_val = -1;



    UnityAssertEqualNumber((UNITY_INT)((createSocket(&testSocket))), (UNITY_INT)((FAILURE)), (

   ((void *)0)

   ), (UNITY_UINT)(47), UNITY_DISPLAY_STYLE_INT);

}















void test_InetServerAcceptIncomingConnections_ReturnsSuccessIfAcceptedConnection (void) {



    accept_fake.return_val = 1;



    UnityAssertEqualNumber((UNITY_INT)((InetServerAcceptIncomingConnections())), (UNITY_INT)((SUCCESS)), (

   ((void *)0)

   ), (UNITY_UINT)(60), UNITY_DISPLAY_STYLE_INT);

}















void test_InetServerAcceptIncomingConnections_ReturnsFailureIfFailedConnection (void) {



    accept_fake.return_val = -1;



    UnityAssertEqualNumber((UNITY_INT)((InetServerAcceptIncomingConnections())), (UNITY_INT)((FAILURE)), (

   ((void *)0)

   ), (UNITY_UINT)(73), UNITY_DISPLAY_STYLE_INT);

}















void test_ReadFromServerSocket_ReturnsFailureIfErrorOnSocketRead() {



    char inputBuffer [50];



    read_fake.return_val = (ssize_t) -1;



    UnityAssertEqualNumber((UNITY_INT)((readFromServerSocket(inputBuffer))), (UNITY_INT)((SR_FAILURE)), (

   ((void *)0)

   ), (UNITY_UINT)(88), UNITY_DISPLAY_STYLE_INT);

}















void test_ReadFromServerSocket_ReturnsNothingIfNoDataReceived() {



    char inputBuffer [50];



    read_fake.return_val = (ssize_t) 0;



    UnityAssertEqualNumber((UNITY_INT)((readFromServerSocket(inputBuffer))), (UNITY_INT)((SR_NOTHING)), (

   ((void *)0)

   ), (UNITY_UINT)(103), UNITY_DISPLAY_STYLE_INT);

}















void test_ReadFromServerSocket_ReturnsSucceesIfDataWasReceived() {



    char inputBuffer [50];



    read_fake.return_val = (ssize_t) 100;



    UnityAssertEqualNumber((UNITY_INT)((readFromServerSocket(inputBuffer))), (UNITY_INT)((SR_SUCCESS)), (

   ((void *)0)

   ), (UNITY_UINT)(118), UNITY_DISPLAY_STYLE_INT);

}















void test_ConfigureServerSocket_ReturnsFailureIfPtonIsIncorrect() {



    inetSocket_t socket = 1;



    inet_pton_fake.return_val = 0;



    UnityAssertEqualNumber((UNITY_INT)((configureServerSocket(socket))), (UNITY_INT)((FAILURE)), (

   ((void *)0)

   ), (UNITY_UINT)(133), UNITY_DISPLAY_STYLE_INT);

}















void test_ConfigureServerSocket_ReturnsSuccessIfAllConditionsAreCorrect() {



    inetSocket_t socket = 1;



    inet_pton_fake.return_val = 1;



    bind_fake.return_val = 1;



    listen_fake.return_val = 0;



    UnityAssertEqualNumber((UNITY_INT)((configureServerSocket(socket))), (UNITY_INT)((SUCCESS)), (

   ((void *)0)

   ), (UNITY_UINT)(152), UNITY_DISPLAY_STYLE_INT);

}















void test_ConfigureServerSocket_ReturnsFailureIfBindIsIncorrect() {



    inetSocket_t socket = 1;



    inet_pton_fake.return_val = 1;



    bind_fake.return_val = -1;



    close_fake.return_val = 0;



    UnityAssertEqualNumber((UNITY_INT)((configureServerSocket(socket))), (UNITY_INT)((FAILURE)), (

   ((void *)0)

   ), (UNITY_UINT)(171), UNITY_DISPLAY_STYLE_INT);

}















void test_ConfigureServerSocket_ReturnsFailureIfListenIsIncorrect() {



    inetSocket_t socket = 1;



    inet_pton_fake.return_val = 1;



    bind_fake.return_val = 1;



    listen_fake.return_val = -1;



    UnityAssertEqualNumber((UNITY_INT)((configureServerSocket(socket))), (UNITY_INT)((FAILURE)), (

   ((void *)0)

   ), (UNITY_UINT)(190), UNITY_DISPLAY_STYLE_INT);

}
