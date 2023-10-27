/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:16:11 by sawang            #+#    #+#             */
/*   Updated: 2023/10/27 17:51:21 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include <iostream>

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice &copy);
		Ice &operator=(const Ice &rhs);
		virtual ~Ice();

		virtual AMateria *clone(void) const;
		virtual void use(ICharacter &target);
};

#endif
