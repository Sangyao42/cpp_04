/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 20:58:39 by sawang            #+#    #+#             */
/*   Updated: 2023/10/25 16:02:53 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &copy);
		Dog &operator=(const Dog &rhs);
		virtual ~Dog();

		virtual void makeSound(void) const;

	private:
		Brain *_brain;
};
# endif