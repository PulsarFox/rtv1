# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: savincen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 14:19:49 by savincen          #+#    #+#              #
#    Updated: 2017/05/24 17:09:50 by savincen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AUTEUR = savincen
NAME = rtv1

CC = gcc
CFLAGS = -Wall -Werror -Wextra
MLXFLAGS = -lmlx -framework OpenGl -framework AppKit

LIBFT = libft/libft.a
HEADERS = ./includes
SRCS_DIR = ./srcs/
SRCS_NAME = rtv1.c raytracer.c init_shapes.c keys.c sphere.c plan.c light.c \
			parser.c checkers.c get_primitive_list_1.c get_primitive_list_2.c \
			parsing_reader.c parsing_tools.c errors.c verif_list.c cylinder.c \
			cone.c vect_calc.c rotate.c shadow.c init.c free.c cam_rot.c

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_NAME))
OBJS=$(SRCS:.c=.o)

#===========================#
#	Compilation rules		#
#===========================#

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft/
	@$(CC) -o $(NAME) $(OBJS) $(LIBFT) $(MLXFLAGS) -I $(HEADERS) -L ./minilibx_macos
	@echo "Executable $(NAME) cree with $(CFLAGS)"

debug: CFLAGS += -g
debug: $(NAME)

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS) -I $(HEADERS)
	@echo "Creation de $@"

#===========================#
#		Repo Rules			#
#===========================#

norme:
	@norminette $(SRCS)

auteur:
	@echo "$(AUTEUR)" > auteur

#===========================#
#		Cleaning Rules		#
#===========================#

clean:
	@/bin/rm -f $(OBJS)
	@echo "Object file cleaned"

libclean:
	@make -C libft fclean

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "$(NAME) cleaned"

re: fclean libclean all

.PHONY: all clean fclean re libclean libft auteur
