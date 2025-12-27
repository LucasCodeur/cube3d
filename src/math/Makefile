# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/14 14:47:47 by lud-adam          #+#    #+#              #
#    Updated: 2025/12/09 16:48:41 by lud-adam         ###   ########.fr        #
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
TEST_NAME = test_exec

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
P_TEST = test/
P_SRC_TEST = $(P_TEST)src/
P_INC_TEST = $(P_TEST)inc/

#############################################################################################
#                                                                                           #
#                                           FILES                                           #
#                                                                                           #
#############################################################################################

SRC = \
	main.c \

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

SRC_TEST = \
	t_vector.c

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


SRC_TEST_FILES = $(addprefix $(P_SRC_TEST), $(SRC_TEST))
OBJ_TEST_FILES = $(SRC_TEST_FILES:.c=.o)
TEST_OBJS = $(patsubst %.c, $(P_OBJ)%.o, $(SRC_TEST_FILES))

# List of depedencies
DEPS = $(OBJS:%.o=%.d)

#############################################################################################
#                                                                                           #
#                                          RULES                                            #
#                                                                                           #
#############################################################################################
all:
	@$(MAKE) $(NAME)

# Create $(NAME) executable
$(TEST_NAME): $(OBJS)
	@if $(CC) $(CFLAGS) -lm $(DEPENDANCIES) -I $(P_INC) -I $(P_INC_TEST) -o $(NAME) $(OBJS) $(LIBS); then \
		echo "$(Green)Creating executable $@$(Color_Off)"; \
	else \
		echo "$(Red)Error creating $@$(Color_Off)"; \
	fi

# Custom rule to compilate all .c with there path
$(P_OBJ)%.o: $(P_SRC)%.c 
	@mkdir -p $(dir $@)
	@if $(CC) $(CFLAGS) $(DEPENDANCIES) -I $(P_INC) -I $(P_INC_TEST) -c $< -o $@; then \
		echo "$(Cyan)Compiling $<$(Color_Off)"; \
	else \
		echo "$(Red)Error creating $@$(Color_Off)"; \
	fi

$(NAME): $(OBJS) 
	ar -rcs $(NAME) $^

test_exec: $(TEST_OBJS) $(OBJS)
	@$(CC) $(CFLAGS) -lm -I $(P_INC) -I $(P_INC_TEST) -o $@ $^

$(P_OBJ)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(DEPENDANCIES) -I $(P_INC) -I $(P_INC_TEST) -c $< -o $@


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
	rm -f $(TEST_NAME)

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

test: test_exec

#############################################################################################
#                                                                                           #
#                                           DEBUG                                           #
#                                                                                           #
#############################################################################################
# Debugging rules
debug:
	@$(MAKE) $(NAME) CFLAGS="$(CFLAGS_DEBUG)"

debug-cc:
	@$(MAKE) $(NAME) CFLAGS="$(CC_DEBUG_CFLAGS)" CC="$(CC_DEBUG)" Cyan="$(Yellow)" Green="$(Purple)"

# Debugging print
debug-print:
	@$(MAKE) debug-print-project
	@$(MAKE) debug-print-separator

debug-print-separator:
	@echo ""
	@echo "$(On_Yellow)____________________$(Color_Off)"
	@echo ""

define check_var
	@if [ "$(strip $(1))" = "" ]; then \
		echo "$(Red)No $(2) found$(Color_Off)"; \
	else \
		echo "$(Red)$(2): \n\t$(Blue)$(1)$(Color_Off)"; \
	fi
endef

debug-print-project:
	$(call check_var,$(NAME),"Project")
	$(call check_var,$(SRCS),"SRCS")
	$(call check_var,$(OBJS),"OBJS")
	$(call check_var,$(INCS),"INCS")
	$(call check_var,$(LIBS),"LIBS")
	@$(MAKE) debug-print-separator
	$(call check_var,$(SRCS_TEST),"SRCS_TEST")
	$(call check_var,$(OBJS_TEST),"OBJS_TEST")


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
