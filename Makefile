# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/10 14:43:47 by eleclet           #+#    #+#              #
#    Updated: 2016/03/14 14:54:33 by eleclet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CFLAGS = -lmlx -framework OpenGl -framework Appkit

all : $(NAME)

$(NAME) :
	gcc main.c parse_map.c error.c trace.c libft/libft.a $(CFLAGS) -o $(NAME) -g
fclean :
	rm -f $(NAME)
re : fclean all
