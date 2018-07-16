/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 14:18:29 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/16 16:52:24 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

Parser::Parser() {
	// printf("parser constructor\n");
	this->stackFunctions[eInstructionType::Push] = &Parser::push;
	this->stackFunctions[eInstructionType::Assert] = &Parser::assert;
	this->stackFunctions[eInstructionType::Print] = &Parser::print;
	this->stackFunctions[eInstructionType::Printnum] = &Parser::printnum;
	this->stackFunctions[eInstructionType::Add] = &Parser::add;
	this->stackFunctions[eInstructionType::Sub] = &Parser::sub;
	this->stackFunctions[eInstructionType::Mul] = &Parser::mul;
	this->stackFunctions[eInstructionType::Div] = &Parser::div;
	this->stackFunctions[eInstructionType::Mod] = &Parser::mod;
	this->stackFunctions[eInstructionType::Min] = &Parser::min;
	this->stackFunctions[eInstructionType::Max] = &Parser::max;
	this->stackFunctions[eInstructionType::Avg] = &Parser::avg;
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
	// std::cout << "parse\n";
	if (this->tokens.size() == 0) {
		return ;
	}
	for (uint i = 0; i < this->tokens.size(); ++i) {
		try {
			(this->*(stackFunctions[this->tokens[i]->getInstruction()]))
				( this->tokens[i]->getType(), this->tokens[i]->getValue() );
		}
		catch (const std::exception & e) {
			std::cout << "\e[0;31m Error [Line " << this->tokens[i]->getLine() << "]: "
				<< e.what() << "\e[0;0m" << std::endl;
			return ;
		}
		if (this->end_parse) {
			if (i + 1 != this->tokens.size()) {
				throw ExitCalledBeforeEndOfProgramException();
			}
			break ;
		}
	}
	
}

void	Parser::push(eOperandType type, std::string const & value) {
	// printf("push\n");
	// printf("push: %s\n", value.c_str());
	this->operands.push_back(this->operandFactory.createOperand(type, value));
}

void	Parser::add(eOperandType type, std::string const & value) {
	// printf("add\n");
	(void)type;
	(void)value;

	if (this->operands.size() < 2)
		throw NotEnoughOperandsException();
	IOperand const * o1 = this->operands.back();
	this->operands.pop_back();
	IOperand const * o2 = this->operands.back();
	this->operands.pop_back();
	
	this->operands.push_back(*o1 + *o2);
	delete o1;
	delete o2;
}

void	Parser::sub(eOperandType type, std::string const & value) {
	// printf("sub\n");
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
	// printf("sub\n");
	(void)type;
	(void)value;

	if (this->operands.size() < 2)
		throw NotEnoughOperandsException();
	IOperand const * o1 = this->operands.back();
	this->operands.pop_back();
	IOperand const * o2 = this->operands.back();
	this->operands.pop_back();
	
	this->operands.push_back(*o1 * *o2);
	delete o1;
	delete o2;
}

void	Parser::div(eOperandType type, std::string const & value) {
	// printf("sub\n");
	(void)type;
	(void)value;

	if (this->operands.size() < 2)
		throw NotEnoughOperandsException();
	IOperand const * o1 = this->operands.back();
	this->operands.pop_back();
	IOperand const * o2 = this->operands.back();
	this->operands.pop_back();
	
	this->operands.push_back(*o2 / *o1);
	delete o1;
	delete o2;
}

void	Parser::mod(eOperandType type, std::string const & value) {
	// printf("sub\n");
	(void)type;
	(void)value;

	if (this->operands.size() < 2)
		throw NotEnoughOperandsException();
	IOperand const * o1 = this->operands.back();
	this->operands.pop_back();
	IOperand const * o2 = this->operands.back();
	this->operands.pop_back();
	
	this->operands.push_back(*o2 % *o1);
	delete o1;
	delete o2;
}

void	Parser::min(eOperandType type, std::string const & value) {
	printf("min\n");
	(void)type;
	(void)value;

	if (this->operands.size() < 2)
		throw NotEnoughOperandsException();
	IOperand const * o1 = this->operands.back();
	this->operands.pop_back();
	IOperand const * o2 = this->operands.back();
	this->operands.pop_back();
	double d1 = std::stof(o1->toString());
	double d2 = std::stof(o2->toString());
	this->operands.push_back(d1 <= d2 ? o1 : o2);
	
	d1 <= d2 ? delete o2 : delete o1;
}

void	Parser::max(eOperandType type, std::string const & value) {
	printf("max\n");
	(void)type;
	(void)value;

	if (this->operands.size() < 2)
		throw NotEnoughOperandsException();
	IOperand const * o1 = this->operands.back();
	this->operands.pop_back();
	IOperand const * o2 = this->operands.back();
	this->operands.pop_back();
	double d1 = std::stof(o1->toString());
	double d2 = std::stof(o2->toString());
	this->operands.push_back(d1 >= d2 ? o1 : o2);
	
	d1 >= d2 ? delete o2 : delete o1;
}


void	Parser::avg(eOperandType type, std::string const & value) {
	printf("avg\n");
	(void)type;
	(void)value;

	if (this->operands.size() < 2)
		throw NotEnoughOperandsException();
	IOperand const * o1 = this->operands.back();
	this->operands.pop_back();
	IOperand const * o2 = this->operands.back();
	this->operands.pop_back();
	// add them, divide by 2
	// get type with highest precision
	IOperand const * d = this->operandFactory.createOperand(eOperandType::Int8, "2");
	IOperand const * o3 = *o1 + *o2;
	IOperand const * o4 = *o3 / *d;

	this->operands.push_back(o4);
	
	delete d;
	delete o1;
	delete o2;
	delete o3;
}
void	Parser::assert(eOperandType type, std::string const & value) {
	// printf("assert\n");
	
	if (this->operands.size() == 0)
		throw EmptyStackException();
	// printf("back value: %s, assert value: %s\n", this->operands.back()->toString().c_str(), value.c_str());
	if (type == this->operands.back()->getType() &&
		std::atof(value.c_str()) == std::atof(this->operands.back()->toString().c_str()))
		return ;
	throw AssertionFalseException(this->operands.back(), type, value);
}

void	Parser::print(eOperandType type, std::string const & value) {
	// printf("print\n");
	(void)type;
	(void)value;

	if (this->operands.size() == 0)
		throw EmptyStackException();
	if (this->operands.back()->getType() != eOperandType::Int8)
		throw AssertionFalseException(this->operands.back(), eOperandType::Int8, this->operands.back()->toString());
	std::cout << this->operands.back()->toString() << std::endl;
}

void	Parser::printnum(eOperandType type, std::string const & value) {
	// printf("printnum\n");
	(void)type;
	(void)value;

	if (this->operands.size() == 0)
		throw EmptyStackException();
	std::cout << this->operands.back()->toString() << std::endl;
}

void	Parser::pop(eOperandType type, std::string const & value) {
	// printf("pop\n");
	(void)type;
	(void)value;

	if (this->operands.size() == 0)
		throw EmptyStackException();
	this->operands.pop_back();
}

void	Parser::dump(eOperandType type, std::string const & value) {
	// printf("dump. stack size: %lu\n", this->operands.size());
	(void)type;
	(void)value;

	for (int i = (int)this->operands.size() - 1; i >= 0 ; --i) {
		std::cout << this->operands[i]->toString() << std::endl;
	}
}

void	Parser::exit(eOperandType type, std::string const & value) {
	// printf("exit\n");
	(void)type;
	(void)value;

	this->end_parse = true;
}
