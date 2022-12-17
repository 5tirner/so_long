/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 02:27:42 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/17 23:50:52 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "get_next_line.h"

typedef struct s_moves
{
	int		moves_number;
	void	*mlx;
	void	*win;
	void	*img;
	int		fd;
	char	**map_look;
}		t_moves;

char	*ft_itoa(int nb);
void	ft_show(t_moves *param);
int		moves(int key, t_moves *param);
void	ft_checkmap(t_moves *param, char **av);
size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	check_first_last_lines(char **map_str, char *av);
void	error_generat(char *av);
#endif