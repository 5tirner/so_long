/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 01:04:10 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/18 03:50:16 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_show(t_moves *param)
{
	int i = 0;
	int j = 0;
	int x;
	int y;
	while (i < 500)
	{
		j = 0;
		while (j < 40)
		{
			mlx_pixel_put(param->mlx, param->win, i, j, 0xFF0FFF);
			j++;
		}
		i++;
	}
	j = 460, i = 0;
	while (j < 500)
	{
		i = 0;
		while (i < 500)
		{
			mlx_pixel_put(param->mlx, param->win, i, j, 0xFF0FFF);
			i++;
		}
		j++;
	}
	param->img = mlx_xpm_file_to_image(param->mlx, "./pic/back.xpm", &x, &y);
	mlx_put_image_to_window(param->mlx, param->win, param->img, 100, 100);
}