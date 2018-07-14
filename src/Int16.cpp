/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int16.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 11:53:45 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/14 13:00:11 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Int16.hpp"

Int16::Int16() {}

Int16::Int16(std::string value) {	
	// stoi throws out of range exception if int too big
	long i = std::stol(value);
	if (SHRT_MIN <= i && i <= SHRT_MAX)
		this->value = value;
	else throw new OverflowException();
}

Int16::Int16( Int16 const & int16 ) {
	*this = int16;
}

Int16::~Int16() {}

class Int16	&Int16::operator=(Int16 const & rhs) {
	this->value = rhs.value;
	(void)rhs;
	return *this;
}

int		Int16::getPrecision() const {
	return eOperandType::Int16;
}

eOperandType Int16::getType( void ) const {
	return eOperandType::Int16;
}

/*
	Arithmetic algorithm:
	- if same type, turn string to type, add and create a new one. 
*/

IOperand const * Int16::operator+( IOperand const & rhs ) const {
	// if same type, cast string to type, add together, and 
	if (this->getPrecision() == rhs.getPrecision()) {
		long res = static_cast<long>(std::atol(this->toString().c_str())) +
			static_cast<long>(std::atol(rhs.toString().c_str()));
		if (std::numeric_limits<short>::min() <= res && res <= std::numeric_limits<short>::max())
			return IOperandFactory().createOperand(eOperandType::Int16, std::to_string(res));
		throw new OverflowException();
	}
	// if not same type, determine final type based on precison
	eOperandType	newType = static_cast<eOperandType>(std::max(this->getPrecision(), rhs.getPrecision()));
	
	// create new IOperands with the right type.
	IOperand const * o1 = IOperandFactory().createOperand(newType, this->toString());
	IOperand const * o2 = IOperandFactory().createOperand(newType, rhs.toString());
	// add (now same type)
	IOperand const * result = *o1 + *o2;
	delete o1;
	delete o2;
	return result;
}

IOperand const * Int16::operator-( IOperand const & rhs ) const {
	if (this->getPrecision() == rhs.getPrecision()) {
		long res = static_cast<long>(std::atol(this->toString().c_str())) -
			static_cast<long>(std::atol(rhs.toString().c_str()));
		if (std::numeric_limits<short>::min() <= res && res <= std::numeric_limits<short>::max())
			return IOperandFactory().createOperand(eOperandType::Int16, std::to_string(res));
		throw new OverflowException();
	}
	eOperandType	newType = static_cast<eOperandType>(std::max(this->getPrecision(), rhs.getPrecision()));
	IOperand const * o1 = IOperandFactory().createOperand(newType, this->toString());
	IOperand const * o2 = IOperandFactory().createOperand(newType, rhs.toString());
	IOperand const * result = *o1 - *o2;
	delete o1;
	delete o2;
	return result;
}

IOperand const * Int16::operator*( IOperand const & rhs ) const {
	if (this->getPrecision() == rhs.getPrecision()) {
		long res = static_cast<long>(std::atol(this->toString().c_str())) *
			static_cast<long>(std::atol(rhs.toString().c_str()));
		if (std::numeric_limits<short>::min() <= res && res <= std::numeric_limits<short>::max())
			return IOperandFactory().createOperand(eOperandType::Int16, std::to_string(res));
		throw new OverflowException();
	}
	eOperandType	newType = static_cast<eOperandType>(std::max(this->getPrecision(), rhs.getPrecision()));
	IOperand const * o1 = IOperandFactory().createOperand(newType, this->toString());
	IOperand const * o2 = IOperandFactory().createOperand(newType, rhs.toString());
	IOperand const * result = *o1 * *o2;
	delete o1;
	delete o2;
	return result;
}

IOperand const * Int16::operator/( IOperand const & rhs ) const {
	if (this->getPrecision() == rhs.getPrecision()) {
		if (static_cast<long>(std::atol(rhs.toString().c_str())) == 0)
			throw new DivideByZeroException();
		long res = static_cast<long>(std::atol(this->toString().c_str())) /
			static_cast<long>(std::atol(rhs.toString().c_str()));
		if (std::numeric_limits<short>::min() <= res && res <= std::numeric_limits<short>::max())
			return IOperandFactory().createOperand(eOperandType::Int16, std::to_string(res));
		throw new OverflowException();
	}
	eOperandType	newType = static_cast<eOperandType>(std::max(this->getPrecision(), rhs.getPrecision()));
	IOperand const * o1 = IOperandFactory().createOperand(newType, this->toString());
	IOperand const * o2 = IOperandFactory().createOperand(newType, rhs.toString());
	IOperand const * result = *o1 / *o2;
	delete o1;
	delete o2;
	return result;
}

IOperand const * Int16::operator%( IOperand const & rhs ) const {
	if (this->getPrecision() == rhs.getPrecision()) {
		if (static_cast<long>(std::atol(rhs.toString().c_str())) == 0)
			throw new DivideByZeroException();
		long res = static_cast<long>(std::atol(this->toString().c_str())) %
			static_cast<long>(std::atol(rhs.toString().c_str()));
		if (std::numeric_limits<short>::min() <= res && res <= std::numeric_limits<short>::max())
			return IOperandFactory().createOperand(eOperandType::Int16, std::to_string(res));
		throw new OverflowException();
	}
	eOperandType	newType = static_cast<eOperandType>(std::max(this->getPrecision(), rhs.getPrecision()));
	if (newType > eOperandType::Float)
		throw new OperandsNotIntegersException();
	IOperand const * o1 = IOperandFactory().createOperand(newType, this->toString());
	IOperand const * o2 = IOperandFactory().createOperand(newType, rhs.toString());
	IOperand const * result = *o1 % *o2;
	delete o1;
	delete o2;
	return result;
}

std::string const & Int16::toString( void ) const {
	return this->value;
}
