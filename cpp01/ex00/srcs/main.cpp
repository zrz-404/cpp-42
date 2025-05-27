/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:12:45 by jroseiro          #+#    #+#             */
/*   Updated: 2025/05/27 14:03:44 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    // Test newZombie (heap allocation)
    Zombie* heap_zombie = newZombie("HeapZombie");
    heap_zombie->announce();
    delete heap_zombie;

    std::cout << "---" << std::endl;

    // Test randomChump (stack allocation)
    randomChump("randomChump");

    std::cout << "---" << std::endl;
    // randomChump should be destroyed before this line.
    Zombie* another_heap_zombie = newZombie("newZombie");
    another_heap_zombie->announce();
    delete another_heap_zombie;

    return 0;
}