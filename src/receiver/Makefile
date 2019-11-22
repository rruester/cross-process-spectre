INCLUDE=../../inc/
RECEIVER_INCLUDE=../../inc/receiver/
SOURCE=../
CFLAGS=-std=c++11 -I$(INCLUDE) -I$(RECEIVER_INCLUDE)
CC=g++

TARGETS=receiver
BIN=../../bin/
UTILS=util.o 

all: $(TARGETS)

$(UTILS): %.o: $(SOURCE)%.cpp $(INCLUDE)%.hpp
	$(CC) $(CFLAGS) -c $< 

%.o: %.cpp $(INCLUDE)util.hpp $(RECEIVER_INCLUDE)%.hpp
	$(CC) $(CFLAGS)  -c $< 

$(TARGETS): %:%.o util.o
	$(CC) $(CFLAGS) $^ -o $(BIN)$@

run:
	./$(BIN)$(TARGETS)

.PHONY:	clean

clean:
	rm *.o $(HELPERS) $(BIN)$(TARGETS)
