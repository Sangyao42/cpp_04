/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:04:47 by sawang            #+#    #+#             */
/*   Updated: 2023/10/27 17:50:12 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include <iostream>

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure &copy);
		Cure &operator=(const Cure &rhs);
		virtual ~Cure();

		virtual AMateria *clone(void) const;
		virtual void use(ICharacter &target);
};

#endif
