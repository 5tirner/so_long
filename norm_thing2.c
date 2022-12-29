/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_thing2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:26:40 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/29 16:18:14 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	first_loop(t_moves *p, char *av)
{
	int	i;
	int	j;

	i = 0;
	while (p->map2[i])
	{
		j = 0;
		while (p->map2[i][j])
		{
			if (p->map2[i][j] != 'F' && p->map2[i][j] != '1'
				&& p->map2[i][j] != 'E' && p->map2[i][j] != '0')
				error_generat(av);
			j++;
		}
		i++;
	}
}

void	second_loop(t_moves *p, char *av)
{
	int	i;
	int	j;

	i = 0;
	while (p->map2[i])
	{
		j = 0;
		while (p->map2[i][j])
		{
			if (p->map2[i][j] != '1'
				&& p->map2[i][j] != 'l' && p->map2[i][j] != '0')
				error_generat(av);
			j++;
		}
		i++;
	}
}

void	flood_fill_val(int *a, int *b, int *c, int *d)
{
	*a = *c;
	*b = *d;
}
