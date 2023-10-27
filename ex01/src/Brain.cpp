/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:12:50 by sawang            #+#    #+#             */
/*   Updated: 2023/10/27 15:07:02 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "no idea";
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain copy constructor called" << std::endl;
	// for (int i = 0; i < 100; i++)
	// 	this->_ideas[i] = copy._ideas[i];
	*this = copy;
}

Brain &Brain::operator=(const Brain &rhs)
{
	std::cout << "Brain assignation operator called" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs._ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

void	Brain::setIdea(std::string idea, int index)
{
	if (index < 0 || index > 99)
	{
		std::cout << "index out of brain"  << std::endl;
		return ;
	}
	else
		this->_ideas[index] = idea;
}

std::string	Brain::getIdea(int index) const
{
	if (index < 0 || index > 99)
	{
		std::cout << "index out of brain" << std::endl;
		return ("");
	}
	else
		return (this->_ideas[index]);
}

std::ostream &operator<<(std::ostream &out, const Brain &brain)
{
	for (int i = 0; i < 5; i++)
		out << "No." << i + 1 << " idea is " << brain.getIdea(i) << std::endl;
	return (out);
}