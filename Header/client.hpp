#ifndef CLIENT
#define CLIENT
#include <sys/socket.h> 
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <vector>
#include <fcntl.h>


class client
{
    private:
        std::string req;
        int fd;
    public:
        client();
        client(int fd);
        int getfd() const ;
        void setfd(int const fd);
        std::string getreq() const;
        void appendreq(char const  *req); 
        ~client();
};


#endif
