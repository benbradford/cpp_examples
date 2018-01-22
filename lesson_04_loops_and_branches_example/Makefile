name=loops

options = -g -Wall -Wextra -pedantic -std=c++14

include_path=-Iinc/
sources=$(wildcard src/*.cpp)

default: $(name)
	
$(name): $(sources) 
	g++ $(options) $(include_path) -o bin/$@ $^

clean: 
	rm -rf bin && mkdir bin
