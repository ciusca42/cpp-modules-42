NAME = phonebook

SRCS = main.cpp PhoneBook.cpp Contact.cpp

SRC = $(addprefix src/, $(SRCS))

CPP = c++

FLAGS = -Wall -Wextra -Werror

C98 = -std=c++98

all: $(NAME)

$(NAME): $(SRC)
	@echo Compiling...
	$(CPP) $(FLAGS) $(C98) $(SRC) -o $(NAME)
	@echo Compilation complete.

clean:
	rm -f $(NAME)

re: clean all

run: all
	./$(NAME)

.SILENT:

.DEFAULT:
	@echo "Usage: make [all | clean | re]"

.PHONY: all clean re run
