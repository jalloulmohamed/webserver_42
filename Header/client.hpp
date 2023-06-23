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
        long long contentlenght;
        long long contentread;
        bool firstbuff;
    public:
        client();
        client(int fd);
        int getfd() const ;
        void setfd(int const fd);
        std::string getreq() const;
        void appendreq(char const  *req,int count); 
        void setcontentlenght(long long const contentlenght);
        long long getcontentlenght() const;
        void setfirstbuff(const bool firstbuffer);
        bool getfirstbuff() const;
        void addTocontentread(long long const contentread);
        long long getcontentread() const;
        ~client();
};


#endif
