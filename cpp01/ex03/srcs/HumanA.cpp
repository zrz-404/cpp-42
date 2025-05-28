/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:37:50 by zrz               #+#    #+#             */
/*   Updated: 2025/05/28 09:38:01 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// HumanA takes its weapon by reference in the constructor's initializer list
HumanA::HumanA(const std::string& name, Weapon& weapon) : name(name), weapon(weapon) {
    // std::cout << "HumanA named '" << this->name << "' created, armed with " << this->weapon.getType() << std::endl;
}

HumanA::~HumanA() {
    // std::cout << "HumanA named '" << this->name << "' destroyed." << std::endl;
}

void HumanA::attack() const {
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
