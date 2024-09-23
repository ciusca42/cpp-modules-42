NAME = scalar

SRC = main.cpp Converter.cpp

CPP = c++

FLAGS = -Wall -Wextra -Werror -g

C98 = 

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
	rm -f $(BUILD_DIR)/*.O $(NAME)
	@rm -rf $(BUILD_DIR)

re: clean all

ARG=

run: all
	./$(NAME) $(ARG)

val: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(ARG)

.SILENT:

.DEFAULT:
	@echo "Usage: make [all | clean | re | run | val ]"

.PHONY: all clean re
