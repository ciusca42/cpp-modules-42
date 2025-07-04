NAME = iter

SRC = main.cpp

CPP = c++

FLAGS = -Wall -Wextra -Werror -g

C98 = -std=c++98

BUILD_DIR = build

OBJ = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@echo Compiling...
	@if [ ! -d $(BUILD_DIR) ]; then\
		mkdir $(BUILD_DIR);\
	fi
	$(CPP) $(CFLAGS) $(C98) $(OBJ) -o $(NAME)
	@echo Compilation complete.
	@echo "\n=========================\n"

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(BUILD_DIR)
	$(CPP) $(CFLAGS) $(C98) -c $< -o $@

clean:
	rm -f $(BUILD_DIR)/*.O
	@rm -rf $(BUILD_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

ARG=

run: all
	./$(NAME) $(ARG)

val: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(ARG)

.SILENT:

.DEFAULT:
	@echo "Usage: make [all | clean | re | run | val | fclean]"

.PHONY: all clean re fclean