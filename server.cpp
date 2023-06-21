#include "./Header/server.hpp"

server::server(int port)
{
    this->server_address.sin_family = AF_INET;
    this->server_address.sin_addr.s_addr = INADDR_ANY;
    this->server_address.sin_port = htons(port);
    this->client_address_size =  sizeof(this->client_address);
}

server::~server()
{

}

int server::startServer()
{
    this->m_socket = socket(AF_INET, SOCK_STREAM, 0);
    if ( this->m_socket == -1) {
        std::cerr << "Error creating socket" << std::endl;
        return 1;
    }
    fcntl(this->m_socket, F_SETFL, O_NONBLOCK);
    return 0;
}

void server::closeServer()
{
    close(this->m_socket);
    exit(0);
}

int server::getSockert() const
{
    return this->m_socket;

}

void server::setSockert(const int socket) 
{ 
    this->m_socket = socket;

} 

sockaddr_in &server::getClientAdtess() const
{ 
    return const_cast<sockaddr_in&>(this->client_address);
}

socklen_t &server::getClientAdtessSize() const
{ 
    return const_cast<socklen_t&>(this->client_address_size);
}


int server::bindServer()
{
    int reuse = 1;
    if (setsockopt(this->m_socket, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) == -1) {
        std::cout << "Failed to set socket option" << std::endl;
        return 1;
    }
    if (bind(this->m_socket, (sockaddr*) &this->server_address, sizeof(this->server_address)) == -1) {
        std::cerr << "Error: socket binding failed\n";
        close(m_socket);
        return 1;
    }
    return 0;
}

int server::listenSrver()
{
    if(listen(m_socket,100) == -1)
    {
        std::cerr << "Error: socket listening failed\n";
        close(m_socket);
        return 1;
    }
    return 0;
}

