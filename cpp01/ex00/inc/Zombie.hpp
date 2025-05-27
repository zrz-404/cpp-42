/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:12:55 by jroseiro          #+#    #+#             */
/*   Updated: 2025/05/26 16:20:41 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Zombie { 
	private:
		std::string name;
	public:
		std::string getName() const;

		void setName(const std::string& Name);
		void speak();

};
