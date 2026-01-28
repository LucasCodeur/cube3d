# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/18 12:51:21 by lud-adam          #+#    #+#              #
#    Updated: 2025/10/29 15:23:45 by lud-adam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re debug
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
DEPENDANCIES = -MMD -MP
NAME = MommyWhenIgrowUpIwantToBeAbureaucrat!
# Debugging flags
CFLAGS_DEBUG = -Wall -Wextra -pthread -g3 -D DEBUG=1

P_SRC = src/
P_OBJ = .obj/
P_INC = inc/

SRC = main.cpp \
	  Bureaucrat.cpp \

SRCS = \
	$(addprefix $(P_SRC), $(SRC)) \

OBJS = $(subst $(P_SRC), $(P_OBJ), $(SRCS:.cpp=.o))

Color_Off=\033[0m
Green=\033[0;32m
Red=\033[0;31m
Cyan=\033[0;36m

all: $(NAME)

$(NAME): $(OBJS) $(INCS)
	@$(CC) $(DEPENDANCIES) $(CFLAGS) -o $@ $(OBJS) -I $(P_INC) && \
	echo "$(Green)Creating executable $@$(Color_Off)" || \
	echo "$(Red)Error creating $@$(Color_Off)"

$(P_OBJ)%.o: $(P_SRC)%.cpp $(INCS)
	@mkdir -p $(dir $@)
	@$(CC) $(DEPENDANCIES) $(CFLAGS) -I $(P_INC) -c $< -o $@ && \
	echo "$(Cyan)Compiling $<$(Color_Off)" || \
	echo "$(Red)Error compiling $<$(Color_Off)"

clean:
	rm -rf $(P_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

#############################################################################################
#                                                                                           #
#                                           DEBUG                                           #
#                                                                                           #
#############################################################################################
# Debugging rules
debug:
	@$(MAKE) $(NAME) CFLAGS="$(CFLAGS_DEBUG)"
