CXX = g++
CXXFLAGS = -Wall

# Buscar todos los .cpp en subdirectorios
SRC = $(wildcard Ej*/**.cpp) main.cpp
OBJ = $(SRC:.cpp=.o)
OUT = run

all: $(OUT)

$(OUT): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OUT)

valgrind: $(OUT)
	clear
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(OUT)
	rm $(OUT)