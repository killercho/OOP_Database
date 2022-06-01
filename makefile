# Variables:
CXX := g++
CXXFLAGS := -o

SRC := src
BIN := bin
MAIN := main

# Filters all the cpp files to be compiled in the compile section.
MAIN_FILES = $(filter-out $(SRC)/$(TEST).cpp, $(wildcard $(SRC)/*.cpp))

# Invokes the 'compile' function and runs the programme.
run: compile
	@echo "Running $(MAIN)..."
	@echo
	@clear
	@./$(MAIN)

# Compiles the files using the given compiler and flags.
compile:
	@echo "Compiling files in $(SRC)..."
	$(CXX) $(MAIN_FILES) $(CXXFLAGS) $(MAIN)

# Runs the 'clean' command even if there is a file named clean.
.PHONY: clean
clean:
	@echo "Removing $(BIN)..."
	rm -rf $(BIN)
