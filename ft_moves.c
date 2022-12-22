/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 03:49:40 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/22 17:08:11 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_up_move(t_moves *p, int key)
{
	p->mv_nb++;
	ft_printf("move number %d: up\n", p->mv_nb);
	mlx_clear_window(p->mlx, p->win);
	ft_move_in_map(p, key);
	mlx_string_put(p->mlx, p->win, 10, 15, 0xFFFFF0, ft_itoa(p->mv_nb));
}

void	ft_down_move(t_moves *p, int key)
{
	p->mv_nb++;
	ft_printf("move number %d: down\n", p->mv_nb);
	mlx_clear_window(p->mlx, p->win);
	ft_move_in_map(p, key);
	mlx_string_put(p->mlx, p->win, 10, 15, 0xFFFFF0, ft_itoa(p->mv_nb));
}

void	ft_right_move(t_moves *p, int key)
{
	p->mv_nb++;
	ft_printf("move number %d: right\n", p->mv_nb);
	mlx_clear_window(p->mlx, p->win);
	ft_move_in_map(p, key);
	mlx_string_put(p->mlx, p->win, 10, 15, 0xFFFFF0, ft_itoa(p->mv_nb));
}

void	ft_left_move(t_moves *p, int key)
{
	p->mv_nb++;
	ft_printf("move number %d: left\n", p->mv_nb);
	mlx_clear_window(p->mlx, p->win);
	ft_move_in_map(p, key);
	mlx_string_put(p->mlx, p->win, 10, 15, 0xFFFFF0, ft_itoa(p->mv_nb));
}

int	moves(int key, t_moves *param)
{
	if (key == 53 || key == 12)
		exit(0);
	if (key == 126 || key == 13)
		ft_up_move(param, key);
	if (key == 125 || key == 1)
		ft_down_move(param, key);
	if (key == 124 || key == 2)
		ft_right_move(param, key);
	if (key == 123 || key == 0)
		ft_left_move(param, key);
	return (0);
}
