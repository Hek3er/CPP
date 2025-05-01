SRC = main.cpp BitcoinExchange.cpp 
CC = c++
NAME = btc
CFLAGS = -Wall -Werror -Wextra -std=c++11
HEADER =  BitcoinExchange.hpp 
OSRC = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OSRC)
	@echo "compiling.. "
	@$(CC) $(CFLAGS) $(OSRC) -o $(NAME)

%.o : %.cpp $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Removing Object files.."
	@rm -rf $(OSRC)

fclean: clean
	@echo "Removing Exec"
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean
