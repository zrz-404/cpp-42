/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:57:32 by zrz               #+#    #+#             */
/*   Updated: 2025/05/29 11:00:15 by zrz              ###   ########.fr       */
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