CC = c++
NAME = webserv
FLAG = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp  server.cpp client.cpp configFile.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)  ./Header/server.hpp ./Header/client.hpp ./Header/configFile.hpp
	$(CC) $(OBJ)  -o $(NAME)

%.o : %.cpp 
	$(CC)  $(FLAG) -c $< -o $@ 

clean :
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)

re : fclean all