#variables
CC = gcc
CFLAGS = -Wall -Wextra -I./src

#name for file
TARGET = peek

#list of all .c files
SRCS = src/utils/peek.c src/core/errors.c

#objects from c files
OBJS = $(SRCS:.c=.o)

#main rule
all: $(TARGET)

#rules for make
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

#rule for compiler
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#remove trash
clean:
	rm -f $(OBJS) $(TARGET)

