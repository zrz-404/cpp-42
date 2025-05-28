/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:02:20 by zrz               #+#    #+#             */
/*   Updated: 2025/05/28 16:02:22 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Default Constructor
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << this->_name << " is born (Constructor)!" << std::endl;
}

// Copy Constructor
ClapTrap::ClapTrap(const ClapTrap& other) {
    *this = other;
    std::cout << "ClapTrap " << this->_name << " has been copied (Copy Constructor)!" << std::endl;
}

// Copy Assignment Operator
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    std::cout << "ClapTrap " << this->_name << " has been assigned (Copy Assignment Operator)!" << std::endl;
    return *this;
}

// Destructor
ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << this->_name << " is destroyed (Destructor)!" << std::endl;
}

std::string ClapTrap::getName() const {
    return this->_name;
}

void ClapTrap::attack(const std::string& target) {
    if (this->_hitPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " can't attack, it has no hit points left!" << std::endl;
        return;
    }
    if (this->_energyPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " can't attack, it has no energy points left!" << std::endl;
        return;
    }
    this->_energyPoints--;
    std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hitPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " can't take more damage, it's already knocked out!" << std::endl;
        return;
    }
    if (amount > this->_hitPoints) {
        this->_hitPoints = 0;
    } else {
        this->_hitPoints -= amount;
    }
    std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage! Remaining HP: " << this->_hitPoints << std::endl;
    if (this->_hitPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " has been knocked out!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_hitPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " can't be repaired, it's already knocked out!" << std::endl;
        return;
    }
    if (this->_energyPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " can't be repaired, it has no energy points left!" << std::endl;
        return;
    }
    this->_energyPoints--;
    this->_hitPoints += amount;
    std::cout << "ClapTrap " << this->_name << " repairs itself for " << amount << " hit points! Current HP: " << this->_hitPoints << ", Current EP: " << this->_energyPoints << std::endl;
}