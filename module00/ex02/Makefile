NAME = account

SRC = Account.cpp tests.cpp

CPP = c++

CFLAGS = -Wall -Wextra -Werror

C98 = -std=c++98

all: $(NAME)
	@echo Compiling...
	$(CPP) $(CFLAGS) $(C98) $(SRC) -o $(NAME)
	@echo Compilation complete.

clean:
	rm -f $(NAME)

re: clean all

run: all
	./$(NAME)

log: all
	./$(NAME) > output.log

.SILENT:

.DEFAULT:
	@echo "Usage: make [all | clean | re]"

.PHONY: all clean re
