SRC = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
CC = c++
NAME = brain
CFLAGS = -Wall -Wextra -Werror -std=c++98
HEADER = HumanA.hpp HumanB.hpp Weapon.hpp

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