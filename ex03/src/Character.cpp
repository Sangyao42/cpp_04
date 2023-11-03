/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:39:48 by sawang            #+#    #+#             */
/*   Updated: 2023/11/03 17:03:21 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character() : _name("default")
{
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
}

Character::Character(const std::string &name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
}

Character::Character(const Character &copy) : _name(copy._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (copy._materia[i])
			this->_materia[i] = copy._materia[i]->clone();
		else
			this->_materia[i] = NULL;
	}
}

Character &Character::operator=(const Character &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			delete this->_materia[i];
			this->_materia[i] = NULL;
			if (rhs._materia[i])
				this->_materia[i] = rhs._materia[i]->clone();
		}
		this->_name = rhs._name;
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		delete this->_materia[i];
		this->_materia[i] = NULL;
	}
}

std::string const &Character::getName(void) const
{
	return (this->_name);
}

void	Character::equip(AMateria *m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!this->_materia[i])
		{
			this->_materia[i] = m;
			return ;
		}
	}
	delete m;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		this->_materia[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && this->_materia[idx])
		this->_materia[idx]->use(target);
}

AMateria *Character::getMateria(int idx) const
{
	if (idx >= 0 && idx < 4)
		return (this->_materia[idx]);
	return (NULL);
}

std::ostream &operator<<(std::ostream &o, const Character &rhs)
{
	o << rhs.getName() << " is equipped with: " << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (rhs.getMateria(i))
			o << "Slot " << i << ": " << *rhs.getMateria(i) << std::endl;
		else
			o << "Slot " << i << ": (null)" << std::endl;
	}
	return (o);
}

// test scope
// {
// 	Materia   *m = new Ice();
// 	{
// 		Character c;

// 		c.equip(m);
// 	}
// 	delete m;
// }