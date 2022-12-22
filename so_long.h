/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 02:27:42 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/23 00:36:31 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "get_next_line.h"
# include "./ft_printf/ft_printf.h"

typedef struct s_moves
{
	int		mv_nb;
	int		coin_mv;
	int		coin_nbr;
	void	*mlx;
	void	*win;
	void	*img;
	void	*wall;
	void	*player;
	void	*ground;
	void	*exit;
	void	*coin;
	int		fd;
	char	*str;
	char	*map;
	int		l;
	int		k;
}	t_moves;

typedef struct s_vars
{
	int	a;
	int	b;
	int	c;
	int	d;
	int	x;
	int	y;
}	t_vars;

char	*ft_itoa(int nb);
void	ft_show(t_moves *param);
void	ft_checkmap(t_moves *param, char **av);
size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	check_first_last_lines(char **map_str, char *av);
void	error_generat(char *av);
int		moves(int key, t_moves *param);
int		ft_width(char *str_map);
int		ft_l(char	*str);
void	ft_graphic_map(t_moves *param, char *av);
void	ft_move_in_map(t_moves *param, int key);
void	go_with_player(t_moves *param, int key);
int		coin_nbr(t_moves *p);
void	get_out(t_moves *param, int key);
#endif