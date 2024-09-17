CXX = g++
CXXFLAGS = -Wall -g

EXEC = main
OBJS = main.o io.o sort_compare.o

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(EXEC)

run: $(EXEC)
	./$(EXEC)


