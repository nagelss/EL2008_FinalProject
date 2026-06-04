# Compiler and Flags
CC = gcc
# -I./include tells the compiler where to find the .h files
CFLAGS = -Wall -Wextra -I./include

# Name of the final executable
TARGET = inventory
 
# This prevents the compiler from touching the Windows or Mock files.
SRCS = src/main.c \
       src/app_logic.c \
       src/user_interface.c \
       src/serial_comm_macos.c

# Automatically convert .c filenames to .o (object) filenames
OBJS = $(SRCS:.c=.o)

# Default target when we just type 'make'
all: $(TARGET)

# Linking stage: Combines all .o files into the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
	@echo "========================================"
	@echo "Build successful! Run with: ./$(TARGET)"
	@echo "========================================"

# Compilation stage, which Compiles each .c file into a .o file
src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up rule to remove generated files
clean:
	rm -f src/*.o $(TARGET)
	@echo "Cleaned up all compiled object files and executable."