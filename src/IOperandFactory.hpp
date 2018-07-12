/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperandFactory.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 14:34:54 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/12 15:49:41 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOPERAND_FACTORY_HPP
# define IOPERAND_FACTORY_HPP

# include "eOperandType.hpp"
# include "IOperand.hpp"

class IOperandFactory {

	public:
		IOperandFactory();
		IOperandFactory(IOperandFactory const &);
		~IOperandFactory();

		IOperandFactory &operator=(IOperandFactory const & rhs);	

		IOperand const * createOperand(eOperandType type, std::string const & value) const;

	private:
		IOperand const * createInt8( std::string const & value ) const;
		IOperand const * createInt16( std::string const & value ) const;
		IOperand const * createInt32( std::string const & value ) const;
		IOperand const * createFloat( std::string const & value ) const;
		IOperand const * createDouble( std::string const & value ) const;

		typedef IOperand const * (IOperandFactory::*operandGetter) (std::string const &) const;
		operandGetter getOperand[5];

};

#endif