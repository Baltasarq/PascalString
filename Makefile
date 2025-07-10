BIN_PATH=bin/
TARGET=pstr_demo
CFLAGS = -O2

ifeq ($(OS),Windows_NT)
	MD=mkdir
else
	MD=mkdir -p
endif

.PHONY: all clean

all: $(BIN_PATH)main.o $(BIN_PATH)pstr.o
	$(MD) bin
	$(CC) $(CFLAGS) $(BIN_PATH)main.o $(BIN_PATH)pstr.o -o $(BIN_PATH)$(TARGET)
	
$(BIN_PATH)main.o: main.c pstr.h
	$(CC) $(CFLAGS) -c main.c -o $(BIN_PATH)main.o
	
$(BIN_PATH)pstr.o: pstr.c pstr.h
	$(CC) $(CFLAGS) -c pstr.c -o $(BIN_PATH)pstr.o
	
clean:
	$(MD) bin
	$(RM) $(BIN_PATH)*.o
	$(RM) $(BIN_PATH)$(TARGET)
