/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:56:51 by zrz               #+#    #+#             */
/*   Updated: 2025/05/28 16:33:35 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main() {
    std::cout << "--- Creating ClapTrap (for context) ---" << std::endl;
    ClapTrap ct_base("CT-Base");
    ct_base.attack("Something");
    std::cout << std::endl;

    std::cout << "--- Creating FragTrap ---" << std::endl;
    FragTrap ft("FR4G-TP");
    std::cout << std::endl;

    ft.attack("a big scary monster"); // Uses FragTrap's AD (30)
    ft.takeDamage(40);  // HP: 100 -> 60
    ft.beRepaired(25);  // HP: 60 -> 85, EP: 100 -> 99
    ft.highFivesGuys();
    std::cout << std::endl;

    std::cout << "--- FragTrap taking massive damage ---" << std::endl;
    ft.takeDamage(150); // Should knock out FragTrap (HP: 85 -> 0)
    ft.attack("the void"); // Should fail
    ft.highFivesGuys();    // Should indicate it's broken
    ft.beRepaired(10);     // Should fail
    std::cout << std::endl;

    std::cout << "--- Testing FragTrap Copy ---" << std::endl;
    FragTrap ft2("FR4G-Buddy");
    FragTrap ft_copy(ft2); // Copy constructor
    ft_copy.attack("CopyTarget");
    ft_copy.highFivesGuys();

    FragTrap ft_assigned("FR4G-Temp");
    ft_assigned = ft2; // Copy assignment
    ft_assigned.attack("AssignedTarget");
    std::cout << std::endl;
    
    std::cout << "--- Showing Construction/Destruction Order ---" << std::endl;
    {
        std::cout << "Entering new scope..." << std::endl;
        FragTrap scoped_ft("ScopedFrag");
        scoped_ft.attack("ScopeMonster");
        scoped_ft.highFivesGuys();
        std::cout << "Exiting new scope..." << std::endl;
    } // scoped_ft destructor (FragTrap then ClapTrap) will be called here
    std::cout << std::endl;

    std::cout << "--- End of ex02 tests ---" << std::endl;
    // Destructors for ct_base, ft, ft2, ft_copy, ft_assigned will be called here
    return 0;
}