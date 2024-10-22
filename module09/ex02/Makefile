NAME = PmergeMe

SRC = main.cpp src/PmergeMe.cpp src/sortDeque.cpp src/sortVector.cpp

CPP = c++

CFLAGS = -Wall -Wextra -Werror -g

C98 = -std=c++98

all: $(NAME)

$(NAME): $(SRC)
	@echo Compiling...
	$(CPP) $(CFLAGS) $(C98) -D DEBUG=$(DBG) $(SRC) -o $(NAME)
	@echo Compilation complete.

clean:
	rm -f $(NAME)

re: clean all

run: all
	@./$(NAME)

val: all
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

# Use the debug target to override the DEBUG variable
debug: 
	$(MAKE) DEBUG=1

.SILENT:

.DEFAULT:
	@echo "Usage: make [ all | clean | re | run | val | debug ]"

.PHONY: all clean re run val debug
