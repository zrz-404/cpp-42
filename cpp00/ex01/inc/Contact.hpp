/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:03:27 by jroseiro          #+#    #+#             */
/*   Updated: 2025/04/25 13:03:29 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Contact {
    private:
        std::string name;
        std::string surname;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;

    public:
        Contact();
        ~Contact();

        std::string getName() const;
        std::string getSurname() const;
        std::string getNickname() const;
        std::string getPhoneNumber() const;
        std::string getDarkestSecret() const;

        void setName(const std::string& newName);
        void setSurname(const std::string& newSurname);
        void setNickname(const std::string& newNickname);
        void setPhoneNumber(const std::string& newPhoneNumber);
        void setDarkestSecret(const std::string& newDarkestSecret);
};
