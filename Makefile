CC = gcc

CFLAGS = -Wall

# Name of the output executable
OUTPUT = a

SRC_FILE = Lista01_03-2.c

all: $(OUTPUT)

$(OUTPUT): $(SRC_FILE)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(SRC_FILE)

clean:
	rm -f $(OUTPUT) $(SRC_FILE:.c=.o)

run:
	./$(OUTPUT)

debug: CFLAGS += -g
debug: $(SRC_FILE)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(SRC_FILE)
	gdb ./$(OUTPUT)

.PHONY: all clean run debugm