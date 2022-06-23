CC = g++
CFLAGS = -std=c++17
GTESTFLAGS = -lgtest -lgtest_main -pthread


all:
	$(CC) $(CFLAGS) $(GTESTFLAGS) runTests.cpp ../src/* -o runTests
test: all
	./runTests