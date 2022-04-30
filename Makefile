CC = g++
CFLAGS =
GTESTFLAGS = -lgtest -lgtest_main -pthread


test:
	$(CC) $(GTESTFLAGS) tests/runTests.cpp src/* -o runTests
	./runTests