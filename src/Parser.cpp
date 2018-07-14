/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 14:18:29 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/14 15:45:15 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

Parser::Parser() {
	printf("parser constructor\n");
	this->stackFunctions[eInstructionType::Push] = &Parser::push;
	this->stackFunctions[eInstructionType::Assert] = &Parser::assert;
	this->stackFunctions[eInstructionType::Print] = &Parser::print;
	this->stackFunctions[eInstructionType::Add] = &Parser::add;
	this->stackFunctions[eInstructionType::Sub] = &Parser::sub;
	this->stackFunctions[eInstructionType::Mul] = &Parser::mul;
	this->stackFunctions[eInstructionType::Div] = &Parser::div;
	this->stackFunctions[eInstructionType::Mod] = &Parser::mod;
	this->stackFunctions[eInstructionType::Pop] = &Parser::pop;
	this->stackFunctions[eInstructionType::Dump] = &Parser::dump;
	this->stackFunctions[eInstructionType::Exit] = &Parser::exit;
	this->end_parse = false;
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
		// printf("calling on stackFunction\n");
		// (this->*(stackFunctions[0]))
		// 	( eOperandType::Int32, "test" );
		(this->*(stackFunctions[this->tokens[i]->getInstruction()]))
			( this->tokens[i]->getType(), this->tokens[i]->getValue() );
		if (this->end_parse) {
			if (i + 1 != this->tokens.size()) {
				throw new ExitCalledBeforeEndOfProgramException();
			}
			break ;
		}
	}
	
}

void	Parser::push(eOperandType type, std::string const & value) {
	printf("push\n");
	printf("push: %s\n", value.c_str());
	this->operands.push_back(this->operandFactory.createOperand(type, value));
}

void	Parser::dump(eOperandType type, std::string const & value) {
	printf("dump. stack size: %lu\n", this->operands.size());
	(void)type;
	(void)value;

	for (uint i = 0; i < this->operands.size(); ++i) {
		std::cout << this->operands[i]->toString() << std::endl;
	}
}

void	Parser::add(eOperandType type, std::string const & value) {
	printf("add\n");
	(void)type;
	(void)value;

	if (this->operands.size() < 2)
		throw new NotEnoughOperandsException();
	IOperand const * o1 = this->operands.back();
	this->operands.pop_back();
	IOperand const * o2 = this->operands.back();
	this->operands.pop_back();
	
	this->operands.push_back(*o1 + *o2);
	delete o1;
	delete o2;
}

void	Parser::sub(eOperandType type, std::string const & value) {
	printf("sub\n");
	(void)type;
	(void)value;

	IOperand const * o1 = this->operands.back();
	this->operands.pop_back();
	IOperand const * o2 = this->operands.back();
	this->operands.pop_back();
	
	this->operands.push_back(*o2 - *o1);
	delete o1;
	delete o2;
}

void	Parser::mul(eOperandType type, std::string const & value) {
	printf("sub\n");
	(void)type;
	(void)value;

	if (this->operands.size() < 2)
		throw new NotEnoughOperandsException();
	IOperand const * o1 = this->operands.back();
	this->operands.pop_back();
	IOperand const * o2 = this->operands.back();
	this->operands.pop_back();
	
	this->operands.push_back(*o1 * *o2);
	delete o1;
	delete o2;
}

void	Parser::div(eOperandType type, std::string const & value) {
	printf("sub\n");
	(void)type;
	(void)value;

	if (this->operands.size() < 2)
		throw new NotEnoughOperandsException();
	IOperand const * o1 = this->operands.back();
	this->operands.pop_back();
	IOperand const * o2 = this->operands.back();
	this->operands.pop_back();
	
	this->operands.push_back(*o2 / *o1);
	delete o1;
	delete o2;
}

void	Parser::mod(eOperandType type, std::string const & value) {
	printf("sub\n");
	(void)type;
	(void)value;

	if (this->operands.size() < 2)
		throw new NotEnoughOperandsException();
	IOperand const * o1 = this->operands.back();
	this->operands.pop_back();
	IOperand const * o2 = this->operands.back();
	this->operands.pop_back();
	
	this->operands.push_back(*o2 % *o1);
	delete o1;
	delete o2;
}

void	Parser::assert(eOperandType type, std::string const & value) {
	printf("assert\n");
	
	if (this->operands.size() == 0)
		throw new EmptyStackException();
	printf("back value: %s, assert value: %s\n", this->operands.back()->toString().c_str(), value.c_str());
	if (type == this->operands.back()->getType() &&
		std::atof(value.c_str()) == std::atof(this->operands.back()->toString().c_str()))
		return ;
	throw new AssertionFalseException();
}

void	Parser::print(eOperandType type, std::string const & value) {
	printf("print\n");
	(void)type;
	(void)value;

	if (this->operands.size() == 0)
		throw new EmptyStackException();
	std::cout << this->operands.back()->toString() << std::endl;
}

void	Parser::pop(eOperandType type, std::string const & value) {
	printf("pop\n");
	(void)type;
	(void)value;

	if (this->operands.size() == 0)
		throw new EmptyStackException();
	this->operands.pop_back();
}

void	Parser::exit(eOperandType type, std::string const & value) {
	printf("exit\n");
	(void)type;
	(void)value;

	this->end_parse = true;
}
