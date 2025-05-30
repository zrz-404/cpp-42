/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:54:56 by zrz               #+#    #+#             */
/*   Updated: 2025/05/29 16:56:56 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Constructor
Animal::Animal(std::string type) : _type(type) {
    std::cout << "Animal Default Constructor called for type: " << this->_type << std::endl;
}

// Copy Constructor
Animal::Animal(const Animal& other) {
    this->_type = other._type;
    std::cout << "Animal Copy Constructor called for type: " << this->_type << std::endl;
}

// Copy Assignment Operator
Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal Copy Assignment Operator called for type: " << this->_type;
    if (this != &other) { // Protect against self-assignment
        this->_type = other._type;
    }
    std::cout << " (now " << this->_type << ")" << std::endl;
    return *this;
}

// Destructor
Animal::~Animal() {
    std::cout << "Animal Destructor called for type: " << this->_type << std::endl;
}

// Member functions
void Animal::makeSound() const {
    std::cout << "Animal of type " << this->_type << " makes a generic sound!" << std::endl;
}

std::string Animal::getType() const {
    return this->_type;
}
