/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:57:03 by zrz               #+#    #+#             */
/*   Updated: 2025/05/30 11:18:57 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex00.hpp"

#define N_ANIMALS 4 // Number of animals in the array

int main() {
    std::cout << "--- Ex01: I don't want to set the world on fire ---" << std::endl;
    std::cout << std::endl;

    // Test from PDF: Simple Dog and Cat creation and deletion (testing Brain deallocation)
    std::cout << "--- PDF Test: Basic Dog/Cat Creation & Deletion ---" << std::endl;
    const Animal* j_pdf = new Dog();
    const Animal* i_pdf = new Cat();
    std::cout << "Deleting Dog from PDF test:" << std::endl;
    delete j_pdf;
    std::cout << "Deleting Cat from PDF test:" << std::endl;
    delete i_pdf;
    std::cout << std::endl;

    // Test: Array of Animals
    std::cout << "--- Test: Array of Animals (Half Dogs, Half Cats) ---" << std::endl;
    Animal* animals[N_ANIMALS];

    // Fill half of array with Dogs
    for (int i = 0; i < N_ANIMALS / 2; ++i) {
        std::cout << "Creating Dog " << i << std::endl;
        animals[i] = new Dog();
        std::cout << std::endl;
    }

    // Fill the other half with Cats
    for (int i = N_ANIMALS / 2; i < N_ANIMALS; ++i) {
        std::cout << "Creating Cat " << i << std::endl;
        animals[i] = new Cat();
        std::cout << std::endl;
    }

    // for (int i = 0; i < N_ANIMALS; ++i) {
    //     animals[i]->makeSound();
    // }
    // std::cout << std::endl;

    // Delete all animals
    std::cout << "--- Deleting Animals from Array ---" << std::endl;
    for (int i = 0; i < N_ANIMALS; ++i) {
        std::cout << "Deleting animal at index " << i << " (" << animals[i]->getType() << ")" << std::endl;
        delete animals[i]; // Virtual destructor in Animal makes surte correct destructor is called
        animals[i] = NULL;
        std::cout << std::endl;
    }

    std::cout << "--- Test: Deep Copy for Dog ---" << std::endl;
    Dog dog_original;
    dog_original.setIdea(0, "Original dog idea: Chase mailman");
    dog_original.setIdea(1, "Original dog idea: Eat food");

    std::cout << "\nDog Original's Brain:" << std::endl;
    dog_original.printBrainIdeas();

    std::cout << "\nCreating Dog Copy (Copy Constructor)..." << std::endl;
    Dog dog_copy = dog_original; // Calls copy constructor
    std::cout << "Dog Copy's Brain (should be same as original's initial state):" << std::endl;
    dog_copy.printBrainIdeas();

    std::cout << "\nCreating Dog Assign (Assignment Operator)..." << std::endl;
    Dog dog_assign;
    dog_assign = dog_original; // Calls assignment operator
    std::cout << "Dog Assign's Brain (should be same as original's initial state):" << std::endl;
    dog_assign.printBrainIdeas();

    std::cout << "\nModifying Original Dog's first idea..." << std::endl;
    dog_original.setIdea(0, "Original dog idea MODIFIED: Befriend mailman");
    std::cout << "Dog Original's Brain AFTER MODIFICATION:" << std::endl;
    dog_original.printBrainIdeas();

    std::cout << "\nDog Copy's Brain (should be UNCHANGED):" << std::endl;
    dog_copy.printBrainIdeas();
    std::cout << "Dog Assign's Brain (should be UNCHANGED):" << std::endl;
    dog_assign.printBrainIdeas();
    std::cout << std::endl;

    std::cout << "--- Test: Deep Copy for Cat ---" << std::endl;
    Cat cat_original;
    cat_original.setIdea(0, "Original cat idea: Nap in sunbeam");
    cat_original.setIdea(1, "Original cat idea: Knock things off table");

    std::cout << "\nCat Original's Brain:" << std::endl;
    cat_original.printBrainIdeas();

    std::cout << "\nCreating Cat Copy (Copy Constructor)..." << std::endl;
    Cat cat_copy = cat_original;
    std::cout << "Cat Copy's Brain:" << std::endl;
    cat_copy.printBrainIdeas();

    std::cout << "\nCreating Cat Assign (Assignment Operator)..." << std::endl;
    Cat cat_assign;
    cat_assign = cat_original;
    std::cout << "Cat Assign's Brain:" << std::endl;
    cat_assign.printBrainIdeas();

    std::cout << "\nModifying Original Cat's first idea..." << std::endl;
    cat_original.setIdea(0, "Original cat idea MODIFIED: Stare intently at wall");
    std::cout << "Cat Original's Brain AFTER MODIFICATION:" << std::endl;
    cat_original.printBrainIdeas();

    std::cout << "\nCat Copy's Brain (should be UNCHANGED):" << std::endl;
    cat_copy.printBrainIdeas();
    std::cout << "Cat Assign's Brain (should be UNCHANGED):" << std::endl;
    cat_assign.printBrainIdeas();
    std::cout << std::endl;

    std::cout << "--- End of Exercise 01 Tests (Scope Exit Will Trigger Destructors for original/copy/assign dogs and cats) ---" << std::endl;
    return 0;
}
