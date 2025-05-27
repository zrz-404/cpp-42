/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:12:45 by jroseiro          #+#    #+#             */
/*   Updated: 2025/05/27 15:51:20 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    int numZombies = 5;
    std::string zombieName = "HordeMember";

    Zombie* horde = zombieHorde(numZombies, zombieName);

    if (horde) {
        std::cout << "Zombie horde created. Announcing each zombie:" << std::endl;
        for (int i = 0; i < numZombies; ++i) {
            horde[i].announce();
        }

        std::cout << "Deleting zombie horde..." << std::endl;
        delete[] horde; // Deallocate the entire array
    } else {
        std::cout << "Failed to create zombie horde." << std::endl;
    }

    std::cout << "---" << std::endl;
    // Zombie* noHorde = zombieHorde(0, "TinyTim");
    if (numZombies < 1) {
        std::cout << "Correctly handled N=0 for zombieHorde." << std::endl;
    }

    return 0;
}