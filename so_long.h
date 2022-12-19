/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 02:27:42 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/19 12:00:48 by zasabri          ###   ########.fr       */
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

typedef struct s_moves
{
	int		mv_nb;
	void	*mlx;
	void	*win;
	void	*img;
	int		fd;
	char	*map_saver;
	void	*wall;
	void	*player;
	void	*ground;
	void	*exit;
	void	*coin;
	int		k;
	int		l;
}	t_moves;

char	*ft_itoa(int nb);
void	ft_show(t_moves *param);
void	ft_checkmap(t_moves *param, char **av);
size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	check_first_last_lines(char **map_str, char *av);
void	error_generat(char *av);
int		moves(int key, t_moves *param);
int		ft_map_3ord(char *str_map);
int		ft_map_tol(char	*str);
void	ft_graphic_map(t_moves *param, char *av);
void	ft_simple_track(char **map, char *av);
#endif