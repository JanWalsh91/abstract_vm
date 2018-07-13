/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int32.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 15:57:53 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/13 16:41:46 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Int32.hpp"

Int32::Int32() {}

Int32::Int32(std::string value) {
	// stoi throws out of range exception if int too big
	// should maybe check length and do it throw exception yourself.
	long i = std::stol(value);
	if (INT_MIN <= i && i <= INT_MAX)
		this->value = value;
	else throw new OverflowException();
}

Int32::Int32( Int32 const & int32 ) {
	*this = int32;
}

Int32::~Int32() {}

class Int32	&Int32::operator=(Int32 const & rhs) {
	this->value = rhs.value;
	return *this;
}

int		Int32::getPrecision() const {
	return eOperandType::Int32;
}

eOperandType Int32::getType( void ) const {
	return eOperandType::Int32;
}

IOperand const * Int32::operator+( IOperand const & rhs ) const {
	if (this->getPrecision() == rhs.getPrecision()) {
		long res = static_cast<long>(std::atol(this->toString().c_str())) +
			static_cast<long>(std::atol(rhs.toString().c_str()));
		if (INT_MIN <= res && res <= INT_MAX)
			return IOperandFactory().createOperand(eOperandType::Int32, std::to_string(res));
		throw new OverflowException();
	}
	eOperandType	newType = static_cast<eOperandType>(std::max(this->getPrecision(), rhs.getPrecision()));
	IOperand const * o1 = IOperandFactory().createOperand(newType, this->toString());
	IOperand const * o2 = IOperandFactory().createOperand(newType, rhs.toString());
	IOperand const * result = *o1 + *o2;
	delete o1;
	delete o2;
	return result;
}

IOperand const * Int32::operator-( IOperand const & rhs ) const {
	if (this->getPrecision() == rhs.getPrecision()) {
		long res = static_cast<long>(std::atol(this->toString().c_str())) -
			static_cast<long>(std::atol(rhs.toString().c_str()));
		if (INT_MIN <= res && res <= INT_MAX)
			return IOperandFactory().createOperand(eOperandType::Int32, std::to_string(res));
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

IOperand const * Int32::operator*( IOperand const & rhs ) const {
	if (this->getPrecision() == rhs.getPrecision()) {
		long res = static_cast<long>(std::atol(this->toString().c_str())) *
			static_cast<long>(std::atol(rhs.toString().c_str()));
		if (INT_MIN <= res && res <= INT_MAX)
			return IOperandFactory().createOperand(eOperandType::Int32, std::to_string(res));
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

IOperand const * Int32::operator/( IOperand const & rhs ) const {
	if (this->getPrecision() == rhs.getPrecision()) {
		if (static_cast<long>(std::atol(rhs.toString().c_str())) == 0)
			throw new DivideByZeroException();
		long res = static_cast<long>(std::atol(this->toString().c_str())) /
			static_cast<long>(std::atol(rhs.toString().c_str()));
		if (INT_MIN <= res && res <= INT_MAX)
			return IOperandFactory().createOperand(eOperandType::Int32, std::to_string(res));
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

IOperand const * Int32::operator%( IOperand const & rhs ) const {
	if (this->getPrecision() == rhs.getPrecision()) {
		if (static_cast<long>(std::atol(rhs.toString().c_str())) == 0)
			throw new DivideByZeroException();
		long res = static_cast<long>(std::atol(this->toString().c_str())) %
			static_cast<long>(std::atol(rhs.toString().c_str()));
		if (INT_MIN <= res && res <= INT_MAX)
			return IOperandFactory().createOperand(eOperandType::Int32, std::to_string(res));
		throw new OverflowException();
	}
	eOperandType	newType = static_cast<eOperandType>(std::max(this->getPrecision(), rhs.getPrecision()));
	IOperand const * o1 = IOperandFactory().createOperand(newType, this->toString());
	IOperand const * o2 = IOperandFactory().createOperand(newType, rhs.toString());
	IOperand const * result = *o1 % *o2;
	delete o1;
	delete o2;
	return result;
}

std::string const & Int32::toString( void ) const {
	return this->value;
}