# Makefile for Lab 4 - Link-State Routing Algorithm

CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2
TARGET = mylinkstate
SRC = mylinkstate.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET) *.o