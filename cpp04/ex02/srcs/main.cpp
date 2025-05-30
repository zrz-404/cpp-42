/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:57:03 by zrz               #+#    #+#             */
/*   Updated: 2025/05/30 10:38:49 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex00.hpp"

#define N_ANIMALS 4 // Number of animals in the array

int main() {
    std::cout << "--- Exercise 02: Abstract Class ---" << std::endl;
    std::cout << std::endl;

    // const AAnimal* meta = new AAnimal(); // <<<< THIS LINE WILL NOW CAUSE A COMPILATION ERROR!
                                            // An AAnimal cannot be instantiated. This is the point of ex02.
                                            
    // std::cout << "Type of meta: " << meta->getType() << " " << std::endl;
    // meta->makeSound();
    // delete meta;

    std::cout << "--- PDF Test: Basic Dog/Cat Creation & Deletion (using AAnimal pointers) ---" << std::endl;
    const AAnimal* j_pdf = new Dog(); // This is fine, Dog is concrete
    const AAnimal* i_pdf = new Cat(); // This is fine, Cat is concrete

    std::cout << "Type of j_pdf (Dog): " << j_pdf->getType() << std::endl;
    j_pdf->makeSound();
    std::cout << "Type of i_pdf (Cat): " << i_pdf->getType() << std::endl;
    i_pdf->makeSound();

    std::cout << "\nDeleting Dog from PDF test:" << std::endl;
    delete j_pdf;
    std::cout << "Deleting Cat from PDF test:" << std::endl;
    delete i_pdf;
    std::cout << std::endl;

    std::cout << "--- Test: Array of AAnimals (Half Dogs, Half Cats) ---" << std::endl;
    AAnimal* animals[N_ANIMALS]; // Array of AAnimal pointers

    for (int i = 0; i < N_ANIMALS / 2; ++i) {
        std::cout << "Creating Dog " << i << std::endl;
        animals[i] = new Dog();
        std::cout << std::endl;
    }
    for (int i = N_ANIMALS / 2; i < N_ANIMALS; ++i) {
        std::cout << "Creating Cat " << i << std::endl;
        animals[i] = new Cat();
        std::cout << std::endl;
    }

    std::cout << "--- Deleting AAnimals from Array ---" << std::endl;
    for (int i = 0; i < N_ANIMALS; ++i) {
        std::cout << "Deleting animal at index " << i << " (" << animals[i]->getType() << ")" << std::endl;
        delete animals[i];
        animals[i] = NULL;
        std::cout << std::endl;
    }

    // Deep copy tests for Dog and Cat should still work as in ex01
    std::cout << "--- Test: Deep Copy for Dog (should still work) ---" << std::endl;
    Dog dog_original;
    dog_original.setIdea(0, "Original dog idea: Bark at squirrel");
    dog_original.printBrainIdeas();
    Dog dog_copy = dog_original;
    dog_copy.printBrainIdeas();
    dog_original.setIdea(0, "Original dog idea MODIFIED: Sleep");
    std::cout << "Original after mod:" << std::endl;
    dog_original.printBrainIdeas();
    std::cout << "Copy after mod (should be unchanged):" << std::endl;
    dog_copy.printBrainIdeas(); // Check deep copy still holds
    std::cout << std::endl;

    std::cout << "--- End of Exercise 02 Tests ---" << std::endl;
    return 0;
}