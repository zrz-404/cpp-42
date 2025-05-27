# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/26 16:02:51 by jroseiro          #+#    #+#              #
#    Updated: 2025/05/27 15:13:51 by zrz              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# The compiler we want to use
CXX := c++

# Compiler flags
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -g # Added -g for debugging

# The name of our executable
TARGET := ex01

# Source directories
SRCS_DIR := srcs
INC_DIR := inc

# Source files - main.cpp in SRCS_DIR, class implementations in SRCS_DIR
SOURCES := $(SRCS_DIR)/main.cpp $(SRCS_DIR)/Zombie.cpp $(SRCS_DIR)/zombieHorde.cpp

# Object files
OBJ_DIR := obj
OBJECTS := $(patsubst $(SRCS_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))

# Include directory flag
CPPFLAGS := -I$(INC_DIR)

# Default target: build the executable
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $(TARGET) $(OBJECTS)

# Create object directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compile each .cpp into .o
$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -rf $(OBJ_DIR)

# Clean everything including executable
fclean: clean
	rm -f $(TARGET)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re