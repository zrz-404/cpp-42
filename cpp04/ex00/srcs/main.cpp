/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:57:03 by zrz               #+#    #+#             */
/*   Updated: 2025/05/29 13:14:00 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex00.hpp"

int main() {
	std::cout << "--- Testing Polymorphism with Animal, Dog, Cat ---" << std::endl;
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	
	
    std::cout << "Type of dog: " << dog->getType() << " " << std::endl;
    std::cout << "Type of cat: " << cat->getType() << " " << std::endl;
	std::cout << "Type of meta: " << meta->getType() << " " << std::endl;
	
	std::cout << "Sound of Chaos (Cat): ";
	cat->makeSound();
    std::cout << "Sound of Wisdom (dog): ";
	dog->makeSound();
    std::cout << "Sound of living thing (Animal): ";
    meta->makeSound();
	std::cout << std::endl;

	std::cout << "--- Making Animal, Dog, Cat, extinct (deleting) ---" << std::endl;
    delete cat;
    delete dog;
    delete meta;
    std::cout << std::endl;
	
	
	std::cout << "--- Testing \"Wrong\" Polymorphism with WrongAnimal, WrongCat ---" << std::endl;
	const WrongAnimal* animale = new WrongAnimal();
	const WrongCat* gattitto = new WrongCat();
	std::cout << std::endl;
	
	std::cout << "Suono di una cosa viva (wrongAnimal): ";
	animale->makeSound();
	std::cout << "Suono di un riquittitto  Gattitto (wrongCat): ";
	gattitto->makeSound();
	std::cout << std::endl;

	std::cout << "--- Estinzione di Animale e Gattitto (deleting) ---" << std::endl;
	delete gattitto;
	delete animale;
	
	return 0;
}
