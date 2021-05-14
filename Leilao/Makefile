CXXFLAGS = -std=c++17
BIN=main
FILE= src/*.cpp tests/*.cpp
FILE_ALL= src/*.cpp tests/*.cpp tests/catch/*.cpp
FLAGS_CATCH = -r compact -s

all:
	@clear
	@g++ tests/catch/main-test.cpp -c
	@mv main-test.o tests/catch/
	@g++ tests/catch/main-test.o $(FILE) -o $(BIN) $(CXXFLAGS)
	@./$(BIN)

run:
	@clear
	@g++ tests/catch/main-test.o $(FILE) -o $(BIN) $(CXXFLAGS)
	@./$(BIN)

clean:
	@rm -f $(BIN)