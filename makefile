CXX = g++
CXXFLAGS = -Wall -O1 -larmadillo
OBJS = PageRank.o main.o
EXEC = pr

$(EXEC): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(EXEC)

PageRank.o: PageRank.h PageRank.cpp
main.o: main.cpp

clean:
	rm $(EXEC) $(OBJS)
