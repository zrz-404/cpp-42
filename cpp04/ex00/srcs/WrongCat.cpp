/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:38:21 by zrz               #+#    #+#             */
/*   Updated: 2025/05/29 13:06:22 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

//  Constructor
WrongCat::WrongCat() : WrongAnimal("WrongCat") {
    std::cout << "WrongCat Constructor called" << std::endl;
}

//  Copy Constructor
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "WrongCat Copy Constructor called" << std::endl;
}

//  Copy Assignment Operator
WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << "WrongCat Copy Assignment Operator called";
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    std::cout << " (WrongCat is now type " << this->_type << ")" << std::endl;
    return *this;
}

//  Destructor
WrongCat::~WrongCat() {
    std::cout << "WrongCat Destructor called" << std::endl;
}

//  Member functions
/*  This sound will be called if the object is a WrongCat and makeSound is called on it directly.
    However, if called via a WrongAnimal pointer, WrongAnimal's makeSound will be called. */
void WrongCat::makeSound() const {
    std::cout << this->getType() << " dice: Miaaaauuuuu! 🤌 🍕 🍝 🇮🇹 (Ma questo potreste non sentirlo...)" << std::endl;
}