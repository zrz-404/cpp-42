/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:32:30 by zrz               #+#    #+#             */
/*   Updated: 2025/05/28 16:33:10 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructor
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->_hitPoints = 100;    // FragTrap specific
    this->_energyPoints = 100; // FragTrap specific
    this->_attackDamage = 30;  // FragTrap specific
    std::cout << "FragTrap " << this->_name << " has been manufactured (FragTrap Constructor)!" << std::endl; //
}

// Copy Constructor
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap " << this->_name << " blueprint copied (FragTrap Copy Constructor)!" << std::endl;
}

// Copy Assignment Operator
FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other); 
        // Call base class assignment operator
        // FragTrap specific values for HP, EP, AD are set by its constructor.
    }
    std::cout << "FragTrap " << this->_name << " reconfigured (FragTrap Copy Assignment Operator)!" << std::endl;
    return *this;
}

// Destructor
FragTrap::~FragTrap() {
    std::cout << "FragTrap " << this->_name << " has been scrapped (FragTrap Destructor)!" << std::endl; //
}

void FragTrap::highFivesGuys(void) {
    if (this->_hitPoints == 0) {
        std::cout << "FragTrap " << this->_name << " is too broken for a high five..." << std::endl;
        return;
    }
    std::cout << "FragTrap " << this->_name << " requests a super positive high five! Anyone?" << std::endl; //
}