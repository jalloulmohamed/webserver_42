#include "./Header/client.hpp"


client::client()
{

}
client::~client()
{

}

client::client(int fd)
{
    this->req = "";
    this->fd =fd;
    this->contentlenght=0;
    this->contentread = 0;
    this->firstbuff = false;

}

int client::getfd() const
{
    return this->fd;
}

void client::setfd(int const fd)
{
    this->fd = fd;
}

std::string client::getreq() const
{
    return this->req;
}

void client::appendreq(char const *req, int count)
{
    

    this->req.append(req,count);
}

void client::setcontentlenght(long long const contentlenght)
{
    this->contentlenght = contentlenght;

}
long long client::getcontentlenght() const
{
    return this->contentlenght;
}
void client::setfirstbuff(const bool firstbuffer)
{
    this->firstbuff = firstbuff;

}
bool client::getfirstbuff() const
{
    return this->firstbuff;
}

void client::addTocontentread(long long const contentread)
{
    this->contentread += contentread;

}
long long client::getcontentread() const
{
    return this->contentread;
}