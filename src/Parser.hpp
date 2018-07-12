/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 14:18:19 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/12 14:35:16 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
# define PARSER_HPP

# include <string>
# include <iostream>
# include <vector>
# include "Token.hpp"

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
		std::vector<Token*>	tokens;
};

// std::ostream& operator<<( std::ostream& os, const Parser & parser );

#endif