/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperandFactory.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 14:36:02 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/19 14:03:53 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IOperandFactory.hpp"

IOperandFactory::IOperandFactory () {
	this->getOperand[eOperandType::Int8] = &IOperandFactory::createInt8;
	this->getOperand[eOperandType::Int16] = &IOperandFactory::createInt16;
	this->getOperand[eOperandType::Int32] = &IOperandFactory::createInt32;
	this->getOperand[eOperandType::Float] = &IOperandFactory::createFloat;
	this->getOperand[eOperandType::Double] = &IOperandFactory::createDouble;
}

IOperandFactory::IOperandFactory( IOperandFactory const & iOperandFactory ) {
	*this = iOperandFactory;
}

IOperandFactory::~IOperandFactory () {}

IOperandFactory &IOperandFactory::operator=(IOperandFactory const & rhs) {
	(void)rhs;
	return *this;
}

IOperand const * IOperandFactory::createOperand(eOperandType type, std::string const & value) const {
	IOperand const * newOperand = (this->*getOperand[type])(value);
	return newOperand;
}

IOperand const * IOperandFactory::createInt8( std::string const & value ) const {
	return new class Int8(value);
}

IOperand const * IOperandFactory::createInt16( std::string const & value ) const {
	return new class Int16(value);
}

IOperand const * IOperandFactory::createInt32( std::string const & value ) const {
	return new class Int32(value);
}

IOperand const * IOperandFactory::createFloat( std::string const & value ) const {
	return new class Float(value);
}

IOperand const * IOperandFactory::createDouble( std::string const & value ) const {
	return new class Double(value);
}
