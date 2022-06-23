CC = g++
CFLAGS = -std=c++17
GTESTFLAGS = -lgtest -lgtest_main -pthread


test:
	$(CC) $(CFLAGS) $(GTESTFLAGS) runTests.cpp ../src/* -o runTests
	./runTests