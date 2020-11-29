CXX = g++
CXXFLAGS = `wx-config --cxxflags --libs std`

main:
	$(CXX) main.cpp $(CXXFLAGS) -o $@ $^
