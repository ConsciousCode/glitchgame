CXX = g++
FLAGS = -std=c++11 -DDEBUG
LIBS = -lsfml-graphics -lsfml-system -lsfml-window
INC = -Iinclude/

obj/main.o: src/main.cpp
	$(CXX) $(FLAGS) $(INC) -c $^ -o $@
obj/%.o: include/%.hpp src/%.cpp
	$(CXX) $(FLAGS) $(INC) -c $(filter %.cpp, $^) -o $@

bin/game: $(patsubst src/%.cpp, obj/%.o, $(wildcard src/*.cpp))
	$(CXX) $(FLAGS) $^ -o $@ $(LIBS)

game: bin/game
clean:
	rm obj/* bin/*

.PHONY: game clean
