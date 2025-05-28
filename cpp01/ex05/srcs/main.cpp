/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:27:06 by zrz               #+#    #+#             */
/*   Updated: 2025/05/28 11:47:24 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
    Harl harl;

    std::cout << "Harl complains with DEBUG:" << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;

    std::cout << "Harl complains with INFO:" << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;

    std::cout << "Harl complains with WARNING:" << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;

    std::cout << "Harl complains with ERROR:" << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;

    std::cout << "Harl complains with an unknown level:" << std::endl;
    harl.complain("SOMETHING_ELSE");
    std::cout << std::endl;
    
    return 0;
}
