/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:57:30 by zrz               #+#    #+#             */
/*   Updated: 2025/05/30 10:35:17 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructor
Cat::Cat() : AAnimal("Cat") {                    // Initialize base class with type "Cat"
	std::cout << "Cat Constructor called" << std::endl;
}

// Copy Constructor
Cat::Cat(const Cat& other) : AAnimal(other) {    // Call AAnimal's copy constructor
	std::cout << "Cat Copy Constructor called" << std::endl;
}

// Copy Assignment Operator
Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat Copy Assignment Operator called";
	if (this != &other) {
		AAnimal::operator=(other);               // AAnimal's assignment operator
	}
	std::cout << " (Cat is now type " << this->_type << ")" << std::endl;
	return *this;
}

// Destructor
Cat::~Cat() {
	std::cout << "Cat Destructor called" << std::endl;
}

// Member functions
void Cat::makeSound() const {
	std::cout << this->getType() << " says: Meooooow!" << std::endl;
}



// Brain stuff
void Cat::setIdea(int index, const std::string& idea) {
    if (this->_brain) {
        this->_brain->setIdea(index, idea);
    }
}

const std::string& Cat::getIdea(int index) const {
    if (this->_brain) {
        return this->_brain->getIdea(index);
    }
    static std::string no_brain_idea = "Error: Cat has no brain.";
    return no_brain_idea;
}

void Cat::printBrainIdeas() const {
    if (this->_brain) {
        std::cout << "Cat (" << this->getType() << ") ";
        this->_brain->printIdeas();
    } else {
        std::cout << "Cat (" << this->getType() << ") has no brain to print ideas from." << std::endl;
    }
}
