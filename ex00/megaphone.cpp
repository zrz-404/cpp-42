/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:43:00 by jroseiro          #+#    #+#             */
/*   Updated: 2025/02/22 21:29:28 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctype.h>


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
	if (argc < 2)	// if there is no argument just end program
		return 1;
	for (int i = 1; i < argc; ++i){		// creating i var, stating the comparison (while i smaller than total args), increasing i (loop args)
		for (int c = 0; argv[i][c] != '\0'; ++c)	// creating c, seeing if c == \0, increasing c
			std::cout << static_cast<char>(std::toupper(argv[i][c])); //printing chars until end of arg and putting them uppercase
		if (i < argc - 1) // if we haven't reached the last argument print a space bar
			std::cout << " ";
	}
	std::cout << '\0';
	return 0;
}
