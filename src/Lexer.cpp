/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 16:39:34 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/14 16:49:11 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.hpp"

Lexer::Lexer() {
	std::cout << "Lexer constructor\n";
	this->error = false;
}

Lexer::Lexer( Lexer const & lexer ) {
	*this = lexer;
}

Lexer::~Lexer() {
}

void	Lexer::printTokens()
{
	std::cout << "\nPrint Tokens: \n";
	for (uint i = 0; i < this->tokens.size(); i++) {
		std::cout << "Token " << i << ": " << *this->tokens[i] << std::endl;
	}
	std::cout << "\nPrint Tokens: DONE\n";
}

std::vector<Token*>	Lexer::getTokens() {
	return this->tokens;
}

bool			Lexer::hasError() {
	return this->error;
}

Lexer &Lexer::operator=(Lexer const & rhs) {
	(void)rhs;
	return *this;
}

void	Lexer::readFile(std::string file) {
	std::ifstream	is(file);
	std::string		line;
	size_t			lineCount;
	size_t			operandsCount;

	if ( is.is_open() ) {
		lineCount = 0;
		operandsCount = 0;
		while (std::getline(is, line)) {
			++lineCount;
			printf("\n==== get line: [%s] ====\n", line.c_str());
			if (!line.size())
				continue ;
		
			std::smatch m;
			if (std::regex_match(line, m, Lexer::comment)) {
				continue ;
			}
			else if (std::regex_match(line, m, Lexer::instr, std::regex_constants::match_not_null)) {
				printf("Matched with instruction\n");
				this->tokenize(m);
				updateOperandsCount(operandsCount, this->tokens.back(), lineCount);
			}
			else {
				printf("Syntax Error [line %lu]: %s\n", lineCount, line.c_str());
				this->error = true;
			}
		}
	}
	else {
		std::cout << "error" << std::endl;
		this->error = true;
	}
}

void	Lexer::readFromSI() {
	printf("Reading from standard input\n");
	std::string input;

	while(getline(std::cin, input)) {
		std::smatch m;
		if (input.empty())
			continue ;
		if (std::regex_match(input, m, Lexer::exit)) {
			printf("Matched with exit\n");
			this->tokenize(m);
			break ;
		}
		else if (std::regex_match(input, m, Lexer::comment)) {
			continue ;
		}
		else if (std::regex_match(input, m, Lexer::instr, std::regex_constants::match_not_null)) {
			printf("Matched with instruction\n");
			this->tokenize(m);
			if (m[1] == "exit")
				break ;
		}
		else
			printf("Syntax Error\n");
	}
}

const std::string	Lexer::N = std::string(
	"\\(([-]?[0-9]+)\\)"
);
const std::string	Lexer::Z = std::string(
	"\\(([-]?[0-9]+.[0-9]+)\\)"
);
const std::string	Lexer::value = std::string(
	"(?:(?:(int8)" + Lexer::N + ")|(?:(int16)" + Lexer::N + ")|(?:(int32)" + Lexer::N + ")|(?:(float)" + Lexer::Z + ")|(?:(double)" + Lexer::Z + "))"
);
const std::regex	Lexer::instr = std::regex(
	"(push|pop|dump|assert|add|sub|mul|div|mod|print|exit)(?: )?" + Lexer::value + "?"
);
const std::regex	Lexer::comment = std::regex(
	";[^;]*[.]*"
);
const std::regex	Lexer::exit = std::regex(
	"(;;)"
);

void	Lexer::updateOperandsCount(size_t & operandsCount, Token * token, size_t & lineCount) {
	if (token->getInstruction() == eInstructionType::Push)
		++operandsCount;
	else if (token->getInstruction() == eInstructionType::Add ||
		token->getInstruction() == eInstructionType::Sub ||
		token->getInstruction() == eInstructionType::Mul ||
		token->getInstruction() == eInstructionType::Div ||
		token->getInstruction() == eInstructionType::Mod) {
		if (operandsCount < 2) {
			printf("Error [Line %lu]: not enough operands in stack to perform operation.\n", lineCount);
			this->error = true;
			delete this->tokens.back();
			this->tokens.pop_back();		
		}
		else
			--operandsCount;
	}
	else if (token->getInstruction() == eInstructionType::Pop ||
		token->getInstruction() == eInstructionType::Assert ||
		token->getInstruction() == eInstructionType::Print) {
		if (operandsCount < 1) {
			printf("Error [Line %lu]: not enough operands in stack to perform instruction.\n", lineCount);
			this->error = true;
			delete this->tokens.back();
			this->tokens.pop_back();		
		}
		else if (token->getInstruction() == eInstructionType::Pop)
			--operandsCount;
	}
}

void	Lexer::tokenize(std::smatch m) {
	std::cout << "Tokenize" << std::endl;
	std::string	instruction = "";
	std::string	type = "";
	std::string	value = "";
	uint i = 2;

	instruction = m[1].str();
	for (; i < m.size(); i++) {
		if (m[i].str().size()) {
			type = m[i].str();
			break ;
		}
	}
	++i;
	for (; i < m.size(); i++) {
		if (m[i].str().size()) {
			value = m[i].str();
			break ;
		}
	}
	if (instruction == ";;")
		instruction = "exit";
	printf("ADD TOKEN: instruction: [%s], type: [%s], value: [%s]\n", instruction.c_str(), type.c_str(), value.c_str());
	if (type.size() == 0 || value.size() == 0)
		this->tokens.push_back(new Token(instruction));
	else
		this->tokens.push_back(new Token(instruction, type, value));
}
