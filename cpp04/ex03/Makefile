SRC = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp
CC = c++
NAME = main
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g3
HEADER =  AMateria.hpp Character.hpp Cure.hpp Ice.hpp ICharacter.hpp IMateriaSource.hpp MateriaSource.hpp
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
