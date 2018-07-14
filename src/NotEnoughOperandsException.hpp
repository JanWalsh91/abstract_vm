/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NotEnoughOperandsException.hpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 13:08:36 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/14 15:33:54 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>

class NotEnoughOperandsException : public std::exception {
	public:
		NotEnoughOperandsException( void );
		NotEnoughOperandsException( NotEnoughOperandsException const & e );
		virtual ~NotEnoughOperandsException( void ) throw();
		NotEnoughOperandsException &    operator=( NotEnoughOperandsException const & rhs ) ;
		virtual const char* what() const throw();
};
