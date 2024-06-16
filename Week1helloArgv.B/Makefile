# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c99

# Executable name
TARGET = helloArgv

# Source files
SRCS = helloArgv.c

# Object files
OBJS = $(SRCS:.c=.o)

# Phony targets
.PHONY: all clean help

# Default target
all: $(TARGET)

# Build the target executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OBJS) $(TARGET)

# Help message
help:
	@echo "Usage:"
	@echo "  make        - Build the project"
	@echo "  make clean  - Remove build artifacts"
	@echo "  make help   - Show this help message"
