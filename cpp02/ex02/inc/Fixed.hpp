/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:56:28 by zrz               #+#    #+#             */
/*   Updated: 2025/05/28 14:25:07 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream> // For std::ostream

class Fixed {
    private:
        int                 _fixedPointValue;
        static const int    _fractionalBits = 8;

    public:
        // Orthodox Canonical Form (OCF)
        Fixed(void);
        Fixed(const Fixed &other);
        Fixed &operator=(const Fixed &other);
        ~Fixed(void);

        Fixed(const int intValue);
        Fixed(const float floatValue);

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;

        // Ex02: Comparison Operators
        bool    operator>(const Fixed &other) const;
        bool    operator<(const Fixed &other) const;
        bool    operator>=(const Fixed &other) const;
        bool    operator<=(const Fixed &other) const;
        bool    operator==(const Fixed &other) const;
        bool    operator!=(const Fixed &other) const;

        // Ex02: Arithmetic Operators
        Fixed   operator+(const Fixed &other) const;
        Fixed   operator-(const Fixed &other) const;
        Fixed   operator*(const Fixed &other) const;
        Fixed   operator/(const Fixed &other) const;

        // Ex02: Increment/Decrement Operators
        Fixed&  operator++(void);      // Pre-increment
        Fixed   operator++(int);       // Post-increment
        Fixed&  operator--(void);      // Pre-decrement
        Fixed   operator--(int);       // Post-decrement

        // Ex02: Static min/max functions
        static Fixed& min(Fixed &a, Fixed &b);
        static const Fixed& min(const Fixed &a, const Fixed &b);
        static Fixed& max(Fixed &a, Fixed &b);
        static const Fixed& max(const Fixed &a, const Fixed &b);
};

// Non-member operator<< overload (from Ex01)
std::ostream &operator<<(std::ostream &outStream, const Fixed &fixedValue);

