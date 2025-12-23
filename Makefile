# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/14 14:47:47 by lud-adam          #+#    #+#              #
#    Updated: 2025/12/18 14:45:55 by lud-adam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all fclean re bonus clean-bin clean-obj debug debug-cc debug-print
CC = cc
CFLAGS = -Wextra -Wall -Werror
DEPENDANCIES = -MMD -MP
NO_DIR = --no-print-directory

MAKE := $(MAKE) -j $(NO_DIR)
NAME = cub3D

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
P_MLX = minilibx-linux/
P_OBJ = .obj/
P_LIB_MATH = $(P_SRC)math/
P_INC_MATH = $(P_SRC)/math/inc/
P_SRC_DRAW = $(P_SRC)draw/
P_SRC_TEST = $(P_SRC)test/

#############################################################################################
#                                                                                           #
#                                           FILES                                           #
#                                                                                           #
#############################################################################################

SRC = \
	main.c \
	mlx.c \
	hooks.c \
	create_sprites.c \
	map.c \
	launcher.c \
	utils.c \
	debug.c

SRC_DRAW = \
	draw_map.c \
	utils_draw.c

SRC_TEST = \
	t_fov.c \

MLX_LIB = $(P_MLX)libmlx.a
MATH_LIB = $(P_LIB_MATH)libmath.a

LIBS = \
	-L$(P_MLX) -lmlx -lXext -lX11 -lm -lz \
	-L$(P_LIB_MATH) -lmath \
	
#############################################################################################
#                                                                                           #
#                                        MANIPULATION                                       #
#                                                                                           #
#############################################################################################
SRCS =	\
	$(addprefix $(P_SRC), $(SRC)) \
	$(addprefix $(P_SRC_DRAW), $(SRC_DRAW)) \
	$(addprefix $(P_SRC_TEST), $(SRC_TEST)) \

# List of object files (redirect to P_OBJ)
OBJS =  \
	$(subst $(P_SRC), $(P_OBJ), $(SRCS:.c=.o)) \

P_OBJS = $(subst $(P_SRC), $(P_OBJ), $(SRCS))

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
$(NAME): $(MLX_LIB) $(P_LIB_MATH)libmath.a $(OBJS)
	@if $(CC) $(CFLAGS) $(DEPENDANCIES) -I $(P_INC) -I $(P_MLX) -I $(P_INC_MATH) -o $(NAME) $(OBJS) $(LIBS) -lm; then \
		echo "$(Green)Creating executable $@$(Color_Off)"; \
	else \
		echo "$(Red)Error creating $@$(Color_Off)"; \
	fi

# Custom rule to compilate all .c with there path
$(P_OBJ)%.o: $(P_SRC)%.c $(INCS)
	@mkdir -p $(dir $@)
	@if $(CC) $(CFLAGS) $(DEPENDANCIES) -I $(P_INC) -I $(P_MLX) -I $(P_INC_MATH) -c $< -o $@; then \
		echo "$(Cyan)Compiling $<$(Color_Off)"; \
	else \
		echo "$(Red)Error creating $@$(Color_Off)"; \
	fi

$(MLX_LIB):
	@echo "Compiling MinilibX..."
	@$(MAKE) -C $(P_MLX)

$(MATH_LIB):
	echo "Compiling math.a..."
	rm -f $(P_LIB_MATH)math.a
	$(MAKE) -C $(P_LIB_MATH)

$(P_LIB_MATH)math.a:
	$(MAKE) -C $(P_LIB_MATH)
#############################################################################################
#                                                                                           #
#                                      Other RULES                                          #
#                                                                                           #
#############################################################################################
# Rules for clean up
clean:
	$(MAKE) -C $(P_MLX) clean
	$(MAKE) -C $(P_LIB_MATH) clean
	rm -rfd $(P_OBJ)
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
