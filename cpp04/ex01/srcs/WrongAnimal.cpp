/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:38:31 by zrz               #+#    #+#             */
/*   Updated: 2025/05/29 16:57:05 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Constructor
WrongAnimal::WrongAnimal(std::string type) : _type(type) {
    std::cout << "WrongAnimal Constructor called for type: " << this->_type << std::endl;
}

// Copy Constructor
WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    this->_type = other._type;
    std::cout << "WrongAnimal Copy Constructor called for type: " << this->_type << std::endl;
}

// Copy Assignment Operator
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "WrongAnimal Copy Assignment Operator called for type: " << this->_type;
    if (this != &other) {
        this->_type = other._type;
    }
    std::cout << " (now " << this->_type << ")" << std::endl;
    return *this;
}

// Destructor
WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal Destructor called for type: " << this->_type << std::endl;
}

// Member functions
void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal of type " << this->_type << " fa un suono generico SBAGLIATO!" << std::endl;
}

std::string WrongAnimal::getType() const {
    return this->_type;
}
