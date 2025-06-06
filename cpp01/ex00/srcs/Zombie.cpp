/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:01:41 by jroseiro          #+#    #+#             */
/*   Updated: 2025/05/28 11:20:47 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp" // Use quotes for local headers

// Constructor
Zombie::Zombie(std::string name) : name(name) {
    std::cout << "Zombie " << this->name << " created." << std::endl;
}

// Destructor
Zombie::~Zombie() {
    std::cout << this->name << ": Destroyed..." << std::endl; // Example debug message
}

// Announce method
void Zombie::announce(void) {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
