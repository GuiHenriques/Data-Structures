CC = gcc

SOURCES = main.c add.c mult.c

OBJS = $(SOURCES:.c=.o)

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

%.o: %.c functions.h
	$(CC) -c $<

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	@./$(TARGET)