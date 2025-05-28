/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:01:41 by jroseiro          #+#    #+#             */
/*   Updated: 2025/05/28 11:21:27 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Default constructor implementation
Zombie::Zombie() : name("Unnamed Zombie") { // Or some other default
    std::cout << "Temporary Zombie created (will be named shortly)." << std::endl;
}

Zombie::Zombie(const std::string& nameVal) : name(nameVal) {
}

Zombie::~Zombie() {
    std::cout << this->name << ": Destroyed..." << std::endl;
}

void Zombie::announce(void) {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
