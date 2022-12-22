/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_on_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:34:33 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/22 17:41:14 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_swap(char *a, char *b)
{
	char	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

void	ft_go_with_player(t_moves *param, int key)
{
	char	**map2;
	int		i;
	int		j;

	i = 0;
	map2 = ft_split(param->map, '\n');
	while (map2[i])
	{
		j = 0;
		while (map2[i][j])
		{
			if (map2[i][j] == 'P')
				break;
			j++;
		}
		if (key == 126 || key == 13)
			ft_swap(&map2[i][j], &map2[i - 1][j]);
		if (key == 125 || key == 1)
			ft_swap(&map2[i][j], &map2[i + 1][j]);
		if (key == 124 || key == 2)
			ft_swap(&map2[i][j], &map2[i][j + 1]);
		if (key == 123 || key == 0)
			ft_swap(&map2[i][j], &map2[i][j - 1]);
		i++;
	}
}