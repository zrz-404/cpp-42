/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:31:46 by zrz               #+#    #+#             */
/*   Updated: 2025/05/29 16:34:14 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
    for (int i = 0; i < 100; ++i) {
    }
    std::cout << "Brain Constructor called." << std::endl;
}

Brain::Brain(const Brain& other) {
    std::cout << "Brain Copy Constructor called." << std::endl;
    for (int i = 0; i < 100; ++i) {
        this->ideas[i] = other.ideas[i]; // Copying each string
    }
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "Brain Copy Assignment Operator called." << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; ++i) {
            this->ideas[i] = other.ideas[i]; // Copying each string
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain Destructor called." << std::endl;
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100) {
        this->ideas[index] = idea;
    } else {
        std::cout << "Error: Idea index " << index << " is out of bounds." << std::endl;
    }
}

const std::string& Brain::getIdea(int index) const {
    if (index >= 0 && index < 100) {
        return this->ideas[index];
    }
    static std::string empty_idea = "Error: Idea index out of bounds or no idea set.";
    std::cout << "Error: Idea index " << index << " is out of bounds (in getIdea)." << std::endl;
    return empty_idea;
}

void Brain::printIdeas() const {
    std::cout << "Brain ideas: " << std::endl;
    for (int i = 0; i < 5; ++i) { // Print first 5 ideas for brevity in tests
        if (!ideas[i].empty()) {
             std::cout << "  Idea " << i << ": " << ideas[i] << std::endl;
        } else {
             std::cout << "  Idea " << i << ": (empty)" << std::endl;
        }
    }
    if (ideas[0].empty() && ideas[1].empty() && ideas[2].empty() && ideas[3].empty() && ideas[4].empty()) {
        std::cout << "  (No ideas set in the first 5 slots or they are empty strings)" << std::endl;
    }
}