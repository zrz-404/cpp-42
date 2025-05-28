/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:34:04 by zrz               #+#    #+#             */
/*   Updated: 2025/05/28 11:19:55 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class Weapon {
    private:
        std::string type;
    public:
        Weapon(const std::string& type);
        ~Weapon();
        const std::string& getType() const;
        void setType(const std::string& newType);
};
