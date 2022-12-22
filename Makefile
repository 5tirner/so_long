# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 02:03:17 by zasabri           #+#    #+#              #
#    Updated: 2022/12/23 00:20:55 by zasabri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRSC	= so_long.c\
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
		./ft_printf/ft_char.c\
		./ft_printf/ft_check_format.c\
		./ft_printf/ft_hex_ptr_len.c\
		./ft_printf/ft_hex.c\
		./ft_printf/ft_number.c\
		./ft_printf/ft_percentage.c\
		./ft_printf/ft_printf.c\
		./ft_printf/ft_ptr.c\
		./ft_printf/ft_putchar.c\
		./ft_printf/ft_string.c\
		./ft_printf/ft_itoa.c\
		./ft_printf/ft_unsigned.c\
		./ft_printf/ft_utoa.c\
		in_game.c\
		move_on_map.c\
		coin_nbr.c\
		go_out.c\
	
OBJS	= $(SRSC:.c=.o)

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

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

