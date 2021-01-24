# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/02 08:42:26 by dogata            #+#    #+#              #
#    Updated: 2020/08/21 18:52:44 by dogata           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
CFLAGS := -Wall -Wextra -Werror
LIBS := ar rcs
NAME := libftprintf.a
NAME_LIBFT := libft.a
LIBFT_DIR := libft/

SRCS := \
	ft_printf.c \
	conversion_character.c \
	get_flags_info.c \
	output_csidu.c \
	output_px.c \
	output_functions.c \
	convert_num.c \
	ft_uitoa.c \
	ft_ullitoa.c \

OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make bonus -C $(LIBFT_DIR)
	$(LIBS) $(NAME) $(OBJS) $(LIBFT_DIR)*.o

clean:
	rm -f $(OBJS) $(LIBFT_DIR)*.o

fclean: clean
	rm -f $(NAME) $(LIBFT_DIR)$(NAME_LIBFT)

re: fclean all
 
.PHONY: all bonus clean fclean re