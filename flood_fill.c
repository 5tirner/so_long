/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:00:01 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/30 15:50:44 by zasabri          ###   ########.fr       */
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

void	flood_fill2(char **str, t_pos s, t_pos size)
{
	char	c;
	char	d;
	t_pos	position;

	c = 'F';
	d = 'E';
	str[s.a][s.b] = 'l';
	if (s.a > 0 && (str[s.a - 1][s.b] == c || str[s.a - 1][s.b] == d))
	{
		position.a = s.a - 1;
		position.b = s.b;
		flood_fill2(str, position, size);
	}
	if (s.a < size.a - 1 && (str[s.a + 1][s.b] == c || str[s.a + 1][s.b] == d))
	{
		position.a = s.a + 1;
		position.b = s.b;
		flood_fill2(str, position, size);
	}
	if (s.b < size.b - 1 && (str[s.a][s.b + 1] == c || str[s.a][s.b + 1] == d))
	{
		position.a = s.a;
		position.b = s.b + 1;
		flood_fill2(str, position, size);
	}
	if (s.b > 0 && (str[s.a][s.b - 1] == c || str[s.a][s.b - 1] == d))
	{
		position.a = s.a;
		position.b = s.b - 1;
		flood_fill2(str, position, size);
	}
}

void	flood_fill(char **str, t_pos s, t_pos size)
{
	char	c;
	char	d;
	t_pos	p;

	c = 'C';
	d = '0';
	str[s.a][s.b] = 'F';
	if (s.a > 0 && (str[s.a - 1][s.b] == c || str[s.a - 1][s.b] == d))
	{
		p.a = s.a - 1;
		p.b = s.b;
		flood_fill(str, p, size);
	}
	if (s.a < size.a - 1 && (str[s.a + 1][s.b] == c || str[s.a + 1][s.b] == d))
	{
		p.a = s.a + 1;
		p.b = s.b;
		flood_fill(str, p, size);
	}
	if (s.b < size.b - 1 && (str[s.a][s.b + 1] == c || str[s.a][s.b + 1] == d))
	{
		p.a = s.a;
		p.b = s.b + 1;
		flood_fill(str, p, size);
	}
	if (s.b > 0 && (str[s.a][s.b - 1] == c || str[s.a][s.b - 1] == d))
	{
		p.a = s.a;
		p.b = s.b - 1;
		flood_fill(str, p, size);
	}
}

void	all_is_good(t_moves *p, char *av)
{
	t_pos	size;
	t_pos	first_pos;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (p->map2[i])
		i++;
	while (p->map2[0][j])
		j++;
	size.a = i;
	size.b = j;
	first_pos.a = position2(p);
	first_pos.b = position1(p);
	flood_fill(p->map2, first_pos, size);
	first_loop(p, av);
	flood_fill2(p->map2, first_pos, size);
	second_loop(p, av);
	free_allocation(p->map2);
}
