/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 04:01:35 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/19 00:13:12 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"
#include "./libft/libft.h"

void	ft_fill_map(t_moves *param, char *map)
{
	int	i;
	int	x;
	int y;
	int	l;
	int k;

	i = 0;
	k = 0;
	l = 0;
	while(map[i])
	{
		if (map[i] == 'P')
		{
			param->img = mlx_xpm_file_to_image(param->mlx, "./pic/face.xpm", &x, &y);
			mlx_put_image_to_window(param->mlx, param->win, param->img, l, k);
		}
		if (map[i] == 'E')
		{
			param->img = mlx_xpm_file_to_image(param->mlx, "./pic/closed.xpm", &x, &y);
			mlx_put_image_to_window(param->mlx, param->win, param->img, l, k);
		}
		if (map[i] == 'C')
		{
			param->img = mlx_xpm_file_to_image(param->mlx, "./pic/coin1.xpm", &x, &y);
			mlx_put_image_to_window(param->mlx, param->win, param->img, l, k);
		}
		if (map[i] == '1')
		{
			param->img = mlx_xpm_file_to_image(param->mlx, "./pic/wall.xpm", &x, &y);
			mlx_put_image_to_window(param->mlx, param->win, param->img, l, k);
		}
		if (map[i] == '0')
		{
			param->img = mlx_xpm_file_to_image(param->mlx, "./pic/ground.xpm", &x, &y);
			mlx_put_image_to_window(param->mlx, param->win, param->img, l, k);
		}
		i++;
		k += 100;
		l += 100;
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