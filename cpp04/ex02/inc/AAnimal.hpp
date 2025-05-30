/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:57:20 by zrz               #+#    #+#             */
/*   Updated: 2025/05/30 10:21:49 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class AAnimal {
protected:
    std::string _type;

public:
    AAnimal(std::string type = "DefaultAbstractAnimal");
    AAnimal(const AAnimal& other);
    AAnimal& operator=(const AAnimal& other);
    virtual ~AAnimal();

    virtual void makeSound() const = 0; // <<<< PURE VIRTUAL function

    std::string getType() const;
};
