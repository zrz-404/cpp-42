/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:56:51 by zrz               #+#    #+#             */
/*   Updated: 2025/05/28 16:13:10 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
    std::cout << "--- Creating ClapTrap ---" << std::endl;
    ClapTrap ct("CT-01");
    ct.attack("Bandit");
    ct.takeDamage(5);
    ct.beRepaired(3);
    ct.takeDamage(10); // Knock out ClapTrap
    ct.attack("Another Bandit");
    ct.beRepaired(5);
    std::cout << std::endl;

    std::cout << "--- Creating ScavTrap ---" << std::endl;
    ScavTrap st("ST-Defender");
    std::cout << std::endl;

    st.attack("Raider");
    st.takeDamage(30);
    st.beRepaired(20);
    st.guardGate();
    std::cout << std::endl;

    std::cout << "--- ScavTrap taking more damage ---" << std::endl;
    st.takeDamage(100);
    st.attack("Another Raider");
    st.guardGate();
    st.beRepaired(10);
    std::cout << std::endl;

    std::cout << "--- Testing ScavTrap Copy ---" << std::endl;
    ScavTrap st2("ST-Guardian");
    ScavTrap st_copy(st2);
    st_copy.attack("CopyTarget");
    ScavTrap st_assigned("ST-Temp");
    st_assigned = st2;
    st_assigned.guardGate();
    std::cout << std::endl;
    
    std::cout << "--- Showing Construction/Destruction Order ---" << std::endl;
    {
        std::cout << "Entering scope..." << std::endl;
        ScavTrap scoped_st("ScopedScav");
        scoped_st.attack("ScopeTarget");
        std::cout << "Exiting scope..." << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- End of tests ---" << std::endl;
    // Destructors for ct, st, st2, st_copy, st_assigned called here in reverse order of creation
    return 0;
}