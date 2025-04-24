#pragma once

#include <iomanip>
#include <sstream>
#include <iostream>
#include <exception>

#include "Contact.hpp"

class PhoneBook {
    private:
        int contact_index;
        Contact contact_list[8];

        std::string GetField(const std::string &prompt) const;

    public:
        PhoneBook(void);
        ~PhoneBook(void);

        void Add(void);
        void Search(void);
        void Show(int index) const;
        void DisplayHeader(void) const;
        void DisplayContactList(void) const;
        std::string ShortStr(const std::string &str) const;
        int GetContactIndex(const std::string &prompt) const;
} ;
