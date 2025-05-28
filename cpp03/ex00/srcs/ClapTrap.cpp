/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:19:17 by zrz               #+#    #+#             */
/*   Updated: 2025/05/28 16:27:04 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructor
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << this->_name << " has been constructed!" << std::endl;
}

// Copy Constructor
ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << "ClapTrap copy constructor called for " << other._name << std::endl;
    *this = other;
}

// Copy Assignment Operator
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "ClapTrap assignment operator called for " << other._name << std::endl;
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

// Destructor
ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << this->_name << " has been destructed!" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (this->_hitPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " cannot attack, it has no hit points left!" << std::endl;
        return;
    }
    if (this->_energyPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " cannot attack, it has no energy points left!" << std::endl;
        return;
    }
    this->_energyPoints--; // Attacking costs 1 energy point
    std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hitPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " is already knocked out and cannot take more damage." << std::endl;
        return;
    }
    
    unsigned int actualDamage = amount;
    if (actualDamage > this->_hitPoints) {
        actualDamage = this->_hitPoints; // Cannot lose more HP than it has
    }
    
    this->_hitPoints -= actualDamage;
    std::cout << "ClapTrap " << this->_name << " takes " << actualDamage << " points of damage! Remaining HP: " << this->_hitPoints << "." << std::endl;

    if (this->_hitPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " has been knocked out!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_hitPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " cannot be repaired, it has no hit points left!" << std::endl;
        return;
    }
    if (this->_energyPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " cannot be repaired, it has no energy points left!" << std::endl;
        return;
    }
    this->_energyPoints--; // Repairing costs 1 energy point
    this->_hitPoints += amount;
    std::cout << "ClapTrap " << this->_name << " repairs itself for " << amount << " hit points! Current HP: " << this->_hitPoints << ". Energy points left: " << this->_energyPoints << "." << std::endl;
}
