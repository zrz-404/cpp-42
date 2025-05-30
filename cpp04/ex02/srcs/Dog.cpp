/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:57:32 by zrz               #+#    #+#             */
/*   Updated: 2025/05/30 11:08:23 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp" 

// Constructor
Dog::Dog() : AAnimal("Dog") {                    // Initialize base class with type "Dog"
    std::cout << "Dog Constructor called" << std::endl;
    this->_brain = new Brain();
}

// Copy Constructor
Dog::Dog(const Dog& other) : AAnimal(other) {    // Call AAnimal's copy constructor
    std::cout << "Dog Copy Constructor called" << std::endl;
    this->_brain = new Brain(*(other._brain));
}

// Copy Assignment Operator
Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog Copy Assignment Operator called for Dog type: " << this->_type;
    if (this != &other) {
        AAnimal::operator=(other); // Call AAnimal's assignment operator

        delete this->_brain;
        this->_brain = new Brain(*(other._brain));
    }
    std::cout << " (now Dog type " << this->_type << ")" << std::endl;
    return *this;
}

// Destructor
Dog::~Dog() {
    std::cout << "Dog Destructor called" << std::endl;
    delete this->_brain; // <<<< DELETE brain
    this->_brain = NULL;
}

// Member functions
void Dog::makeSound() const {
    std::cout << this->getType() << " says: Woof Woof!" << std::endl;
}

// brain stuff
void Dog::setIdea(int index, const std::string& idea) {
    if (this->_brain) {
        this->_brain->setIdea(index, idea);
    } else {
        // This should not happen if constructors are correct
        std::cout << "Error: Dog " << this->getType() << " has no brain to set idea." << std::endl;
    }
}

const std::string& Dog::getIdea(int index) const {
    if (this->_brain) {
        return this->_brain->getIdea(index);
    }
    static std::string no_brain_idea = "Error: Dog has no brain or idea index out of bounds.";
    std::cout << "Error: Dog " << this->getType() << " has no brain to get idea." << std::endl;
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
