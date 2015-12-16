TARGET=smith_waterman
CXX=clang++
CXXFLAGS=--std=c++11 -Wall
.PHONY: all clean
all: smith_waterman
smith_waterman: main.cc ezOptionParser.h smith_waterman.h
	$(CXX) $(CXXFLAGS) -o $(TARGET) $<
clean:
	-@ rm -v $(TARGET)
