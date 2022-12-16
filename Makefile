# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 02:03:17 by zasabri           #+#    #+#              #
#    Updated: 2022/12/16 02:37:37 by zasabri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRSC	= help_function.c\
		../libft/ft_itoa.c\
	
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

