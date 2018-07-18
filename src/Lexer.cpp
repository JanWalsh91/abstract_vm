/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 16:39:34 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/18 11:50:29 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.hpp"

Lexer::Lexer() :
	error(false),
	verbose(false) {}

Lexer::Lexer(bool verbose) :
	error(false),
	verbose(verbose) {}

Lexer::Lexer( Lexer const & lexer ) {
	*this = lexer;
}

Lexer::~Lexer() {
}

void	Lexer::printTokens()
{
	if (this->verbose) {
		std::cout << "\nTokens found: \n";
		for (uint i = 0; i < this->tokens.size(); i++) {
			std::cout << *this->tokens[i] << std::endl;
		}
		std::cout << std::endl;
	}
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
	size_t			operandsCount;

	if (is.is_open()) {
		this->line = 0;
		operandsCount = 0;
		if (this->verbose)
			std::cout << "Tokenizing:" << std::endl;
		while (std::getline(is, line)) {
			++this->line;
			if (!line.size())
				continue ;
			try {
				std::smatch m;
				if (std::regex_match(line, m, Lexer::comment)) {
					continue ;
				}
				else if (std::regex_match(line, m, Lexer::instr, std::regex_constants::match_not_null)) {
					this->tokenize(m);
					updateOperandsCount(operandsCount, this->tokens.back());
				}
				else {
					throw SyntaxErrorException(line, this->line);
				}
			}
			catch (const std::exception & e) {
				std::cout << "\e[0;31mError [Line: " << this->line << "]: " << e.what() << "\e[0m" << std::endl;
				this->error = true;
			}
		}
	}
	else {
		throw ReadingFileErrorException();
		this->error = true;
	}
	try {
		if (this->tokens.size() && this->tokens.back()->getInstruction() != eInstructionType::Exit)
			throw NoExitInstructionException();
	}
	catch (const std::exception & e) {
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
		this->error = true;
	}
	if (this->error)
		throw LexerErrorException();
}

void	Lexer::readFromSI() {
	std::cout << "Reading from standard input. Type 'help'for instructions.\n";
	std::string input;
	this->line = 0;

	while(getline(std::cin, input)) {
		std::smatch m;
		++this->line;
		if (input.empty())
			continue ;
		if (std::regex_match(input, m, Lexer::exit)) {
			this->tokenize(m);
			break ;
		}
		else if (std::regex_match(input, m, Lexer::comment)) {
			continue ;
		}
		else if (std::regex_match(input, m, Lexer::instr, std::regex_constants::match_not_null)) {
			if (m[1] == "exit")
				continue ;
			this->tokenize(m);
		}
		else if (input == "help") {
			Lexer::printInstructions();
		}
		else
			printf("\e[0;31mSyntax Error\e[0m\n");
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
	"(push|pop|dump|assert|add|sub|mul|div|mod|print|exit|min|max|printnum|avg)(?: )?" + Lexer::value + "?" + "(:?[^;]*;(?:[^;].*)?)?"
	// "(push|pop|dump|assert|add|sub|mul|div|mod|print|exit|min|max|printnum|avg)(?: )?" + Lexer::value + "?" + "(?:[^;]*;[^;]*[.]*)?" // first version
);
const std::regex	Lexer::comment = std::regex(
	";(?:[^;].*)?"
	// ";[^;]+[.]*" first version
	//";(?:[^;]|\n).*" second
);
const std::regex	Lexer::exit = std::regex(
	"(;;)"
);

void	Lexer::updateOperandsCount(size_t & operandsCount, Token * token) {
	if (token->getInstruction() == eInstructionType::Push)
		++operandsCount;
	else if (token->getInstruction() == eInstructionType::Add ||
		token->getInstruction() == eInstructionType::Sub ||
		token->getInstruction() == eInstructionType::Mul ||
		token->getInstruction() == eInstructionType::Div ||
		token->getInstruction() == eInstructionType::Mod ||
		token->getInstruction() == eInstructionType::Min ||
		token->getInstruction() == eInstructionType::Max ||
		token->getInstruction() == eInstructionType::Avg) {
		if (operandsCount < 2) {
			throw NotEnoughOperandsException();

			// code never executed
			this->error = true;
			delete this->tokens.back();
			this->tokens.pop_back();		
		}
		else
			--operandsCount;
	}
	else if (token->getInstruction() == eInstructionType::Pop ||
		token->getInstruction() == eInstructionType::Assert ||
		token->getInstruction() == eInstructionType::Print ||
		token->getInstruction() == eInstructionType::Printnum) {
		if (operandsCount < 1) {
			throw NotEnoughOperandsException();

			// code never executed
			this->error = true;
			delete this->tokens.back();
			this->tokens.pop_back();		
		}
		else if (token->getInstruction() == eInstructionType::Pop)
			--operandsCount;
	}
}

void	Lexer::tokenize(std::smatch m) {
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
	// printf("ADD TOKEN: instruction: [%s], type: [%s], value: [%s]\n", instruction.c_str(), type.c_str(), value.c_str());
	if (type.size() == 0 || value.size() == 0)
		this->tokens.push_back(new Token(this->line, instruction));
	else
		this->tokens.push_back(new Token(this->line, instruction, type, value));
}

void			Lexer::printInstructions() {
	printf("\nInstructions: \n");
	printf("1. push \e[1mv\e[0m : Pushes the value \e[1mv\e[0m at the top of the stack. The value \e[1mv\e[0m must have one of the following forms:\n");
	printf("\t- int8(\e[1mn\e[0m)\n");
	printf("\t- int16(\e[1mn\e[0m)\n");
	printf("\t- int32(\e[1mn\e[0m)\n");
	printf("\t- float(\e[1mz\e[0m)\n");
	printf("\t- double(\e[1mz\e[0m)\n");
	printf("  with \e[1mn\e[0m an integer, and \e[1mz\e[0m a floating point number\n");
	printf("2. pop : Unstacks the value from the top of the stack.\n");
	printf("3. dump : Displays each value of the stack from newest to oldest.\n");
	printf("4. assert \e[1mv\e[0m: Asserts that the value at the top of the stack is equal to the one passed as parameter for this instruction.\n");
	printf("   Arithmetic operations: pops the top two elements of the stack and pushes result of the operation on those two elements on top of stack:\n");
	printf("5. add\n");
	printf("6. sub\n");
	printf("7. mul\n");
	printf("8. div\n");
	printf("9. mod\n");
	printf("10. print : Prints the value on top of the stack if it is an int8\n");
	printf("11. exit. Can also use \";;\" while reading from standard input\n\n");
}
