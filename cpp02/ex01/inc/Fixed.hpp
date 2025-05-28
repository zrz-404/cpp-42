/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:56:28 by zrz               #+#    #+#             */
/*   Updated: 2025/05/28 14:17:31 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed {
private:
    int                 _fixedPointValue;
    static const int    _fractionalBits = 8;

public:
    // Orthodox Canonical Form (OCF)
    Fixed(void);                                // Default constructor
    Fixed(const Fixed &other);                  // Copy constructor
    Fixed &operator=(const Fixed &other);       // Copy assignment operator
    ~Fixed(void);                               // Destructor

  
    Fixed(const int intValue);                  // Integer constructor
    Fixed(const float floatValue);              // Float constructor

    int  getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat(void) const;
    int   toInt(void) const;
};

// Non-member operator<< overload declaration
std::ostream &operator<<(std::ostream &outStream, const Fixed &fixedValue);

