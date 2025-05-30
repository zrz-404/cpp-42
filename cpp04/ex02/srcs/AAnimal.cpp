/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:54:56 by zrz               #+#    #+#             */
/*   Updated: 2025/05/30 10:25:03 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

// Constructor
AAnimal::AAnimal(std::string type) : _type(type) {
    std::cout << "Animal Default Constructor called for type: " << this->_type << std::endl;
}

// Copy Constructor
AAnimal::AAnimal(const AAnimal& other) {
    this->_type = other._type;
    std::cout << "Animal Copy Constructor called for type: " << this->_type << std::endl;
}

// Copy Assignment Operator
AAnimal& AAnimal::operator=(const AAnimal& other) {
    std::cout << "Animal Copy Assignment Operator called for type: " << this->_type;
    if (this != &other) { // Protect against self-assignment
        this->_type = other._type;
    }
    std::cout << " (now " << this->_type << ")" << std::endl;
    return *this;
}

// Destructor
AAnimal::~AAnimal() {
    std::cout << "Animal Destructor called for type: " << this->_type << std::endl;
}

// Member functions

// THIS FUNCTION IS NOW PURELY VIRTUAL!!! 
// void AAnimal::makeSound() const {
//     std::cout << "Animal of type " << this->_type << " makes a generic sound!" << std::endl;
// }

std::string AAnimal::getType() const {
    return this->_type;
}
