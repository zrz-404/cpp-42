/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:55:55 by zrz               #+#    #+#             */
/*   Updated: 2025/05/29 11:56:23 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class WrongAnimal {
protected:
    std::string _type;

public:
    WrongAnimal(std::string type = "DefaultWrongThing"); // Constructor
    WrongAnimal(const WrongAnimal& other);                // Copy constructor
    WrongAnimal& operator=(const WrongAnimal& other);     // Copy assignment operator
    ~WrongAnimal();                                       // Destructor

    void makeSound() const; // <<<< NOT virtual
    std::string getType() const;
};
