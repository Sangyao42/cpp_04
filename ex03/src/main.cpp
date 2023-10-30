/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:35:39 by sawang            #+#    #+#             */
/*   Updated: 2023/10/30 13:28:12 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "AMateria.hpp"
// #include "Character.hpp"
// #include "Cure.hpp"
// #include "Ice.hpp"
// #include "MateriaSource.hpp"

#include <iostream>

class Test
{
	public:
		std::string const &getName(void) const
		{
			return (this->_name);
		}
	private:
		std::string _name;
};

int main(void)
{
	// no harm to delete a NULL pointer, don't check for NULL before deleting
	// Reference:
	// https://isocpp.org/wiki/faq/freestore-mgmt#delete-handles-null
	// int *a = NULL;
	// delete a;

	//Calling member function on a NULL pointer casuses undefined behavior
	// Test *test = NULL;
	// test->getName();

	system("leaks a.out");
	return (0);
}