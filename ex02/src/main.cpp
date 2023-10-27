/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:20:14 by sawang            #+#    #+#             */
/*   Updated: 2023/10/27 16:05:25 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

#include <iostream>

int main()
{
	// AAnimal testAnimal;
	//Error: Abstract class AAnimal cannot be instantiated

	AAnimal *aAnimals[10];
	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
			aAnimals[i] = new Dog();
		else
			aAnimals[i] = new Cat();
		// std::cout << animals[i]->getType() << " makes ";
		// animals[i]->makeSound();
	}

	Dog *dog = dynamic_cast<Dog *>(aAnimals[0]);
	if (dog)
		std::cout << "dog's idea: \n" << *(dog->getBrain()) << std::endl;
	Cat *cat = dynamic_cast<Cat *>(aAnimals[5]);
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

	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
		delete aAnimals[i];

	return 0;
}