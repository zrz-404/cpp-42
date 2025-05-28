/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:34:34 by zrz               #+#    #+#             */
/*   Updated: 2025/05/28 11:19:45 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanA {
    private:
        std::string name;
        Weapon& weapon; // Reference to a weapon
    public:
        HumanA(const std::string& name, Weapon& weapon);
        ~HumanA();
        void attack() const;
};
