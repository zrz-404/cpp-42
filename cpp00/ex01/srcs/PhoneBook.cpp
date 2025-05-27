/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:00:31 by jroseiro          #+#    #+#             */
/*   Updated: 2025/05/21 13:31:43 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"
#include <limits> // Required for std::numeric_limits

// Constructor
PhoneBook::PhoneBook(void) : contact_index(0) {
}

// Destructor
PhoneBook::~PhoneBook(void) {
}

std::string PhoneBook::GetField(const std::string &prompt) const {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (std::cin.eof()) { // Handle EOF (Ctrl+D)
            throw std::runtime_error("EOF encountered");
        }
        if (!input.empty()) {
            break;
        }
        std::cout << "Field cannot be empty. Please try again." << std::endl;
    }
    return input;
}

void PhoneBook::Add(void) {
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

    try {
        firstName = GetField("Enter first name: ");
        lastName = GetField("Enter last name: ");
        nickname = GetField("Enter nickname: ");
        phoneNumber = GetField("Enter phone number: ");
        darkestSecret = GetField("Enter darkest secret: ");
    } catch (const std::runtime_error& e) {
        std::cout << std::endl << "Add operation cancelled due to EOF." << std::endl;
        return; // Exit Add operation
    }

    this->contact_list[this->contact_index].setName(firstName);
    this->contact_list[this->contact_index].setSurname(lastName);
    this->contact_list[this->contact_index].setNickname(nickname);
    this->contact_list[this->contact_index].setPhoneNumber(phoneNumber);
    this->contact_list[this->contact_index].setDarkestSecret(darkestSecret);

    this->contact_index = (this->contact_index + 1) % 8; // Cycle through 0-7
    std::cout << "Contact added successfully!" << std::endl;
}

std::string PhoneBook::ShortStr(const std::string &str) const {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    }
    return str;
}

void PhoneBook::DisplayHeader(void) const {
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
}

void PhoneBook::DisplayContactList(void) const {
    bool hasContacts = false;
    for (int i = 0; i < 8; ++i) {
        if (!this->contact_list[i].getName().empty()) { // Check if contact is filled
            hasContacts = true;
            std::cout << std::setw(10) << i << "|";
            std::cout << std::setw(10) << ShortStr(this->contact_list[i].getName()) << "|";
            std::cout << std::setw(10) << ShortStr(this->contact_list[i].getSurname()) << "|";
            std::cout << std::setw(10) << ShortStr(this->contact_list[i].getNickname()) << std::endl;
        }
    }
    if (!hasContacts) {
        std::cout << "Phonebook is empty." << std::endl;
    }
}

void PhoneBook::Show(int index) const {
    if (index < 0 || index >= 8 || this->contact_list[index].getName().empty()) {
        std::cout << "Invalid index or contact not found." << std::endl;
        return;
    }
    std::cout << "Contact Details (Index " << index << "):" << std::endl;
    std::cout << "First Name:     " << this->contact_list[index].getName() << std::endl;
    std::cout << "Last Name:      " << this->contact_list[index].getSurname() << std::endl;
    std::cout << "Nickname:       " << this->contact_list[index].getNickname() << std::endl;
    std::cout << "Phone Number:   " << this->contact_list[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << this->contact_list[index].getDarkestSecret() << std::endl;
}

int PhoneBook::GetContactIndex(const std::string &prompt) const {
    int index = -1;
    std::string input;
    while(true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (std::cin.eof()) {
             throw std::runtime_error("EOF encountered");
        }

        // Check if input is a valid integer
        std::stringstream ss(input);
        if (ss >> index) {
            // Check if there are any trailing characters after the integer
            char c;
            if (!(ss >> c)) { // No trailing characters
                 if (index >= 0 && index < 8) { // Basic range check
                    if (!this->contact_list[index].getName().empty()) { // Check if contact exists
                        break;
                    } else
                        std::cout << "No contact at this index. Please try again." << std::endl;
                } else
                    std::cout << "Index out of range (0-7). Please try again." << std::endl;
            } else // Trailing characters found
                 std::cout << "Invalid input. Please enter a number." << std::endl;
        } else
            std::cout << "Invalid input. Please enter a number." << std::endl;
        std::cin.clear();
    }
    return index;
}

void PhoneBook::Search(void) {
    DisplayHeader();
    DisplayContactList();

    // Check if there are any contacts to search for
    bool isEmpty = true;
    for (int i = 0; i < 8; ++i) {
        if (!this->contact_list[i].getName().empty()) {
            isEmpty = false;
            break;
        }
    }
    if (isEmpty) {
        return; // No contacts to search, already printed "Phonebook is empty."
    }

    try {
        int index = GetContactIndex("Enter index of the contact to display: ");
        Show(index);
    } catch (const std::runtime_error& e) {
         std::cout << std::endl << "Search operation cancelled due to EOF." << std::endl;
    }
}