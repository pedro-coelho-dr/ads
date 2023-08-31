# Specify the compiler
CC = gcc

# Specify compiler flags
CFLAGS = -Wall

# Name of the output executable
OUTPUT = OUT

# Specify the default source file (change as needed)
SRC_FILE = Aula_04.c

# Default target: build the specified executable
all: $(OUTPUT)

# Compile and build the executable
$(OUTPUT): $(SRC_FILE)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(SRC_FILE)

# Clean up compiled files and the executable
clean:
	rm -f $(OUTPUT) $(SRC_FILE:.c=.o)

# Run the specific .c file
run:
	./$(OUTPUT)

# Compile and run the specific .c file with debugging flags
debug: CFLAGS += -g
debug: $(SRC_FILE)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(SRC_FILE)
	gdb ./$(OUTPUT)

.PHONY: all clean run debugm