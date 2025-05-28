/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:41:31 by zrz               #+#    #+#             */
/*   Updated: 2025/05/28 11:22:10 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {
    std::string myString = "HI THIS IS BRAIN";
    std::string* stringPTR = &myString;
    std::string& stringREF = myString;

    // Print memory addresses
    std::cout << "Memory address of the string variable: " << &myString << std::endl;
    std::cout << "Memory address held by stringPTR:      " << stringPTR << std::endl; 
    // For a pointer, printing the pointer itself shows the address itself
    std::cout << "Memory address held by stringREF:      " << &stringREF << std::endl; 
    // Taking the address of a reference gives the address of the original var

    std::cout << "---" << std::endl;

    std::cout << "Value of the string variable: " << myString << std::endl;
    std::cout << "Value pointed to by stringPTR:  " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF:  " << stringREF << std::endl; 
    // Accessing a reference directly gives the value.

    return 0;
}
