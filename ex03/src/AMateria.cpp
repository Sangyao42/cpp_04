/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:51:58 by sawang            #+#    #+#             */
/*   Updated: 2023/10/30 17:17:45 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria()
{
}

AMateria::AMateria(std::string const &type) : _type(type)
{
}

AMateria::AMateria(const AMateria &copy)
{
	*this = copy;
}

AMateria &AMateria::operator=(const AMateria &rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

AMateria::~AMateria(void)
{
}

std::string const &AMateria::getType(void) const
{
	return (this->_type);
}

void AMateria::use(ICharacter &target)
{
	std::cout << "* does nothing at " << target.getName() << " *" << std::endl;
}

std::ostream &operator<<(std::ostream &o, const AMateria &rhs)
{
	o << rhs.getType();
	return (o);
}