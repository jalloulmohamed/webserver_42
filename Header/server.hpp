#ifndef SERVER
#define SERVER
#include <sys/socket.h> 
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <vector>
#include <signal.h>
#include <fcntl.h>
#include <poll.h>
#include "client.hpp"

class server
{
    private:
        int m_socket;
        sockaddr_in server_address;
        sockaddr_in client_address;
        socklen_t client_address_size;

    public:
        server(int port);
        ~server();
        int  startServer();
        void closeServer();
        int bindServer();
        int listenSrver();
        int acceptServer();

        int getSockert() const ;
        void setSockert( const int socket);

        sockaddr_in  &getClientAdtess() const ;
        socklen_t  &getClientAdtessSize() const ;

};


#endif
