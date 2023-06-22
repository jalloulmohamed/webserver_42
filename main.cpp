#include "./Header/server.hpp"
#include "./Header/configFile.hpp"

int main(int argc, char** argv)
{
    if(argc > 2)
        return  1; 
    if(argc == 2)
    {
        configFile parsingfile(argv[1],false);
        parsingfile.parsing();
        if(!parsingfile.validefile())
            return 1;
    }
    // else {
    //     default
    // }
    //vectore for all  file descriptore  file server file server 
    std::vector<pollfd> all_df;
    std::vector<server> all_server;
    std::vector<client> all_client;
    std::vector<int> fd_server;
    std::string req;
    // create number of server
    server Server = server(8000);
    server Server2 = server(8001);
    server Server3 = server(8002);
    server Server4 = server(8003);
    all_server.push_back(Server);
    all_server.push_back(Server2);
    all_server.push_back(Server3);
    all_server.push_back(Server4);

    //staart server and bind and lesten
    for (size_t i = 0; i < all_server.size(); i++)
    {
        if(all_server[i].startServer())
            return 1;
        struct pollfd fds;
        fds.fd= all_server[i].getSockert();
        fds.events = POLLIN;
        all_df.push_back(fds);
        fd_server.push_back(all_server[i].getSockert());
        // i need bind of all port
        if(all_server[i].bindServer())
            return 1;
        if(all_server[i].listenSrver())
            return 1;
    }
    // pooling and accept connection and parsing requist
    signal(SIGPIPE, SIG_IGN);
    while (true)
    {
        int rev =  poll(&all_df[0], all_df.size(), -1);
        if (rev == -1) {
            std::cerr << "Error: Polling failed\n";
            return 1;
        }
        for (size_t i = 0; i < all_df.size(); i++)
        {
            if (all_df[i].revents & POLLIN) {
                std::vector<int>::iterator it = std::find(fd_server.begin(), fd_server.end(), all_df[i].fd); 
                if (it != fd_server.end()) {
                    int client_socket = accept(all_df[i].fd, (sockaddr*) &all_server[std::distance(fd_server.begin(), it)].getClientAdtess(), &all_server[std::distance(fd_server.begin(), it)].getClientAdtessSize());
                    if (client_socket == -1)
                    {
                        std::cerr << "Error: client connection failed\n";
                        close(all_df[i].fd);
                        return 1;
                    }
                    struct pollfd fds;
                    fds.fd=  client_socket;
                    fds.events = POLLIN;
                    all_df.push_back(fds);
                    // client newclient = client(fds.fd);
                    // all_client.push_back(newclient);
                    std::cout<< "server ==> "<<all_df[i].fd<<"   accept connection cleient ==> "<<client_socket<<std::endl;
                }
                else
                {
                    char buff[1024];
                    int content = read(all_df[i].fd,buff,1024);
                    req.append(buff);
                    // std::vector<client>::iterator it = std::find(all_client.begin() , all_client.end(), all_df[i].fd);
                    // if(it != all_client.end())
                    // {
                    //     std::cout<<"find it"<<std::endl;

                    // }
                    if(content != 1024)
                    {
                        std::string response = "HTTP/1.1 200 OK";
                        response+= "Content-Length:" +  std::to_string(req.length()) + "\r\n\r\n";
                        response += req;
                        write(all_df[i].fd,response.c_str(),response.length());
                        response="";
                        close(all_df[i].fd);
                        all_df.erase(all_df.begin() + i);
                    }

                }
            }
        } 
    }
    return 0;
}
