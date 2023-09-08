/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 20:46:29 by sawang            #+#    #+#             */
/*   Updated: 2023/09/08 20:58:03 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	public:
		Animal();
		~Animal();
		Animal(const Animal &copy);
		Animal &operator=(const Animal &rhs);

		std::string getType(void) const;

		virtual void makeSound(void) const;
	protected:
		std::string _type;
};
#endif