/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:58:26 by sawang            #+#    #+#             */
/*   Updated: 2023/10/25 23:01:15 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	public:
		Brain();
		Brain(const Brain &copy);
		Brain &operator=(const Brain &rhs);
		~Brain();

		void setIdea(std::string idea, int index);
		std::string getIdea(int index) const;

	private:
		std::string _ideas[100];
};

#endif