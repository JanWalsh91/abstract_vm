/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 16:39:59 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/16 14:03:27 by jwalsh           ###   ########.fr       */
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
# include "LexerErrorException.hpp"
# include "SyntaxErrorException.hpp"
# include "ReadingFileErrorException.hpp"
# include "NoExitInstructionException.hpp"

class Lexer {

	public:
		Lexer();
		Lexer(Lexer const &);
		~Lexer();
		void				readFile(std::string);
		void				readFromSI();
		void				printTokens();
		std::vector<Token*>	getTokens();
		bool				hasError();

		Lexer &operator=(Lexer const & rhs);
		
		static void			printInstructions();
	
	private:
		std::vector<Token*>	tokens;
		bool				error;

		void			tokenize(std::smatch);
		void			updateOperandsCount(size_t & operandsCount, Token * token);
		static const	std::regex exit;
		static const	std::regex comment;
		static const	std::regex instr;
		static const 	std::string value;
		static const	std::string N;
		static const	std::string Z;
		size_t			line;

};


#endif