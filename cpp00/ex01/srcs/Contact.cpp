/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:03:22 by jroseiro          #+#    #+#             */
/*   Updated: 2025/05/21 13:27:00 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.hpp"

// Constructor
Contact::Contact() {
}

// Destructor
Contact::~Contact() {
}

/*****  Getters  *****/
std::string Contact::getName() const {
    return this->name;
}

std::string Contact::getSurname() const {
    return this->surname;
}

std::string Contact::getNickname() const {
    return this->nickname;
}

std::string Contact::getPhoneNumber() const {
    return this->phone_number;
}

std::string Contact::getDarkestSecret() const {
    return this->darkest_secret;
}

/****  Setters  *****/
void Contact::setName(const std::string& newName) {
    this->name = newName;
}

void Contact::setSurname(const std::string& newSurname) {
    this->surname = newSurname;
}

void Contact::setNickname(const std::string& newNickname) {
    this->nickname = newNickname;
}

void Contact::setPhoneNumber(const std::string& newPhoneNumber) {
    this->phone_number = newPhoneNumber;
}

void Contact::setDarkestSecret(const std::string& newDarkestSecret) {
    this->darkest_secret = newDarkestSecret;
}