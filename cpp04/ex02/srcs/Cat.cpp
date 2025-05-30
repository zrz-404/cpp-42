/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:57:30 by zrz               #+#    #+#             */
/*   Updated: 2025/05/30 11:10:35 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp" 

// Constructor
Cat::Cat() : AAnimal("Cat") {                    // Initialize base class with type "Cat"
	std::cout << "Cat Constructor called" << std::endl;
    this->_brain = new Brain();
}

// Copy Constructor
Cat::Cat(const Cat& other) : AAnimal(other) {    // Call AAnimal's copy constructor
	std::cout << "Cat Copy Constructor called" << std::endl;
    this->_brain = new Brain(*(other._brain));
}

// Copy Assignment Operator
Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat Copy Assignment Operator called";
	if (this != &other) {
		AAnimal::operator=(other);               // AAnimal's assignment operator

        delete this->_brain;
        this->_brain = new Brain(*(other._brain));
	}
	std::cout << " (Cat is now type " << this->_type << ")" << std::endl;
	return *this;
}

// Destructor
Cat::~Cat() {
	std::cout << "Cat Destructor called" << std::endl;
    delete this->_brain; // <<<< DELETE brain
    this->_brain = NULL;
}

// Member functions
void Cat::makeSound() const {
	std::cout << this->getType() << " says: Meooooow!" << std::endl;
}



// Brain stuff
// brain stuff
void Cat::setIdea(int index, const std::string& idea) {
    if (this->_brain) {
        this->_brain->setIdea(index, idea);
    } else {
        // This should not happen if constructors are correct
        std::cout << "Error: Cat " << this->getType() << " has no brain to set idea." << std::endl;
    }
}

const std::string& Cat::getIdea(int index) const {
    if (this->_brain) {
        return this->_brain->getIdea(index);
    }
    static std::string no_brain_idea = "Error: Cat has no brain or idea index out of bounds.";
    std::cout << "Error: Cat " << this->getType() << " has no brain to get idea." << std::endl;
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
