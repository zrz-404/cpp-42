/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:00:31 by jroseiro          #+#    #+#             */
/*   Updated: 2025/02/22 22:12:44 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// can be private / public, depending on who can access this data / change it
// a class is a blue print for objects ( a bit like a struct )
//each object has multiple attributes and methods
//attributes are characteristics
//methods are things it can do
/* example:

class Dog{  -> name of the class
	public :
		std::string	name;	-> attribute
		std::string	breed;	-> attribute -> these are just like a member of a struct, providing information,
		int age;			-> attribute	may be changeable depending on if these attributes are public or private

		void fetch(){
			std::cout << "This dog is playing fetch\n";	`-> method
		}

		void run(){
			std::cout << "This dog is running\n";	`-> method -> these behave more like a function
		}

		void eat(){
			std::cout << "This dog is eating\n";	`-> method
		}
}
*/

class PhoneBook{

} ;


int main() {


	return 0;
}