/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssertionFalseException.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 13:08:36 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/14 13:08:38 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>

class AssertionFalseException : public std::exception {
	public:
		AssertionFalseException( void );
		AssertionFalseException( AssertionFalseException const & e );
		virtual ~AssertionFalseException( void ) throw();
		AssertionFalseException &    operator=( AssertionFalseException const & rhs ) ;
		virtual const char* what() const throw();
};
