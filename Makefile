# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 02:03:17 by zasabri           #+#    #+#              #
#    Updated: 2022/12/18 23:04:31 by zasabri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRSC	= help_function.c\
		so_long.c\
		./libft/ft_itoa.c\
		ft_validation.c\
		./libft/ft_strnstr.c\
		./libft/ft_strlen.c\
		./libft/ft_split.c\
		get_next_line.c\
		get_next_line_utils.c\
		./libft/ft_calloc.c\
		./libft/ft_bzero.c\
		ft_print_error.c\
		ft_moves.c\
		map_size.c\
		ft_graphic_map.c\
	
OBJS	= $(SRSC:.c=.o)

CC		= cc

CFLAGS		= -Wall -Wextra -Werror

libmlx	= -I /usr/local/include -L /usr/local/bin -lmlx -framework openGL -framework Appkit

PROG	= so_long

RM		= rm -f

all : $(PROG)

$(PROG) : $(OBJS)

	$(CC) $(CFLAGS) $(OBJS) $(libmlx) -o $(PROG)

clean :

	$(RM) $(OBJS)

fclean : clean

	$(RM) $(PROG)

re : fclean all

