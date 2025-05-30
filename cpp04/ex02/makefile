# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/26 16:02:51 by jroseiro          #+#    #+#              #
#    Updated: 2025/05/30 11:16:21 by jroseiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# The compiler we want to use
CXX := c++

# Compiler flags
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

# The name of our executable
TARGET := ex02

# Source directories
SRCS_DIR := srcs
INC_DIR := inc

# Source files - main.cpp in SRCS_DIR, class implementations in SRCS_DIR
SOURCES :=	$(SRCS_DIR)/main.cpp 		\
			$(SRCS_DIR)/AAnimal.cpp 		\
			$(SRCS_DIR)/Brain.cpp		\
			$(SRCS_DIR)/Cat.cpp			\
			$(SRCS_DIR)/Dog.cpp			\
			#$(SRCS_DIR)/WrongAnimal.cpp \
			$(SRCS_DIR)/WrongCat.cpp	


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
