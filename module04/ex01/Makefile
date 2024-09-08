NAME = animal

SRC_DIR = src/

CPP_FILES = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp

SRC = $(addprefix src/, $(CPP_FILES))

CPP = c++

FLAGS = -Wall -Wextra -Werror

C98 = -std=c++98

BUILD_DIR = build

OBJ = $(patsubst $(SRC_DIR)%, $(BUILD_DIR)/%, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@echo Compiling...
	@if [ ! -d $(BUILD_DIR) ]; then\
		mkdir $(BUILD_DIR);\
	fi
	$(CPP) $(CFLAGS) $(C98) $(OBJ) -o $(NAME)
	@echo Compilation complete.

$(BUILD_DIR)/%.o: src/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CPP) $(CFLAGS) $(C98) -c $< -o $@

clean:
	rm -f $(BUILD_DIR)/*.O $(NAME)
	@rm -rf $(BUILD_DIR)

re: clean all

run: all
	./$(NAME)

val: all
	valgrind ./$(NAME)

.SILENT:

.DEFAULT:
	@echo "Usage: make [all | clean | re | run | val ]"

.PHONY: all clean re
