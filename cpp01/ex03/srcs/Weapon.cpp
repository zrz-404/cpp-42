/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:35:38 by zrz               #+#    #+#             */
/*   Updated: 2025/05/28 09:37:45 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : type(type) {
    // std::cout << "Weapon of type '" << this->type << "' created." << std::endl;
}

Weapon::~Weapon() {
    // std::cout << "Weapon of type '" << this->type << "' destroyed." << std::endl;
}

const std::string& Weapon::getType() const {
    return this->type;
}

void Weapon::setType(const std::string& newType) {
    // std::cout << "Weapon type changed from '" << this->type << "' to '" << newType << "'." << std::endl;
    this->type = newType;
}