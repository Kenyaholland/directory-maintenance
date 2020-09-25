CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJECTS = node.o filemanager.o terminal.o

main: main.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	$(RM) *.o main
