/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:56:19 by zrz               #+#    #+#             */
/*   Updated: 2025/05/28 14:27:21 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath> // For roundf

Fixed::Fixed(void) : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    this->_fixedPointValue = other._fixedPointValue;
}

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_fixedPointValue = other._fixedPointValue;
    }
    return *this;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int intValue) {
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = intValue << _fractionalBits;
}

Fixed::Fixed(const float floatValue) {
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = roundf(floatValue * (1 << _fractionalBits));
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(this->_fixedPointValue) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return this->_fixedPointValue >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &outStream, const Fixed &fixedValue) {
    outStream << fixedValue.toFloat();
    return outStream;
}

// --- Comparison Operators ---
bool Fixed::operator>(const Fixed &other) const {
    return this->_fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(const Fixed &other) const {
    return this->_fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &other) const {
    return this->_fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->_fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(const Fixed &other) const {
    return this->_fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &other) const {
    return this->_fixedPointValue != other._fixedPointValue;
}

// --- Arithmetic Operators ---
Fixed Fixed::operator+(const Fixed &other) const {
    Fixed result;
    result.setRawBits(this->_fixedPointValue + other._fixedPointValue);
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed result;
    result.setRawBits(this->_fixedPointValue - other._fixedPointValue);
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
    Fixed result;
    long long temp_val = static_cast<long long>(this->_fixedPointValue) * other._fixedPointValue;
    result.setRawBits(static_cast<int>(temp_val >> _fractionalBits));
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
    Fixed result;
    if (other._fixedPointValue == 0) {
        std::cerr << "Error: Division by zero." << std::endl;
        exit(1);
    }
    long long temp_val = static_cast<long long>(this->_fixedPointValue) << _fractionalBits;
    result.setRawBits(static_cast<int>(temp_val / other._fixedPointValue));
    return result;
}

// --- Increment/Decrement Operators ---
Fixed& Fixed::operator++(void) { // Pre-increment
    this->_fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int) { // Post-increment
    Fixed temp(*this);
    this->_fixedPointValue++;
    return temp;       // Returns the state before incrementing
}

Fixed& Fixed::operator--(void) { // Pre-decrement
    this->_fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int) { // Post-decrement
    Fixed temp(*this);
    this->_fixedPointValue--;
    return temp;       // Returns the state before decrementing
}

// --- Ex02: Static min/max functions ---
Fixed& Fixed::min(Fixed &a, Fixed &b) {
    return (a._fixedPointValue < b._fixedPointValue) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
    return (a._fixedPointValue < b._fixedPointValue) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
    return (a._fixedPointValue > b._fixedPointValue) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
    return (a._fixedPointValue > b._fixedPointValue) ? a : b;
}
