/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:43:00 by jroseiro          #+#    #+#             */
/*   Updated: 2025/02/19 21:11:34 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctype.h>

int	main(int argc, char **argv)
{
	int i = 0;

	if (argv[i])
	std::cout << "text goes in here.";
	return 0;
}

// we need to get text argument
// make it all upper case in case it is not (toupper)