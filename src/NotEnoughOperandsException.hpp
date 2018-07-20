/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NotEnoughOperandsException.hpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 13:08:36 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/18 15:01:59 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NOT_ENOUGH_OPERANDS_EXCEPTION_HPP
# define NOT_ENOUGH_OPERANDS_EXCEPTION_HPP

# include <exception>

class NotEnoughOperandsException : public std::exception {
	public:
		NotEnoughOperandsException( void );
		NotEnoughOperandsException( NotEnoughOperandsException const & e );
		virtual ~NotEnoughOperandsException( void ) throw();
		NotEnoughOperandsException &    operator=( NotEnoughOperandsException const & rhs ) ;
		virtual const char* what() const throw();
};

#endif
