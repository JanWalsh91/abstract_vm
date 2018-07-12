/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 16:21:45 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/12 13:04:17 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.hpp"

int    main() {
	Lexer *lexer = new Lexer("test.txt");
	lexer->printTokens();
	return (0);
}
