/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:19:29 by zrz               #+#    #+#             */
/*   Updated: 2025/05/28 16:23:59 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    // Test default constructor and named constructor
    ClapTrap claptrap1("Trap Trap");
    ClapTrap claptrap2("LoaderBot");
    ClapTrap defaultClap;
    std::cout << std::endl;

    // Test attack
    std::cout << "--- ATTACK TESTS ---" << std::endl;
    claptrap1.attack("a scary door"); // Attack damage is 0 by default
    claptrap2.attack("itself in confusion");
    std::cout << std::endl;

    // Test takeDamage
    std::cout << "--- TAKEDAMAGE TESTS ---" << std::endl;
    claptrap1.takeDamage(5);  // HP: 10 -> 5
    claptrap1.takeDamage(3);  // HP: 5 -> 2
    claptrap1.takeDamage(10); // HP: 2 -> 0 (knocked out)
    claptrap1.takeDamage(3);  // Already knocked out
    std::cout << std::endl;

    // Test beRepaired
    std::cout << "--- BEREPAIRED TESTS ---" << std::endl;
    claptrap2.beRepaired(5); // EP: 10 -> 9, HP: 10 -> 15
    claptrap1.beRepaired(5); // Knocked out, won't repair
    std::cout << std::endl;

    // Test energy points depletion
    std::cout << "--- ENERGY DEPLETION TESTS ---" << std::endl;
    ClapTrap energeticBot("Sparky");    // HP:10, EP:10, AD:0
    for (int i = 0; i < 11; ++i) {      // Tries to attack 11 times
        energeticBot.attack("a training dummy");
        // Last attack fails due to no energy
    }
    energeticBot.beRepaired(5); // Should also fail due to no energy if all 10 were used by attacks
    std::cout << std::endl;

    // Test copy constructor and assignment operator
    std::cout << "--- COPY AND ASSIGNMENT TESTS ---" << std::endl;
    ClapTrap original("Original");
    original.takeDamage(3); // Original HP: 7, EP: 10

    ClapTrap copyConstructed(original); // Copy constructor
    copyConstructed.attack("CopyTarget");

    ClapTrap assignedBot("PreAssign");
    assignedBot = original; // Assignment operator
    assignedBot.attack("AssignedTarget");
    std::cout << std::endl;
    
    std::cout << "--- END OF TESTS ---" << std::endl;
    // Destructors called in reverse order of creation
    return 0;
}