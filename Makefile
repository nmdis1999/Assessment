CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -pedantic

SRC = uri_parser.cpp main.cpp
TEST_SRC = uri_parser.cpp test.cpp

BIN = uri
TEST_BIN = test

all: $(BIN)

$(BIN): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

test: $(TEST_SRC)
	$(CXX) $(CXXFLAGS) -o $(TEST_BIN) $^
	./$(TEST_BIN)

clean:
	rm -f $(BIN) $(TEST_BIN)
