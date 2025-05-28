/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:56:19 by zrz               #+#    #+#             */
/*   Updated: 2025/05/28 14:21:55 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath> // For roundf

Fixed::Fixed(void) : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    this->_fixedPointValue = other._fixedPointValue; // Direct copy
}

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_fixedPointValue = other._fixedPointValue; // Direct copy
    }
    return *this;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

// --- New Constructors for Ex01 ---
Fixed::Fixed(const int intValue) {
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = intValue << _fractionalBits;
}

Fixed::Fixed(const float floatValue) {
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = roundf(floatValue * (1 << _fractionalBits));
}

// --- Member functions from Ex00 ---
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl; // As per Ex00
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}

// --- New member functions for Ex01 ---
float Fixed::toFloat(void) const {
    return static_cast<float>(this->_fixedPointValue) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return this->_fixedPointValue >> _fractionalBits;
}

// --- operator << overload ---
std::ostream &operator<<(std::ostream &outStream, const Fixed &fixedValue) {
    outStream << fixedValue.toFloat();
    return outStream;
}
