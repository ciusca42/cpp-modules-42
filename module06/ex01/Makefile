NAME = serialize

SRC = main.cpp Serialize.cpp Data.cpp 

CPP = c++

CFLAGS = -Wall -Wextra -Werror

C98 = -std=c++98 -g

all: $(NAME)
$(NAME): $(SRC)
	@echo Compiling...
	$(CPP) $(CFLAGS) $(C98) $(SRC) -o $(NAME)
	@echo Compilation complete.

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
