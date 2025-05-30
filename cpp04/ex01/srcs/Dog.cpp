/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:57:32 by zrz               #+#    #+#             */
/*   Updated: 2025/05/29 16:56:46 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructor
Dog::Dog() : Animal("Dog") {                    // Initialize base class with type "Dog"
    std::cout << "Dog Constructor called" << std::endl;
}

// Copy Constructor
Dog::Dog(const Dog& other) : Animal(other) {    // Call Animal's copy constructor
    std::cout << "Dog Copy Constructor called" << std::endl;
}

// Copy Assignment Operator
Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog Copy Assignment Operator called";
    if (this != &other) {
        Animal::operator=(other);               // Animal's assignment operator
    }
    std::cout << " (Dog is now type " << this->_type << ")" << std::endl;
    return *this;
}

// Destructor
Dog::~Dog() {
    std::cout << "Dog Destructor called" << std::endl;
}

// Member functions
void Dog::makeSound() const {
    std::cout << this->getType() << " says: Woof Woof!" << std::endl;
}

// brain stuff
void Dog::setIdea(int index, const std::string& idea) {
    if (this->_brain) {
        this->_brain->setIdea(index, idea);
    }
}

const std::string& Dog::getIdea(int index) const {
    if (this->_brain) {
        return this->_brain->getIdea(index);
    }
    static std::string no_brain_idea = "Error: Dog has no brain.";
    return no_brain_idea;
}

void Dog::printBrainIdeas() const {
    if (this->_brain) {
        std::cout << "Dog (" << this->getType() << ") ";
        this->_brain->printIdeas();
    } else {
        std::cout << "Dog (" << this->getType() << ") has no brain to print ideas from." << std::endl;
    }
}
