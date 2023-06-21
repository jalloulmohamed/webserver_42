#include "./Header/server.hpp"
#include "./Header/configFile.hpp"

int main(int argc, char** argv)
{
    if(argc != 2)
        return  1; 
    configFile parsingfile(argv[1],false);
    parsingfile.parsing();
    if(!parsingfile.validefile())
        return 1;
    // (void) argv;
    // //vectore for all  file descriptore 
    // std::vector<pollfd> all_df;
    // //vectore for all  file server 
    // std::vector<server> all_server;
    //  //vectore for all  file cleient 
    // std::vector<client> all_client;
    // std::vector<int> fd_server;

    // // create number of server
    // server Server = server(8000);
    // server Server2 = server(8001);
    // server Server3 = server(8002);
    // server Server4 = server(8003);
    // all_server.push_back(Server);
    // all_server.push_back(Server2);
    // all_server.push_back(Server3);
    // all_server.push_back(Server4);

    // //staart server and bind and lesten
    // for (size_t i = 0; i < all_server.size(); i++)
    // {
    //     if(all_server[i].startServer())
    //         return 1;
    //     struct pollfd fds;
    //     fds.fd= all_server[i].getSockert();
    //     fds.events = POLLIN;
    //     all_df.push_back(fds);
    //     fd_server.push_back(all_server[i].getSockert());
    //     // i need bind of all port
    //     if(all_server[i].bindServer())
    //         return 1;
    //     if(all_server[i].listenSrver())
    //         return 1;
    // }
    // // pooling and accept connection and parsing requist
    // signal(SIGPIPE, SIG_IGN);
    // while (true)
    // {
    //     std::cout << "waiting for events ....\n";
    //     int rev =  poll(&all_df[0], all_df.size(), -1);
    //     if (rev == -1) {
    //         std::cerr << "Error: Polling failed\n";
    //         return 1;
    //     }
    //     for (size_t i = 0; i < all_df.size(); i++)
    //     {
    //         if (all_df[i].revents & POLLIN) {
    //             std::vector<int>::iterator it = std::find(fd_server.begin(), fd_server.end(), all_df[i].fd); 
    //             if (it != fd_server.end()) {
    //                 int client_socket = accept(all_df[i].fd, (sockaddr*) &all_server[std::distance(fd_server.begin(), it)].getClientAdtess(), &all_server[std::distance(fd_server.begin(), it)].getClientAdtessSize());
    //                 if (client_socket == -1)
    //                 {
    //                     std::cerr << "Error: client connection failed\n";
    //                     close(all_df[i].fd);
    //                     return 1;
    //                 }
    //                 struct pollfd fds;
    //                 fds.fd=  client_socket;
    //                 fds.events = POLLIN;
    //                 all_df.push_back(fds);
    //                 client c = client(client_socket);
    //                 all_client.push_back(c);
    //                 std::cout<< "server ==> "<<all_df[i].fd<<"   accept connection cleient ==> "<<client_socket<<std::endl;
                   
    //             }
    //             else
    //             {
    //                 std::cout<< "read"<< std::endl;
    //             }
    //         }
    //         else if(all_df[i].revents & POLLOUT)
    //         {
    //             std::cout<< "send"<< std::endl;
    //         }
    //     } 
    // }
    return 0;    
}
