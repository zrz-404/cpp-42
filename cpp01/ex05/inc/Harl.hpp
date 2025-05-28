/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:19:05 by zrz               #+#    #+#             */
/*   Updated: 2025/05/28 11:24:50 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class Harl {
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

		// std::string level_strings[4];
		// void (Harl::*member_functions[4])(void); 

	public:
		Harl();
		~Harl();
		void complain(std::string level);
};
