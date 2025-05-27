/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:32:11 by jroseiro          #+#    #+#             */
/*   Updated: 2025/05/21 13:32:15 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"
#include <iostream>
#include <string> // Required for std::string and std::getline

int main() {
    PhoneBook phonebook;
    std::string input;

    std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;
    std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;

    while (true) {
        std::cout << "\nEnter command: ";
        std::getline(std::cin, input);

        if (std::cin.eof()) { // Handle EOF (Ctrl+D) as EXIT
            std::cout << std::endl << "Exiting PhoneBook due to EOF. Goodbye!" << std::endl;
            break;
        }

        if (input == "ADD") {
            phonebook.Add();
        } else if (input == "SEARCH") {
            phonebook.Search();
        } else if (input == "EXIT") {
            std::cout << "Exiting PhoneBook. Goodbye!" << std::endl;
            break;
        } else {
            if (!input.empty()) { // Only show error for non-empty invalid commands
                 std::cout << "Invalid command. Available commands: ADD, SEARCH, EXIT" << std::endl;
            }
        }
    }
    return 0;
}
