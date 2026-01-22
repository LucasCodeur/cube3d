# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/14 14:47:47 by lud-adam          #+#    #+#              #
#    Updated: 2025/12/29 15:46:09 by lud-adam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all fclean re bonus clean-bin clean-obj debug debug-cc debug-print
CC = cc
CFLAGS = -Wextra -Wall -Werror
CC_DEBUG = gcc
DEPENDANCIES = -MMD -MP
NO_DIR = --no-print-directory

MAKE := $(MAKE) -j $(NO_DIR)
NAME = libmath.a

# Debugging flags
CFLAGS_DEBUG = -Wall -Wextra -g3 -D DEBUG=1
CC_DEBUG = clang
CC_DEBUG_CFLAGS = -g3 -D DEBUG=1 -Weverything -Wno-padded -pedantic -O2 -Wwrite-strings -Wconversion -Wno-suggest-override -Wno-suggest-destructor-override -Wno-incompatible-pointer-types-discards-qualifiers -Wno-disabled-macro-expansion
#############################################################################################
#                                                                                           #
#                                         DIRECTORIES                                       #
#                                                                                           #
#############################################################################################
# Source directories
P_SRC = src/
P_INC = inc/
P_OBJ = .obj/
P_VECTOR = $(P_SRC)vector/
P_MATRICE = $(P_SRC)matrice/

#############################################################################################
#                                                                                           #
#                                           FILES                                           #
#                                                                                           #
#############################################################################################

SRC = \
 	utils_maths.c \

SRC_VECTOR = \
	vector.c \
	power_vector.c \
	add_vector_operation.c \
	divide_vector_operation.c \
	multiply_vector_operation.c \
	subtract_vector_operation.c \
	normalize_vector.c \
	scalar_operation.c \
	construct_vector.c \
	magnitude_vector.c \
	utils.c \

SRC_MATRICE = \
	matrice.c \

LIBS = \

#############################################################################################
#                                                                                           #
#                                        MANIPULATION                                       #
#                                                                                           #
#############################################################################################
SRCS =	\
	$(addprefix $(P_SRC), $(SRC)) \
	$(addprefix $(P_VECTOR), $(SRC_VECTOR)) \
	$(addprefix $(P_MATRICE), $(SRC_MATRICE)) \
		
# List of object files (redirect to P_OBJ)
OBJS =  \
	$(subst $(P_SRC), $(P_OBJ), $(SRCS:.c=.o)) \

# List of depedencies
DEPS = $(OBJS:%.o=%.d)

#############################################################################################
#                                                                                           #
#                                          RULES                                            #
#                                                                                           #
#############################################################################################
all:
	$(MAKE) $(NAME)

# Custom rule to compilate all .c with there path
$(P_OBJ)%.o: $(P_SRC)%.c $(P_INC)
	@mkdir -p $(dir $@)
	@if $(CC) $(CFLAGS) $(DEPENDANCIES) -I $(P_INC) -c $< -o $@; then \
		echo "$(Cyan)Compiling $<$(Color_Off)"; \
	else \
		echo "$(Red)Error creating $@$(Color_Off)"; \
	fi

$(NAME): $(OBJS) 
	ar -rcs $(NAME) $^

$(P_OBJ)%.o: %.c $(P_INC)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(DEPENDANCIES) -I $(P_INC) -c $< -o $@

#############################################################################################
#                                                                                           #
#                                      Other RULES                                          #
#                                                                                           #
#############################################################################################
# Rules for clean up
clean:
	rm -rfd $(P_OBJ)
	rm -rfd $(NAME)
	rm -rfd $(OBJS)
	rm -rfd $(DEPS)

clean-bin:
	rm -f $(NAME)

clean-obj:
	@$(MAKE) clean

fclean:
	@$(MAKE) clean-obj
	@$(MAKE) clean-bin

re:
	@$(MAKE) fclean
	@$(MAKE) all

# Aliases
clear: clean
fclear: fclean
flcean: fclean
flcear: fclean

#############################################################################################
#                                                                                           #
#                                           DEBUG                                           #
#                                                                                           #
#############################################################################################
# Debugging rules
debug:
	@$(MAKE) $(NAME) CFLAGS="$(CFLAGS_DEBUG)"

# Debugging print

#############################################################################################
#                                                                                           #
#                                         COSMETIC                                          #
#                                                                                           #
#############################################################################################
# Reset
Color_Off=\033[0m       # Text Reset

# Regular Colors
Black=\033[0;30m
Red=\033[0;31m
Green=\033[0;32m
Yellow=\033[0;33m
Blue=\033[0;34m
Purple=\033[0;35m
Cyan=\033[0;36m
White=\033[0;37m

# Background
On_Black=\033[40m
On_Red=\033[41m
On_Green=\033[42m
On_Yellow=\033[43m
On_Blue=\033[44m
On_Purple=\033[45m
On_Cyan=\033[46m
On_White=\033[47m

-include $(DEPS)% 
