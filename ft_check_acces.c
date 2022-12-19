/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_acces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:55:45 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/19 12:17:51 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_simple_track(char **map, char *av)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				k = j;
				if ((map[i][j - 1] == '1' || map[i][j - 1] == 'E')
					&& (map[i][j + 1] == '1' || map[i][j + 1] == 'E')
					&& (map[i - 1][k] == '1' || map[i - 1][k] == 'E')
					&& (map[i + 1][k] == '1' || map[i + 1][k] == 'E'))
					error_generat(av);
			}
			if (map[i][j] == 'P')
			{
				k = j;
				if ((map[i][j - 1] == '1' || map[i][j - 1] == 'E')
					&& (map[i][j + 1] == '1' || map[i][j + 1] == 'E')
					&& (map[i - 1][k] == '1' || map[i - 1][k] == 'E')
					&& (map[i + 1][k] == '1' || map[i + 1][k] == 'E'))
					error_generat(av);
			}
			if (map[i][j] == 'E')
			{
				k = j;
				if (map[i][j - 1] == '1' && map[i][j + 1] == '1'
					&& map[i - 1][k] == '1' && map[i + 1][k] == '1')
					error_generat(av);
			}
			j++;
		}
		i++;
	}
}