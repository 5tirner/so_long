/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:24:48 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/22 17:40:17 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_p(t_moves *p, int l, int k, int key)
{
	int	x;
	int	y;

	if (key == 126 || key == 13)
	{
		ft_go_with_player(p, key);
		mlx_destroy_image(p->mlx, p->player);
		p->player = mlx_xpm_file_to_image(p->mlx, "./pic/back.xpm", &x, &y);
		mlx_put_image_to_window(p->mlx, p->win, p->player, l, k);
	}
	if (key == 125 || key == 1)
	{
		ft_go_with_player(p, key);
		mlx_destroy_image(p->mlx, p->player);
		p->player = mlx_xpm_file_to_image(p->mlx, "./pic/face.xpm", &x, &y);
		mlx_put_image_to_window(p->mlx, p->win, p->player, l, k);
	}
	if (key == 124 || key == 2)
	{
		ft_go_with_player(p, key);
		mlx_destroy_image(p->mlx, p->player);
		p->player = mlx_xpm_file_to_image(p->mlx, "./pic/right.xpm", &x, &y);
		mlx_put_image_to_window(p->mlx, p->win, p->player, l, k);
	}
	if (key == 123 || key == 0)
	{
		ft_go_with_player(p, key);
		mlx_destroy_image(p->mlx, p->player);
		p->player = mlx_xpm_file_to_image(p->mlx, "./pic/left.xpm", &x, &y);
		mlx_put_image_to_window(p->mlx, p->win, p->player, l, k);
	}
}

void	ft_zero_or_one(t_moves *p, char c, int l, int k)
{
	int	x;
	int	y;

	if (c == '1')
	{
		mlx_destroy_image(p->mlx, p->wall);
		p->wall = mlx_xpm_file_to_image(p->mlx, "./pic/wall.xpm", &x, &y);
		mlx_put_image_to_window(p->mlx, p->win, p->wall, l, k);
	}
	if (c == '0')
	{
		mlx_destroy_image(p->mlx, p->ground);
		p->ground = mlx_xpm_file_to_image(p->mlx, "./pic/ground.xpm", &x, &y);
		mlx_put_image_to_window(p->mlx, p->win, p->ground, l, k);
	}
}

void	ft_coin(t_moves *p, int l, int k)
{
	int	x;
	int	y;
	
	if (p->coin_mv == 0)
	{
		mlx_destroy_image(p->mlx, p->coin);
		p->coin = mlx_xpm_file_to_image(p->mlx, "./pic/coin1.xpm", &x, &y);
		mlx_put_image_to_window(p->mlx, p->win, p->coin, l, k);
	}
	if (p->coin_mv == 1)
	{
		mlx_destroy_image(p->mlx, p->coin);
		p->coin = mlx_xpm_file_to_image(p->mlx, "./pic/coin2.xpm", &x, &y);
		mlx_put_image_to_window(p->mlx, p->win, p->coin, l, k);
	}
	if (p->coin_mv == 2)
	{
		mlx_destroy_image(p->mlx, p->coin);
		p->coin = mlx_xpm_file_to_image(p->mlx, "./pic/coin3.xpm", &x, &y);
		mlx_put_image_to_window(p->mlx, p->win, p->coin, l, k);
	}
	if (p->coin_mv == 3)
	{
		mlx_destroy_image(p->mlx, p->coin);
		p->coin = mlx_xpm_file_to_image(p->mlx, "./pic/coin4.xpm", &x, &y);
		mlx_put_image_to_window(p->mlx, p->win, p->coin, l, k);
		p->coin_mv = 0;
	}
	p->coin_mv++;		
}

void	ft_exit(t_moves *p, int l, int k)
{
	int	x;
	int	y;
	
	mlx_destroy_image(p->mlx, p->exit);
	p->exit = mlx_xpm_file_to_image(p->mlx, "./pic/c_door.xpm", &x, &y);
	mlx_put_image_to_window(p->mlx, p->win, p->exit, l, k);
}

void	ft_move_in_map(t_moves *param, int key)
{
	int	i;

	i = 0;
	param->k = 0;
	param->l = 0;
	while (param->map[i])
	{
		if (param->map[i] == 'P')
			ft_p(param, param->l, param->k, key);
		if (param->map[i] == 'E')
			ft_exit(param, param->l, param->k);
		if (param->map[i] == 'C')
			ft_coin(param, param->l, param->k);
		if (param->map[i] == '1' || param->map[i] == '0')
			ft_zero_or_one(param, param->map[i], param->l, param->k);
		i++;
		param->l += 50;
		if (param->map[i] == '\n')
		{
			param->k += 50;
			param->l = 0;
			i++;
		}
	}
}
