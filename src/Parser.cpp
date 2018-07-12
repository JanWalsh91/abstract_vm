/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 14:18:29 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/12 17:41:43 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

Parser::Parser() {
	printf("parser constructor\n");
	this->stackFunctions[0] = &Parser::push;
	this->stackFunctions[1] = NULL;
	this->stackFunctions[2] = NULL;
	this->stackFunctions[3] = NULL;
	this->stackFunctions[4] = NULL;
	this->stackFunctions[5] = NULL;
	this->stackFunctions[6] = NULL;
	this->stackFunctions[7] = NULL;
	this->stackFunctions[8] = NULL;
	this->stackFunctions[9] = NULL;
	this->stackFunctions[10] = NULL;
}

Parser::Parser(std::vector<Token*> tokens) : Parser::Parser() {
	this->tokens = tokens;
}

Parser::Parser( Parser const & parser ) {
	*this = parser;
}

Parser::~Parser() {
}

Parser &Parser::operator=(Parser const & rhs) {
	(void)rhs;
	return *this;
}

void	Parser::setTokens(std::vector<Token*> tokens) {
	this->tokens = tokens;
}

void	Parser::parse() {
	std::cout << "parse\n";
	if (this->tokens.size() == 0) {
		return ;
	}
	
	// execute action for each token type
	// if push new value, create operand with the IOperandFactory
	for (uint i = 0; i < this->tokens.size(); ++i) {
		// this->*stackFunction[this->tokens[i]->getInstruction()]
		printf("calling on stackFunction\n");
		// (this->*(stackFunctions[0]))
		// 	( eOperandType::Int32, "test" );
		(this->*(stackFunctions[0]))
			( this->tokens[i]->getType(), this->tokens[i]->getValue() );
		std::exit(0);
	}
	
}

void	Parser::push(eOperandType type, std::string const & value) {
	printf("push\n");
	printf("push: %s\n", value.c_str());
	this->operands.push_back(this->operandFactory.createOperand(type, value));
}