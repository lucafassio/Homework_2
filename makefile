CXX = g++
CXXFLAGS = -Wall -std=c++17

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
