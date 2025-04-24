# The compiler we want to use
CXX := c++

# Compiler flags
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

# The name of our executable
TARGET := megaphone

# Source file
SOURCES := megaphone.cpp

# Object file, derived from the source file
OBJECTS := $(SOURCES:.cpp=.o)

# Default target: build the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compile each .cpp into .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files but keep executable
clean:
	rm -f $(OBJECTS)

# Clean everything including executable
fclean: clean
	rm -f $(TARGET)

# Rebuild everything
re: fclean all

# Build all
all: $(TARGET)
