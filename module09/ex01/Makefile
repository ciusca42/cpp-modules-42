NAME = RPN

SRC = main.cpp RPN.cpp

CPP = c++

CFLAGS = -Wall -Wextra -Werror -g

C98 = -std=c++98

all: $(NAME)
$(NAME): $(SRC)
	@echo Compiling...
	$(CPP) $(CFLAGS) $(C98) $(SRC) -o $(NAME)
	@echo "==========================="
	@echo "|| Compilation complete. ||"
	@echo "==========================="

clean:
	rm -f $(NAME)

re: clean all

run: all
	@./$(NAME) "8 4 * 9 - 9 - 9 - 4 - 1 +"

val: all
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "8 4 * 9 - 9 - 9 - 4 - 1 +"

.SILENT:

.DEFAULT:
	@echo "Usage: make [ all | clean | re | run | val ]"

.PHONY: all clean re run val
