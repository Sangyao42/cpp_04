/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:20:14 by sawang            #+#    #+#             */
/*   Updated: 2023/10/27 17:46:12 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

#include <iostream>

int main()
{

	Animal *animals[10];
	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		// std::cout << animals[i]->getType() << " makes ";
		// animals[i]->makeSound();
	}

	Dog *dog = dynamic_cast<Dog *>(animals[0]);
	if (dog)
		std::cout << "dog's idea: \n" << *(dog->getBrain()) << std::endl;
	Cat *cat = dynamic_cast<Cat *>(animals[5]);
	if (cat)
		std::cout << "cat's idea: \n"  << *(cat->getBrain()) << std::endl;

	dog->getBrain()->setIdea("I want to go out", 0);
	cat->getBrain()->setIdea("I want to sleep", 0);
	std::cout << "dog's idea: \n" <<  *(dog->getBrain()) << std::endl;
	std::cout << "cat's idea: \n" << *(cat->getBrain()) << std::endl;

	*dog->getBrain() = *cat->getBrain();
	std::cout << "dog's idea: \n" << *(dog->getBrain()) << std::endl;
	std::cout << "cat's idea: \n" << *(cat->getBrain()) << std::endl;

	dog->getBrain()->setIdea("I want to go out", 1);
	Brain floatingBrain(*dog->getBrain());
	std::cout << "floatingBrain's idea: \n" << floatingBrain << std::endl;

	// animals[0] = animals[5];
	//error: segmentation fault
	// when destructor, the animals[5] is already deleted and animals[0] is pointing to the same address
	// but the brain in animals[0] is not deleted because of object slicing
	// definitely, the brain in animals[0] is a dangling pointer
	// std::cout << "animals[0] is now a " << animals[0]->getType() << std::endl;

	// Dog *dog2 = dynamic_cast<Dog *>(animals[0]);
	// if (dog2)
	// 	std::cout << "dog2's idea: \n" << *(dog->getBrain()) << std::endl;
	// else
	// {
	// 	std::cout << "animals[0] is not a dog" << std::endl;
	// 	std::cout << "the dynamic casting failed" << std::endl;
	// }

	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
		delete animals[i];
	// system("leaks main");
	return 0;
}