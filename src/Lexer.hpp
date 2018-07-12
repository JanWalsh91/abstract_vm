/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 16:39:59 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/12 14:16:26 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_HPP
# define LEXER_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <sstream>
# include <iterator>
# include <regex>
# include <vector>
# include "Token.hpp"

class Lexer {

	public:
		Lexer(std::string);
		Lexer(Lexer const &);
		~Lexer();
		void				printTokens();
		std::vector<Token*>	getTokens();

		Lexer &operator=(Lexer const & rhs);
	
	private:
		std::vector<Token*>	tokens;

		Lexer();
		void			readFile(std::string);
		void			tokenize(std::smatch);
		// static bool		matchRegex(std::string, std::regex, std::smatch *);
		static const	std::regex exit;
		static const	std::regex comment;
		static const	std::regex instr;
		static const 	std::string value;
		static const	std::string N;
		static const	std::string Z;

};


#endif