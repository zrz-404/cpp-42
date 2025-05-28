/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:05:01 by zrz               #+#    #+#             */
/*   Updated: 2025/05/28 16:08:42 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100; 
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " has been assembled (ScavTrap Constructor)!" << std::endl;
}

// Copy Constructor
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "ScavTrap " << this->_name << " has been duplicated (ScavTrap Copy Constructor)!" << std::endl;
}

// Copy Assignment Operator
ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << "ScavTrap " << this->_name << " assignment completed (ScavTrap Copy Assignment Operator)!" << std::endl;
	return *this;
}

// Destructor
ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->_name << " has been disassembled (ScavTrap Destructor)!" << std::endl;
}

// Overridden attack function
void ScavTrap::attack(const std::string& target) {
	if (this->_hitPoints == 0) {
		std::cout << "ScavTrap " << this->_name << " is too damaged to attack!" << std::endl;
		return;
	}
	if (this->_energyPoints == 0) {
		std::cout << "ScavTrap " << this->_name << " has no energy to attack!" << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << "ScavTrap " << this->_name << " fiercely attacks " << target << ", causing " << this->_attackDamage << " points of damage! Energy left: " << this->_energyPoints << std::endl;
}

void ScavTrap::guardGate() {
	if (this->_hitPoints == 0) {
		std::cout << "ScavTrap " << this->_name << " can't enter Gate keeper mode, it's knocked out!" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode!" << std::endl;
}
