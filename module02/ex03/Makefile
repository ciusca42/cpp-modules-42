NAME = fixed

SRC = main.cpp Fixed.cpp Point.cpp bsp.cpp

CPP = c++

FLAGS = -Wall -Wextra -Werror

C98 = -std=c++98

all: $(NAME)
	@echo Compiling...
	$(CPP) $(FLAGS) $(C98) $(SRC) -o $(NAME)
	@echo Compilation complete.

clean:
	rm -f $(NAME)

re: clean all


run: all
	./$(NAME)

val: all
	valgrind ./$(NAME)

.SILENT:

.DEFAULT:
	@echo "Usage: make [all | clean | re]"

.PHONY: all clean re
