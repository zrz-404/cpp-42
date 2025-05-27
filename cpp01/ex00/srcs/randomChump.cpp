/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:12:50 by jroseiro          #+#    #+#             */
/*   Updated: 2025/05/27 13:58:59 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*  Creates a zombie on the stack
	Makes it announce itself
	stackZombie is destroyed automatically when this function ends
*/ 

void randomChump(std::string name) {
	Zombie stackZombie = Zombie(name);
	stackZombie.announce();
}