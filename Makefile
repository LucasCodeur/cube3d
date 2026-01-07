# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prigaudi <prigaudi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/05 13:04:53 by prigaudi          #+#    #+#              #
#    Updated: 2026/01/07 14:49:12 by prigaudi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re
NAME = cub3D

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3

MLX_DIR = minilibx
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11

SRC_DIR = sources
SRC = 		$(SRC_DIR)/main.c						\
			$(SRC_DIR)/init/init_data.c				\
			$(SRC_DIR)/init/mlx_utils.c				\
			$(SRC_DIR)/map/map.c					\
			$(SRC_DIR)/minimap/minimap.c			\
			$(SRC_DIR)/parsing/argument.c			\
			$(SRC_DIR)/parsing/check_element_line.c	\
			$(SRC_DIR)/parsing/check_extract_rgb.c	\
			$(SRC_DIR)/parsing/check_map_structure.c\
			$(SRC_DIR)/parsing/check_map.c			\
			$(SRC_DIR)/parsing/extract_save_map.c	\
			$(SRC_DIR)/parsing/config.c				\
			$(SRC_DIR)/parsing/parsing.c			\
			$(SRC_DIR)/parsing/save_element.c		\
			$(SRC_DIR)/utils/ft_free.c				\
			$(SRC_DIR)/utils/ft_atoi.c				\
			$(SRC_DIR)/utils/ft_calloc.c			\
			$(SRC_DIR)/utils/ft_lstadd_front.c		\
			$(SRC_DIR)/utils/ft_lstclear.c			\
			$(SRC_DIR)/utils/ft_lstnew.c			\
			$(SRC_DIR)/utils/ft_lstsize.c			\
			$(SRC_DIR)/utils/ft_malloc.c			\
			$(SRC_DIR)/utils/ft_memmove.c			\
			$(SRC_DIR)/utils/ft_split.c				\
			$(SRC_DIR)/utils/ft_strdup.c			\
			$(SRC_DIR)/utils/ft_strlen.c			\
			$(SRC_DIR)/utils/ft_strncmp.c			\
			$(SRC_DIR)/utils/ft_strnjoin.c			\
			$(SRC_DIR)/utils/ft_strnstr.c			\
			$(SRC_DIR)/utils/ft_strtrim.c			\
			$(SRC_DIR)/utils/ft_substr.c			\
			$(SRC_DIR)/utils/get_next_line.c			

OBJ_DIR = objects
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c ./includes/cub3d.h Makefile | $(OBJ_DIR)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX):
	make -C $(MLX_DIR) --no-print-directory

clean:
	find . -name "*.o" -type f -delete
	find . -type d -empty -delete
fclean: clean
	find . -name "*.a" -type f -delete
	rm -f $(NAME)
re: fclean all