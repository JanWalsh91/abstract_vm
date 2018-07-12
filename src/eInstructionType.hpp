/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eInstructionType.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 17:12:08 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/12 17:33:53 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EINSTRUCTION_TYPE
# define EINSTRUCTION_TYPE

# include <string>

enum eInstructionType { Push, Assert, Print, Add, Sub, Mul, Div, Mod, Pop, Dump, Exit };
const std::string eInstructionTypeNames[] { "push", "assert", "print", "add", "sub", "mul", "div", "mod", "pop", "dump", "exit" };

#endif