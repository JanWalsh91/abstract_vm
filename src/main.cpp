/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 16:21:45 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/12 17:37:05 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.hpp"
#include "Parser.hpp"

int    main() {
	Lexer *lexer = new Lexer("test.txt");
	// Lexer *lexer = new Lexer("test.1.txt");
	lexer->printTokens();
	std::vector<Token*> tokens = lexer->getTokens();
	
	Parser *parser = new Parser(tokens);
	
	parser->parse();
	
	return (0);
}
