# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/10 15:59:40 by jwalsh            #+#    #+#              #
#    Updated: 2018/07/12 14:37:58 by jwalsh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = avm

CXX = g++
CFLAGS = -Wall -Werror -Wextra -Wc++11-extensions -std=c++11


# Sources #

SRCS = main.cpp \
		Lexer.cpp \
		Token.cpp \
		Parser.cpp \
		IOperandFactory.cpp

HEADERS = Lexer.hpp \
		Token.hpp \
		eOperandType.hpp \
		Parser.hpp \
		IOperand.hpp \
		IOperandFactory.hpp

OBJS := $(SRCS:.cpp=.o)
SRCS_DIR := ./src
OBJS_DIR := ./obj
HEADERS := $(addprefix $(SRCS_DIR)/, $(HEADERS))
OBJS := $(addprefix $(OBJS_DIR)/, $(OBJS))
SRCS := $(addprefix $(SRCS_DIR)/, $(SRCS))
# INCLUDES := "/sgoinfre/goinfre/Perso/jwalsh/boost_1_67_0/"

# Colors #

C_NONE = \033[0m
C_BOLD = \033[1m
C_BLACK = \033[30m
C_RED = \033[31m
C_GREEN = \033[32m
C_BROWN = \033[33m
C_BLUE = \033[34m
C_MAGENTA = \033[35m
C_CYAN = \033[36m
C_GRAY = \033[37m


# Rules #

opti:
	@$(MAKE) -j all

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CFLAGS) -I$(SRCS) $< -o $@
	@echo "$(C_CYAN)$(NAME) compiled$(C_NONE)"

$(OBJS): $(SRCS) $(HEADERS)
	@$(CXX) -I$(SRCS_DIR) $(CFLAGS) -o $@ -c $<

$(OBJS): | $(OBJS_DIR)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	@-/bin/rm -rf $(OBJS_DIR)
	@echo "$(C_CYAN)$(NAME) cleaned$(C_NONE)"

fclean: clean
	@-/bin/rm -f $(NAME)
	@echo "$(C_CYAN)$(NAME) fcleaned$(C_NONE)"

re: fclean opti

.PHONY: all clean fclean re
