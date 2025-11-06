# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/05 13:04:53 by prigaudi          #+#    #+#              #
#    Updated: 2025/11/06 16:46:15 by prigaudi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re
NAME = cub3D

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3

SRC_DIR = sources
SRC = 		$(SRC_DIR)/main.c						\
			$(SRC_DIR)/init/init_config_data.c		\
			$(SRC_DIR)/parsing/argument.c			\
			$(SRC_DIR)/parsing/config_elements.c	\
			$(SRC_DIR)/parsing/config.c				\
			$(SRC_DIR)/parsing/parsing.c			\
			$(SRC_DIR)/utils/ft_calloc.c			\
			$(SRC_DIR)/utils/ft_memmove.c			\
			$(SRC_DIR)/utils/ft_strlen.c			\
			$(SRC_DIR)/utils/ft_strncmp.c			\
			$(SRC_DIR)/utils/ft_strnjoin.c			\
			$(SRC_DIR)/utils/ft_strnstr.c			\
			$(SRC_DIR)/utils/ft_substr.c			\
			$(SRC_DIR)/utils/get_next_line.c			

OBJ_DIR = objects
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c ./includes/cub3d.h Makefile | $(OBJ_DIR)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	find . -name "*.o" -type f -delete
	find . -type d -empty -delete
fclean: clean
	find . -name "*.a" -type f -delete
	rm -f $(NAME)
re: fclean all