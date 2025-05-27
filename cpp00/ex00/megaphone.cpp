/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:43:00 by jroseiro          #+#    #+#             */
/*   Updated: 2025/05/21 13:24:12 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

/* original solution *
int	main(int argc, char **argv)
{
	int i = 1;
	int c = 0;

	if (argc < 2)
	return 1;
	while (argv[i])
	{
		while (argv[i][c])
		{
			if (!isupper(argv[i][c]))
			std::cout << static_cast<char>(std::toupper(argv[i][c]));
			c++;
		}
		c = 0;
		std::cout << " ";
		i++;
	}
	return 0;
}
*/

// we need to get text argument
// make it all upper case in case it is not (toupper)

/* optimization go brr */

int main(int argc, char **argv){
	if (argc < 2) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}	// if there is no argument just end program
	for (int i = 1; i < argc; ++i){
		for (int c = 0; argv[i][c] != '\0'; ++c)
			std::cout << static_cast<char>(std::toupper(argv[i][c]));
		if (i < argc - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
	return 0;
}
