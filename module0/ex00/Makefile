NAME = megaphone

SRC = megaphone.cpp

CPP = c++

FLAGS = -Wall -Wextra -Werror

C98 = -std=c++98

all: $(NAME)
	@echo "Compiling $(NAME)"
	$(CPP) $(FLAGS) $(C98) $(SRC) -o $(NAME)
	@echo "Done"

clean:
	rm -f $(NAME)

re: fclean all

.SILENT:

.DEFAULT:
	@echo "Usage: make [all | clean | fclean]"

.PHONY: all clean fclean .default re

