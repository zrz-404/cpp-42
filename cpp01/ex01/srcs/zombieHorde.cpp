/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:05:48 by zrz               #+#    #+#             */
/*   Updated: 2025/05/27 15:48:57 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    if (N <= 0) {
        std::cerr << "Error: Number of zombies must be positive." << std::endl;
        return NULL;
    }
    Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; ++i) {
        horde[i] = Zombie(name);
    }

    return horde;
}