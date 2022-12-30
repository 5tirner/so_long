/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 02:27:42 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/30 15:41:01 by zasabri          ###   ########.fr       */
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
	int		x;
	int		y;
	char	**map2;
}	t_moves;

typedef struct s_vars
{
	int	a;
	int	b;
	int	c;
	int	d;
}	t_vars;

typedef struct s_pos
{
	int	a;
	int	b;
}	t_pos;

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
void	vars_value_nb1(int *v_a, int *v_b, int *v_c, int *v_d);
void	vars_value_nb2(t_moves *p, int *v_a, int *v_b, int *v_c);
void	win_func(t_moves *p, int key);
void	go_down_and_up_norm(t_moves *p, char *c1, char *c2, int key);
void	all_is_good(t_moves *p, char *av);
void	player_move1(t_moves *p, int l, int k);
void	player_move2(t_moves *p, int l, int k);
void	player_move3(t_moves *p, int l, int k);
void	player_move4(t_moves *p, int l, int k);
void	first_loop(t_moves *p, char *av);
void	second_loop(t_moves *p, char *av);
void	free_allocation(char **str);
#endif