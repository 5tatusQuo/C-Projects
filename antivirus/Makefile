# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Target executable name
TARGET = phalanx

# Default rule: build and run the program
all: $(TARGET)
	./$(TARGET)

# Rule to build the program
$(TARGET): phalanx.o
	$(CC) $(CFLAGS) -o $(TARGET) phalanx.o

# Rule to build the object file
phalanx.o: phalanx.c phalanx.h
	$(CC) $(CFLAGS) -c phalanx.c

# Clean up compiled files
clean:
	rm -f $(TARGET) *.o