/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NoExitInstructionException.hpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 13:08:36 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/16 14:03:06 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>

class NoExitInstructionException : public std::exception {
	public:
		NoExitInstructionException( void );
		NoExitInstructionException( NoExitInstructionException const & e );
		virtual ~NoExitInstructionException( void ) throw();
		NoExitInstructionException &    operator=( NoExitInstructionException const & rhs ) ;
		virtual const char* what() const throw();
};
