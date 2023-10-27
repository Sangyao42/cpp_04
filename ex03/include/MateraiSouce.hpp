/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateraiSouce.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:56:11 by sawang            #+#    #+#             */
/*   Updated: 2023/10/27 20:33:09 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include <iostream>

class MateraiSource : public IMateriaSource
{
	public:
		MateraiSource();
		MateraiSource(const MateraiSource &copy);
		MateraiSource &operator=(const MateraiSource &rhs);
		virtual ~MateraiSource();

		virtual void learnMateria(AMateria *m);
		virtual AMateria *createMateria(std::string const &type);
};

#endif
