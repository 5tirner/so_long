/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:24:48 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/22 13:03:12 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_p(t_moves *p, int l, int k, int key)
{
	int	x;
	int	y;
	
	if (key == 126 || key == 13)
	{
		p->player = mlx_xpm_file_to_image(p->mlx, "./pic/p_back.xpm", &x, &y);
		mlx_put_image_to_window(p->mlx, p->win, p->player, l, k);
	}
	if (key == 125 || key == 1)
	{
		p->player = mlx_xpm_file_to_image(p->mlx, "./pic/p_face.xpm", &x, &y);
		mlx_put_image_to_window(p->mlx, p->win, p->player, l, k);
	}
	if (key == 124 || key == 2)
	{
		p->player = mlx_xpm_file_to_image(p->mlx, "./pic/p_right.xpm", &x, &y);
		mlx_put_image_to_window(p->mlx, p->win, p->player, l, k);
	}
	if (key == 123 || key == 0)
	{
		p->player = mlx_xpm_file_to_image(p->mlx, "./pic/p_left.xpm", &x, &y);
		mlx_put_image_to_window(p->mlx, p->win, p->player, l, k);
	}
}

void	ft_zero_or_one(t_moves *p, char c, int l, int k)
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

void	ft_coin_or_exit(t_moves *p, char c, int l, int k)
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

void	ft_move_in_map(t_moves *param, int key)
{
	int	i;
	int	l;
	int	k;

	i = 0;
	k = 0;
	l = 0;
	while (param->map[i])
	{
		if (param->map[i] == 'P')
			ft_p(param, l, k, key);
		if (param->map[i] == 'E' || param->map[i] == 'C')
			ft_coin_or_exit(param, param->map[i], l, k);
		if (param->map[i] == '1' || param->map[i] == '0')
			ft_zero_or_one(param, param->map[i], l, k);
		i++;
		l += 100;
		if (param->map[i] == '\n')
		{
			k += 100;
			l = 0;
			i++;
		}
	}
}
