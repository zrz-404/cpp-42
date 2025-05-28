/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:35:02 by zrz               #+#    #+#             */
/*   Updated: 2025/05/28 11:19:49 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanB {
    private:
        std::string name;
        Weapon* weapon; // Pointer to a weapon
    public:
        HumanB(const std::string& name);
        ~HumanB();
        void setWeapon(Weapon& newWeapon);
        void attack() const;
};
