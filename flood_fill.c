/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:00:01 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/30 16:36:49 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	p1(t_moves *p)
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

int	p2(t_moves *p)
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

void	flood_fill(char **str, t_pos s, t_pos sz)
{
	t_pos	p;

	vals_for_flood_fill(&p);
	str[s.a][s.b] = 'F';
	if (s.a > 0 && (str[s.a - 1][s.b] == p.o || str[s.a - 1][s.b] == p.p))
	{
		p.a = s.a - 1;
		p.b = s.b;
		flood_fill(str, p, sz);
	}
	if (s.a < sz.a - 1 && (str[s.a + 1][s.b] == p.o || str[s.a + 1][s.b] == p.p))
	{
		p.a = s.a + 1;
		p.b = s.b;
		flood_fill(str, p, sz);
	}
	if (s.b < sz.b - 1 && (str[s.a][s.b + 1] == p.o || str[s.a][s.b + 1] == p.p))
	{
		p.a = s.a;
		p.b = s.b + 1;
		flood_fill(str, p, sz);
	}
	if (s.b > 0 && (str[s.a][s.b - 1] == p.o || str[s.a][s.b - 1] == p.p))
	{
		p.a = s.a;
		p.b = s.b - 1;
		flood_fill(str, p, sz);
	}
}

void	flood_fill2(char **str, t_pos s, t_pos sz)
{
	t_pos	p;

	vals_for_flood_fill(&p);
	str[s.a][s.b] = 'l';
	if (s.a > 0 && (str[s.a - 1][s.b] == p.y || str[s.a - 1][s.b] == p.z))
	{
		p.a = s.a - 1;
		p.b = s.b;
		flood_fill2(str, p, sz);
	}
	if (s.a < sz.a - 1 && (str[s.a + 1][s.b] == p.y || str[s.a + 1][s.b] == p.z))
	{
		p.a = s.a + 1;
		p.b = s.b;
		flood_fill2(str, p, sz);
	}
	if (s.b < sz.b - 1 && (str[s.a][s.b + 1] == p.y || str[s.a][s.b + 1] == p.z))
	{
		p.a = s.a;
		p.b = s.b + 1;
		flood_fill2(str, p, sz);
	}
	if (s.b > 0 && (str[s.a][s.b - 1] == p.y || str[s.a][s.b - 1] == p.z))
	{
		p.a = s.a;
		p.b = s.b - 1;
		flood_fill2(str, p, sz);
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
	first_pos.a = p2(p);
	first_pos.b = p1(p);
	flood_fill(p->map2, first_pos, size);
	first_loop(p, av);
	flood_fill2(p->map2, first_pos, size);
	second_loop(p, av);
	free_allocation(p->map2);
}
