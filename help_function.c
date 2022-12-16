/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 01:04:10 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/16 22:34:45 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
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
	param->img = mlx_xpm_file_to_image(param->mlx, "image.xpm", &x, &y);
	mlx_put_image_to_window(param->mlx, param->win, param->img, 100, 100);
}

int	moves(int key, t_moves *param)
{
	if (key == 126 || key == 13)
	{
		param->moves_number++;
		printf("move number %d: up\n", param->moves_number);
		mlx_clear_window(param->mlx, param->win);
		ft_show(param);
		mlx_string_put(param->mlx, param->win, 10, 15, 0xFFFFF0, ft_itoa(param->moves_number));
	}
	if (key == 125 || key == 1)
	{
		param->moves_number++;
		printf("move number %d: down\n", param->moves_number);
		mlx_clear_window(param->mlx, param->win);
		ft_show(param);
		mlx_string_put(param->mlx, param->win, 10, 15, 0xFFFFF0, ft_itoa(param->moves_number));
	}
	if (key == 124 || key == 2)
	{
		param->moves_number++;
		printf("move number %d: right\n", param->moves_number);
		mlx_clear_window(param->mlx, param->win);
		ft_show(param);
		mlx_string_put(param->mlx, param->win, 10, 15, 0xFFFFF0, ft_itoa(param->moves_number));
	}
	if (key == 123 || key == 0)
	{
		param->moves_number++;
		printf("move number %d: left\n", param->moves_number);
		mlx_clear_window(param->mlx, param->win);
		ft_show(param);
		mlx_string_put(param->mlx, param->win, 10, 15, 0xFFFFF0, ft_itoa(param->moves_number));
	}
	return (0);
}