/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 04:01:35 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/22 12:13:10 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_player(t_moves *p, int l, int k)
{
	int	x;
	int	y;

	p->player = mlx_xpm_file_to_image(p->mlx, "./pic/p_face.xpm", &x, &y);
	mlx_put_image_to_window(p->mlx, p->win, p->player, l, k);
}

void	ft_zero_one(t_moves *p, char c, int l, int k)
{
	int	x;
	int	y;

	if (c == '1')
	{
		p->wall = mlx_xpm_file_to_image(p->mlx, "./pic/wall.xpm", &x, &y);
		mlx_put_image_to_window(p->mlx, p->win, p->wall, l, k);
	}
	if (c == '0')
	{
		p->ground = mlx_xpm_file_to_image(p->mlx, "./pic/ground.xpm", &x, &y);
		mlx_put_image_to_window(p->mlx, p->win, p->ground, l, k);
	}
}

void	ft_coin_exit(t_moves *p, char c, int l, int k)
{
	int	x;
	int	y;

	if (c == 'C')
	{
		p->coin = mlx_xpm_file_to_image(p->mlx, "./pic/coin1.xpm", &x, &y);
		mlx_put_image_to_window(p->mlx, p->win, p->coin, l, k);
	}
	if (c == 'E')
	{
		p->exit = mlx_xpm_file_to_image(p->mlx, "./pic/cl_door.xpm", &x, &y);
		mlx_put_image_to_window(p->mlx, p->win, p->exit, l, k);
	}
}

void	ft_fill_map(t_moves *param, char *map)
{
	int	i;
	int	l;
	int	k;

	i = 0;
	k = 0;
	l = 0;
	while (map[i])
	{
		if (map[i] == 'P')
			ft_player(param, l, k);
		if (map[i] == 'E' || map[i] == 'C')
			ft_coin_exit(param, map[i], l, k);
		if (map[i] == '1' || map[i] == '0')
			ft_zero_one(param, map[i], l, k);
		i++;
		l += 100;
		if (map[i] == '\n')
		{
			k += 100;
			l = 0;
			i++;
		}
	}
}

void	ft_graphic_map(t_moves *param, char *av)
{
	char	*str;
	int		fd;
	char	*map_str;

	map_str = ft_calloc(1, 1);
	fd = open(av, O_RDONLY, 0777);
	str = get_next_line(fd);
	while (str)
	{
		map_str = ft_strj(map_str, str);
		str = get_next_line(fd);
	}
	ft_fill_map(param, map_str);
}
