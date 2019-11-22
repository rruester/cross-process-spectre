INCLUDE=../../inc/
SENDER_INCLUDE=../../inc/sender/
SOURCE=../
CFLAGS=-std=c++11 -I$(INCLUDE) -I$(SENDER_INCLUDE)
CC=g++

TARGETS=sender
BIN=../../bin/
UTILS=util.o 

all: $(TARGETS)

$(UTILS): %.o: $(SOURCE)%.cpp $(INCLUDE)%.hpp
	$(CC) $(CFLAGS) -c $< 

%.o: %.cpp $(INCLUDE)util.hpp $(SENDER_INCLUDE)%.hpp
	$(CC) $(CFLAGS)  -c $< 

$(TARGETS): %:%.o util.o
	$(CC) $(CFLAGS) $^ -o $(BIN)$@

run:
	./$(BIN)$(TARGETS)

.PHONY:	clean

clean:
	rm *.o $(HELPERS) $(BIN)$(TARGETS)
