BIN_PATH=bin/
TARGET=pstr_demo

.PHONY: all clean

all: $(BIN_PATH)main.o $(BIN_PATH)pstr.o
	$(CC) $(BIN_PATH)main.o $(BIN_PATH)pstr.o -o $(BIN_PATH)$(TARGET)
	
$(BIN_PATH)main.o: main.c pstr.h
	$(CC) -c main.c -o $(BIN_PATH)main.o
	
$(BIN_PATH)pstr.o: pstr.c pstr.h
	$(CC) -c pstr.c -o $(BIN_PATH)pstr.o
	
clean:
	$(RM) $(BIN_PATH)*.o
	$(RM) $(BIN_PATH)$(TARGET)
