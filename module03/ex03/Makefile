NAME = claptrap

SRC_DIR = src/

SRC = ClapTrap.cpp main.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

CPP = c++

FLAGS = -Wall -Wextra -Werror

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
	@echo "Compilation complete.\n\n"

$(BUILD_DIR)/%.o: %.cpp
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
