/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eInstructionType.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 17:12:08 by jwalsh            #+#    #+#             */
/*   Updated: 2018/07/16 16:01:30 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EINSTRUCTION_TYPE
# define EINSTRUCTION_TYPE

# define INSTRUCTION_NUM 15

# include <string>

enum eInstructionType { Push, Assert, Print, Printnum, Add, Sub, Mul, Div, Mod, Min, Max, Avg, Pop, Dump, Exit };
const std::string eInstructionTypeNames[] { "push", "assert", "print", "printnum", "add", "sub", "mul", "div", "mod", "min", "max", "avg", "pop", "dump", "exit" };

#endif