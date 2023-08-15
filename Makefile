# Compiler and flags
CC := g++
CFLAGS := -std=c++11 -g
SFML_LIBS := -lsfml-graphics -lsfml-window -lsfml-system

# Source files and executable name
SRCS := *.cpp
EXECUTABLE := StackAttackRemake
EXEC_PARAMS := -h 5

build: $(EXECUTABLE)

$(EXECUTABLE): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(EXECUTABLE) $(SFML_LIBS)

run: $(EXECUTABLE)
	./$(EXECUTABLE) $(EXEC_PARAMS)

clean:
	rm -f $(EXECUTABLE)
