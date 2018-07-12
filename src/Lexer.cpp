/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 16:39:34 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/12 13:43:45 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.hpp"

Lexer::Lexer() {
	std::cout << "Lexer constructor\n";
}

Lexer::Lexer(std::string file) {
	this->readFile(file);
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
}

Lexer &Lexer::operator=(Lexer const & rhs) {
	(void)rhs;
	return *this;
}

void	Lexer::readFile(std::string file) {
	std::ifstream is(file);
	std::string line;
	
	if ( is.is_open() ) {
		while (std::getline(is, line)) {
			printf("\n==== get line: [%s] ====\n", line.c_str());
			if (!line.size())
				continue ;
		
			std::smatch m;
			// printf("instruction regex: %s\n", ("(push|pop|dump|assert|add|sub|mul|div|mod|print|exit) (?:" + Lexer::value + ")").c_str());
			if (std::regex_match(line, m, Lexer::exit)) {
				printf("Matched with exit\n");
				this->tokenize(m);
			}
			else if (std::regex_match(line, m, Lexer::comment)) {
				printf("Matched with comment\n");
				// this->tokenize(m);
			}
			else if (std::regex_match(line, m, Lexer::instr, std::regex_constants::match_not_null)) {
				printf("Matched with instruction\n");
				this->tokenize(m);
			}
			else {
				printf("Syntax error: %s\n", line.c_str());
				return ;
			}
		}
	}
	else {
		std::cout << "error" << std::endl;
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
	";;"
);

void	Lexer::tokenize(std::smatch m)
{
	std::cout << "Tokenize" << std::endl;
	// for (uint i = 1; i < m.size(); i++) {
	// 	printf("match[%-2d]: [%-10s], \tsize: %lu\n", i, m[i].str().c_str(), m[i].str().size());
	// }
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
	printf("ADD TOKEN: instruction: [%s], type: [%s], value: [%s]\n", instruction.c_str(), type.c_str(), value.c_str());
	if (type.size() == 0 || value.size() == 0)
		this->tokens.push_back(new Token(instruction));
	else
		this->tokens.push_back(new Token(instruction, type, value));
}
