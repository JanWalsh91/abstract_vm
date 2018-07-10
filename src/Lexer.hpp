/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 16:39:59 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/10 17:10:44 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_HPP
# define LEXER_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <sstream>

class Lexer {

	public:
		Lexer(std::string);
		Lexer(Lexer const &);
		~Lexer();

	Lexer &operator=(Lexer const & rhs);
	
	private:
		Lexer();
		void	readFile(std::string);

};

#endif