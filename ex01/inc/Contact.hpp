#pragma once

#include <string>
#include <iostream>

class Contact {
    public:
        Contact();
        ~Contact();

        std::string name;
        std::string surname;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
};
