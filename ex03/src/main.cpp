/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:35:39 by sawang            #+#    #+#             */
/*   Updated: 2023/10/30 20:23:36 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

#include <iostream>

// class Test
// {
// 	public:
// 		Test(std::string name = "default") : _name(name)
// 		{
// 			std::cout << "Test constructor called" << std::endl;
// 		}
// 		std::string const &getName(void) const
// 		{
// 			return (this->_name);
// 		}
// 	private:
// 		std::string _name;
// };

// int main(void)
// {
// 	Test *test = new Test("name1");
// 	Test *test2 = new Test(*test);
// 	std::cout << test2->getName() << std::endl;

// 	delete test;
// 	delete test2;

// 	no harm to delete a NULL pointer, don't check for NULL before deleting
// 	Reference:
// 	https://isocpp.org/wiki/faq/freestore-mgmt#delete-handles-null
// 	int *a = NULL;
// 	delete a;

// 	Calling member function on a NULL pointer casuses undefined behavior
// 	Test *test = NULL;
// 	test->getName();
// 	return (0);
// }

namespace unequippedWrapper
{
	AMateria *unequipProxy(ICharacter &characterToUnequip, int idx)
	{
		if (idx < 0 || idx > 3)
			return (NULL);

		AMateria *tmp = NULL;
		tmp = dynamic_cast<Character &>(characterToUnequip).getMateria(idx);
		dynamic_cast<Character &>(characterToUnequip).unequip(idx);
		return (tmp);
	}
}

int main(void)
{
	AMateria *floor[50];
	for (int i = 0; i < 50; i++)
		floor[i] = NULL;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	AMateria* tmp;

	ICharacter* me = new Character("me");
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	std::cout << *(dynamic_cast<Character *>(me)) << std::endl;

	ICharacter* bob = new Character("bob");
	tmp = src->createMateria("cure");
	bob->equip(tmp);
	tmp = src->createMateria("ice");
	bob->equip(tmp);
	std::cout << *(dynamic_cast<Character *>(bob)) << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);

	//me unequip slot 1
	for (int i = 0; i < 50; i++)
	{
		if (!floor[i])
		{
			floor[i] = unequippedWrapper::unequipProxy(*me, 1);
			break;
		}
	}
	std::cout << *(dynamic_cast<Character *>(me)) << std::endl;

	ICharacter *bobCopy = new Character(*dynamic_cast<Character *>(bob));
	tmp = src->createMateria("ice");
	bobCopy->equip(tmp);
	std::cout << "bobCopy possesses :\n" << std::endl;
	std::cout << *dynamic_cast<Character *>(bobCopy) << std::endl;
	for (int i = 0; i < 50; i++)
	{
		if (!floor[i])
		{
			floor[i] = unequippedWrapper::unequipProxy(*bobCopy, 0);
			break;
		}
	}
	std::cout << "bobCopy possesses :\n" << std::endl;
	std::cout << *dynamic_cast<Character *>(bobCopy) << std::endl;

	// test what is on the floor
	std::cout << "What is on the floor:" << std::endl;
	for (int i = 0; i < 50; i++)
	{
		if (floor[i])
			std::cout << "Floor " << i << ": " << *floor[i] << std::endl;
		else
			std::cout << "Floor " << i << ": (null)" << std::endl;
	}

	//delet all unequipped materia on the floor
	for (int i = 0; i < 50; i++)
	{
		if (floor[i])
		{
			delete floor[i];
			floor[i] = NULL;
		}
	}

	delete bob;
	delete me;
	delete bobCopy;
	delete src;
	// system("leaks main");
	return (0);
}
