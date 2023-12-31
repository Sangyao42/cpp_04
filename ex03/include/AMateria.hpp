/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:13:13 by sawang            #+#    #+#             */
/*   Updated: 2023/10/30 17:17:18 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"
# include <iostream>

class ICharacter;

class AMateria
{
	public:
		AMateria();
		AMateria(std::string const &type);
		AMateria(const AMateria &copy);
		AMateria &operator=(const AMateria &rhs);
		virtual ~AMateria();

		std::string const &getType(void) const;

		virtual AMateria *clone(void) const = 0;
		virtual void use(ICharacter &target);

	protected:
		std::string _type;
};

std::ostream &operator<<(std::ostream &o, const AMateria &rhs);

#endif
