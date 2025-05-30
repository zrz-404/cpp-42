/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:05:20 by zrz               #+#    #+#             */
/*   Updated: 2025/05/30 10:26:11 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
private:
    Brain* _brain;

public:
    // Orthodox Canonical Form
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    ~Cat();

    virtual void makeSound() const;

    //brain stuff
    void setIdea(int index, const std::string& idea);
    const std::string& getIdea(int index) const;
    void printBrainIdeas() const;
};
