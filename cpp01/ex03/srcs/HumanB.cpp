/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:37:48 by zrz               #+#    #+#             */
/*   Updated: 2025/05/28 09:38:38 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/* HumanB's weapon pointer is initialized to NULL (or nullptr in C++11)
// For C++98, NULL is defined in <cstddef> or <cstdlib> or often just as 0.
// #include <cstddef> // For NULL
*/
HumanB::HumanB(const std::string& name) : name(name), weapon(NULL) {
    // std::cout << "HumanB named '" << this->name << "' created, unarmed." << std::endl;
}

HumanB::~HumanB() {
    // std::cout << "HumanB named '" << this->name << "' destroyed." << std::endl;
}

void HumanB::setWeapon(Weapon& newWeapon) {
    this->weapon = &newWeapon; // Store the address of the weapon
    // std::cout << "HumanB '" << this->name << "' is now armed with " << this->weapon->getType() << std::endl;
}

void HumanB::attack() const {
    if (this->weapon) { // Check if the pointer is not NULL
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
    } else {
        std::cout << this->name << " tries to attack, but is unarmed!" << std::endl;
    }
}
