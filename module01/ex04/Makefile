NAME = replace

SRC_DIR = src/

SRC = src/main.cpp src/Replace.cpp

CPP = c++

CFLAGS = -Wall -Wextra -Werror

C98 = -std=c++98

# Define the build directory
BUILD_DIR = build

# Create object file paths in the build directory
OBJ = $(patsubst $(SRC_DIR)%, $(BUILD_DIR)/%, $(SRC:.cpp=.o))

all: $(NAME)

# Ensure the build directory exists before linking
$(NAME): $(OBJ)
	@echo Linking...
	@if [ ! -d $(BUILD_DIR) ]; then\
		mkdir $(BUILD_DIR);\
	fi
	$(CPP) $(CFLAGS) $(C98) $(OBJ) -o $(NAME)
	@echo Compilation complete, created the executable

# Ensure object files are placed in the build directory
$(BUILD_DIR)/%.o: src/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CPP) $(CFLAGS) $(C98) -c $< -o $@

clean:
	rm -f $(BUILD_DIR)/*.o $(NAME)
	@rm -rf $(BUILD_DIR)

re: clean all

run: all
	./$(NAME)

val: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.SILENT:

.DEFAULT:
	@echo "Usage: make [all | clean | re]"

.PHONY: all clean re
