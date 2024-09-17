CXX = g++

CXXFLAGS = -Wall -g

EXEC = main

OBJS = main.o io.o sort_compare.o


all: $(EXEC)

# Link object files to create the executable
$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC)

# Compile main.cpp to main.o

	$(CXX) $(CXXFLAGS) -c main.cpp

# Compile reading.cpp to reading.o

	$(CXX) $(CXXFLAGS) -c io.cpp

# Compile sort_compare.cpp to sort_compare.o

	$(CXX) $(CXXFLAGS) -c sort_compare.cpp

	./$(EXEC)
	rm -f $(OBJS) $(EXEC)
