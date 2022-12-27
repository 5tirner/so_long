/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:45:48 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/27 15:10:13 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_move1(t_moves *p, int l, int k)
{
	mlx_destroy_image(p->mlx, p->player);
	p->player = mlx_xpm_file_to_image(p->mlx, "./pic/b.xpm", &p->x, &p->y);
	if (!p->player)
		exit(1);
	mlx_put_image_to_window(p->mlx, p->win, p->player, l, k);
}

void	player_move2(t_moves *p, int l, int k)
{
	mlx_destroy_image(p->mlx, p->player);
	p->player = mlx_xpm_file_to_image(p->mlx, "./pic/f.xpm", &p->x, &p->y);
	if (!p->player)
		exit(1);
	mlx_put_image_to_window(p->mlx, p->win, p->player, l, k);
}

void	player_move3(t_moves *p, int l, int k)
{
	mlx_destroy_image(p->mlx, p->player);
	p->player = mlx_xpm_file_to_image(p->mlx, "./pic/r.xpm", &p->x, &p->y);
	if (!p->player)
		exit(1);
	mlx_put_image_to_window(p->mlx, p->win, p->player, l, k);
}

void	player_move4(t_moves *p, int l, int k)
{
	mlx_destroy_image(p->mlx, p->player);
	p->player = mlx_xpm_file_to_image(p->mlx, "./pic/l.xpm", &p->x, &p->y);
	if (!p->player)
		exit(1);
	mlx_put_image_to_window(p->mlx, p->win, p->player, l, k);
}
