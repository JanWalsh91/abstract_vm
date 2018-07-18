/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 16:21:45 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/18 11:48:50 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.hpp"
#include "Parser.hpp"

#include <vector>
#include <string>

void	delete_tokens(std::vector<Token*> tokens) {
	for (uint i = 0; i < tokens.size(); ++i) {
		delete tokens[i];
	}
}

int    main(int ac, char **av) {

	std::vector<std::string> args;
	bool verbose = false;

	for (int i = 0; i < ac; i++) {
		if (std::string(av[i]) == "-v") {
			verbose = true;
			continue ;
		}
		args.push_back(av[i]);
	}
	if (verbose)
		ac--;

	try {
		Lexer *lexer = new Lexer(verbose);
		try {
			if (ac == 1)
				lexer->readFromSI();
			else	
				lexer->readFile(args[1]);
		} catch (const std::exception & e) {
			std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
			std::vector<Token*> tokens = lexer->getTokens();
			delete_tokens(tokens);
			delete lexer;
			return (0);
		}
		
		lexer->printTokens();
		
		std::vector<Token*> tokens = lexer->getTokens();
		
		Parser *parser = new Parser(tokens, verbose);
		parser->parse();
		delete_tokens(tokens);
		delete lexer;
		delete parser;
	} catch (const std::exception & e) {
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
	}
	return (0);
}
