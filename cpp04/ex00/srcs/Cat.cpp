/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:57:30 by zrz               #+#    #+#             */
/*   Updated: 2025/05/29 16:24:13 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructor
Cat::Cat() : Animal("Cat") {                    // Initialize base class with type "Cat"
	std::cout << "Cat Constructor called" << std::endl;
}

// Copy Constructor
Cat::Cat(const Cat& other) : Animal(other) {    // Call Animal's copy constructor
	std::cout << "Cat Copy Constructor called" << std::endl;
}

// Copy Assignment Operator
Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat Copy Assignment Operator called";
	if (this != &other) {
		Animal::operator=(other);               // Animal's assignment operator
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
