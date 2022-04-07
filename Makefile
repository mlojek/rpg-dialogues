CC = g++
CFLAGS =
GTESTFLAGS = -lgtest -lgtest_main -pthread


test:
	$(CC) $(GTESTFLAGS) tests/* src/* -o runTests
	./runTests