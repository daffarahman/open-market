CXX = g++
CXXFLAGS = `wx-config --cxxflags --libs std`
INPUT = main.cpp
OUTPUT = market

main:
	$(CXX) $(INPUT) $(CXXFLAGS) -o $(OUTPUT)
