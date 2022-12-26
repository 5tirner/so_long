/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:00:01 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/26 15:42:53 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	position1(t_moves *p)
{
	int	i;
	int	j;

	i = 0;
	while (p->map2[i])
	{
		j = 0;
		while (p->map2[i][j])
		{
			j++;
			if (p->map2[i][j] == 'P')
				return (j);
		}
		i++;
	}
	return (0);
}

int	position2(t_moves *p)
{
	int	i;
	int	j;

	i = 0;
	while (p->map2[i])
	{
		j = 0;
		while (p->map2[i][j])
		{
			j++;
			if (p->map2[i][j] == 'P')
				return (i);
		}
		i++;
	}
	return (0);
}

void	flood_fill(char **str, t_pos start, t_pos size)
{
	char	c;
	char	d;
	char	e;
	t_pos	p;

	c = 'C';
	d = '0';
	e = 'E';
	str[start.a][start.b] = 'F';
	if (start.a > 0 && (str[start.a - 1][start.b] == c
		|| str[start.a - 1][start.b] == d
		|| str[start.a - 1][start.b] == e))
	{
		p.a = start.a - 1;
		p.b = start.b;
		flood_fill(str, p, size);
	}
	if (start.a < size.a - 1 && (str[start.a + 1][start.b] == c
		|| str[start.a + 1][start.b] == d
		|| str[start.a + 1][start.b] == e))
	{
		p.a = start.a + 1;
		p.b = start.b;
		flood_fill(str, p, size);
	}
	if (start.a < size.b - 1 && (str[start.a][start.b + 1] == c
		|| str[start.a][start.b + 1] == d
		|| str[start.a][start.b + 1] == e))
	{
		p.a = start.a;
		p.b = start.b + 1;
		flood_fill(str, p, size);
	}
	if (start.b > 0 && (str[start.a][start.b - 1] == c
		|| str[start.a][start.b - 1] == d
		|| str[start.a][start.b - 1] == e))
	{
		p.a = start.a;
		p.b = start.b - 1;
		flood_fill(str, p, size);
	}
}

void	all_is_good(t_moves *p, char *av)
{
	t_pos size;
	t_pos first_pos;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (p->map2[i])
		i++;
	while (p->map2[0][j])
		j++;
	size.a = i + 1;
	size.b = j + 1;
	first_pos.a = position2(p);
	first_pos.b = position1(p);
	flood_fill(p->map2, first_pos, size);
	i = 0;
	while (p->map2[i])
	{
		j = 0;
		while (p->map2[i][j])
		{
			if (p->map2[i][j] != 'F' && p->map2[i][j] != '1')
				error_generat(av);
			j++;
		}
		i++;
	}
}