/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:56:28 by zrz               #+#    #+#             */
/*   Updated: 2025/05/28 14:04:10 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed {
private:
    int                 _fixedPointValue;
    static const int    _fractionalBits = 8;

public:
    // Orthodox Canonical Form
    Fixed(void);                                        // Default constructor
    Fixed(const Fixed &other);                          // Copy constructor
    Fixed &operator=(const Fixed &other);               // Copy assignment operator 
    ~Fixed(void);                                       // Destructor

    // Member functions
    int  getRawBits(void) const;
    void setRawBits(int const raw);
};
