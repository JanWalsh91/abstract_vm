/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 14:18:19 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/14 15:45:55 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
# define PARSER_HPP

# include <string>
# include <iostream>
# include <vector>

# include "Token.hpp"
# include "IOperandFactory.hpp"
# include "AssertionFalseException.hpp"
# include "NotEnoughOperandsException.hpp"
# include "EmptyStackException.hpp"
# include "ExitCalledBeforeEndOfProgramException.hpp"

class Parser {

	public:
		Parser();
		Parser(std::vector<Token*> tokens);
		Parser(Parser const &);
		~Parser();

		Parser &operator=(Parser const & rhs);
		
		void	setTokens(std::vector<Token*>);
		void	parse();
		
	private:
		std::vector<Token*>				tokens;
		std::vector<IOperand const *>	operands;
		IOperandFactory					operandFactory;
		bool							end_parse;

		// stack functions
		void	push(eOperandType, std::string const &);
		void	assert(eOperandType, std::string const &);
		void	print(eOperandType, std::string const &);
		
		void	add(eOperandType, std::string const &);
		void	sub(eOperandType, std::string const &);
		void	mul(eOperandType, std::string const &);
		void	div(eOperandType, std::string const &);
		void	mod(eOperandType, std::string const &);
		
		void	pop(eOperandType, std::string const &);
		void	dump(eOperandType, std::string const &);
		void	exit(eOperandType, std::string const &);

		typedef void (Parser::*stackFunction) (eOperandType, std::string const &);
		stackFunction stackFunctions[11];
};

// std::ostream& operator<<( std::ostream& os, const Parser & parser );

#endif