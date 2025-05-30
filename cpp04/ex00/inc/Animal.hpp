/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:57:20 by zrz               #+#    #+#             */
/*   Updated: 2025/05/29 10:45:59 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Animal {
    protected: // instead of private, for inheritance
        std::string _type;

    public:
        Animal(std::string name = "DefaultLivingThing");    // Default constructor
        Animal(const Animal& other);                        // Copy constructor
        Animal& operator=(const Animal& other);             // Copy assignment operator
        virtual ~Animal();                                 // Destructor

        // Member functions

        virtual void makeSound() const;
        std::string getType() const;

        // std::string getName() const;
};
