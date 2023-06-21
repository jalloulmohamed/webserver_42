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

void client::appendreq(char const *req)
{
    std::string baff(req);

    this->req.append(req,baff.length());
}