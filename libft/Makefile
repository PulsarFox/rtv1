# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: savincen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 14:19:49 by savincen          #+#    #+#              #
#    Updated: 2017/04/13 20:05:38 by savincen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra

CC = gcc

HEADER = ./
SRCS = ft_memalloc.c ft_bzero.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
	ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c \
	ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
	ft_strncat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
	ft_strcmp.c ft_strncmp.c ft_isalpha.c ft_isdigit.c ft_isascii.c \
	ft_isalnum.c ft_isprint.c ft_toupper.c ft_tolower.c \
	ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
	ft_strequ.c ft_strnequ.c ft_putchar.c ft_putstr.c ft_putendl.c \
	ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_atoi.c ft_strnstr.c ft_strlcat.c ft_strmap.c \
	ft_strsub.c ft_strtrim.c ft_strmapi.c ft_itoa.c ft_lstadd.c \
	ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
	ft_strjoin.c ft_strsplit.c ft_count_words.c ft_isprime.c ft_sqrt.c \
	ft_lstaddend.c ft_display_lst.c get_next_line.c ft_strchrword.c ft_dswap.c

OBJS=$(SRCS:.c=.o)

#===========================#
#	Compilation rules		#
#===========================#

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@echo "Libft created and indexed."

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS) -I $(HEADER)

#===========================#
#		Repo Rules			#
#===========================#

norme:
	@norminette $(SRCS)

#===========================#
#		Cleaning Rules		#
#===========================#

clean:
	@/bin/rm -f $(OBJS)
	@echo "Object file cleaned"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "$(NAME) cleaned"

re: fclean all

.PHONY: all clean fclean re
