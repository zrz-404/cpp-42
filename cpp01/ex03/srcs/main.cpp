/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:37:01 by zrz               #+#    #+#             */
/*   Updated: 2025/05/28 11:23:12 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int main() {
    {
        Weapon club = Weapon("crude spiked club"); // Weapon object on the stack

        HumanA bob("Bob", club); // Bob is created with a reference to club
        bob.attack();
        club.setType("some other type of club"); // The original club's type is changed
        bob.attack(); // Bob attacks with the modified weapon
    }
    std::cout << "---" << std::endl;
    {
        Weapon club = Weapon("crude spiked club"); // New Weapon object on the stack

        HumanB jim("Jim"); // Jim is created, initially unarmed (weapon pointer is NULL)
        // jim.attack(); // here Jim would be unarmed.
        jim.setWeapon(club); // Jim's weapon pointer is set to the address of club
        jim.attack();
        club.setType("some other type of club"); // The original club's type is changed
        jim.attack(); // Jim attacks with the modified weapon
    }
    return 0;
}