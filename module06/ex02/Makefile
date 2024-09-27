NAME = identify

SRC = main.cpp src/A.cpp src/B.cpp src/C.cpp src/Base.cpp

CPP = c++

CFLAGS = -Wall -Wextra -Werror -g

C98 = -std=c++98

all: $(NAME)
$(NAME): $(SRC)
	@echo Compiling...
	$(CPP) $(CFLAGS) $(C98) $(SRC) -o $(NAME)
	@echo Compilation complete.
	@echo "======================\n"

clean:
	rm -f $(NAME)

re: clean all

run: all
	@./$(NAME)

val: all
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.SILENT:

.DEFAULT:
	@echo "Usage: make [ all | clean | re | run | val ]"

.PHONY: all clean re run val
