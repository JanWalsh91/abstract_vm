/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExitCalledBeforeEndOfProgramException.hpp          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 13:08:36 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/14 15:45:49 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>

class ExitCalledBeforeEndOfProgramException : public std::exception {
	public:
		ExitCalledBeforeEndOfProgramException( void );
		ExitCalledBeforeEndOfProgramException( ExitCalledBeforeEndOfProgramException const & e );
		virtual ~ExitCalledBeforeEndOfProgramException( void ) throw();
		ExitCalledBeforeEndOfProgramException &    operator=( ExitCalledBeforeEndOfProgramException const & rhs ) ;
		virtual const char* what() const throw();
};
