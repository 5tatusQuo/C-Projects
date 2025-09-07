# Compiler & flags
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -g -Iinclude

# Files
SRC_DIR = src
BIN     = phalanx

# Collect all .c in src/
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:.c=.o)

# Default: build and run
all: $(BIN)
	./$(BIN)

# Link
$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile each .c to .o
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Separate run target (optional)
run: $(BIN)
	./$(BIN)

clean:
	rm -f $(BIN) $(OBJS)