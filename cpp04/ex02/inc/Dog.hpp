/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:31:36 by zrz               #+#    #+#             */
/*   Updated: 2025/05/30 10:26:08 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp" 

class Dog : public AAnimal {
private:
    Brain* _brain;

public:
    // Orthodox Canonical Form
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    ~Dog();

    virtual void makeSound() const;

    // brain stuff
    void setIdea(int index, const std::string& idea);
    const std::string& getIdea(int index) const;
    void printBrainIdeas() const;
};
