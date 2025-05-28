/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:57:20 by zrz               #+#    #+#             */
/*   Updated: 2025/05/28 16:29:34 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class ClapTrap {
    protected: // instead of private, for inheritance
        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;

    public:
        ClapTrap(std::string name = "DefaultClap"); // Default constructor
        ClapTrap(const ClapTrap& other);            // Copy constructor
        ClapTrap& operator=(const ClapTrap& other); // Copy assignment operator
        ~ClapTrap(); // Destructor

        // Member functions
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        std::string getName() const;
};
