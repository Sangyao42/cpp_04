/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:15:34 by sawang            #+#    #+#             */
/*   Updated: 2023/10/27 18:45:08 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <iostream>

class Character : public ICharacter
{
	public:
		Character();
		Character(const std::string &name);
		Character(const Character &copy);
		Character &operator=(const Character &rhs);
		virtual ~Character();

		virtual std::string const &getName(void) const;
		virtual void equip(AMateria *m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter &target);

	private:
		std::string _name;
		AMateria *_materia[4];
};
#endif