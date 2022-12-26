/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:00:01 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/26 18:24:54 by zasabri          ###   ########.fr       */
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

void	flood_fill2(char **str, t_pos start, t_pos size)
{
	char	c;
	char	d;
	t_pos	position;

	c = 'F';
	d = 'E';
	str[start.a][start.b] = 'l';
	if (start.a > 0 && (str[start.a - 1][start.b] == c || str[start.a - 1][start.b] == d))
	{
		position.a = start.a - 1;
		position.b = start.b;
		flood_fill2(str, position, size);
	}
	if (start.a < size.a - 1 && (str[start.a + 1][start.b] == c || str[start.a + 1][start.b] == d))
	{
		position.a = start.a + 1;
		position.b = start.b;
		flood_fill2(str, position, size);
	}
	if (start.b < size.b - 1 && (str[start.a][start.b + 1] == c || str[start.a][start.b + 1] == d))
	{
		position.a = start.a;
		position.b = start.b + 1;
		flood_fill2(str, position, size);
	}
	if (start.b > 0 && (str[start.a][start.b - 1] == c || str[start.a][start.b - 1] == d))
	{
		position.a = start.a;
		position.b = start.b - 1;
		flood_fill2(str, position, size);	
	}
}
void	flood_fill(char **str, t_pos start, t_pos size)
{
	char	c;
	char	d;
	t_pos	p;

	c = 'C';
	d = '0';
	str[start.a][start.b] = 'F';
	if (start.a > 0 && (str[start.a - 1][start.b] == c
		|| str[start.a - 1][start.b] == d))
	{
		p.a = start.a - 1;
		p.b = start.b;
		flood_fill(str, p, size);
	}
	if (start.a < size.a - 1 && (str[start.a + 1][start.b] == c
		|| str[start.a + 1][start.b] == d))
	{
		p.a = start.a + 1;
		p.b = start.b;
		flood_fill(str, p, size);
	}
	if (start.b < size.b - 1 && (str[start.a][start.b + 1] == c
		|| str[start.a][start.b + 1] == d))
	{
		p.a = start.a;
		p.b = start.b + 1;
		flood_fill(str, p, size);
	}
	if (start.b > 0 && (str[start.a][start.b - 1] == c
		|| str[start.a][start.b - 1] == d))
	{
		p.a = start.a;
		p.b = start.b - 1;
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
	flood_fill2(p->map2, first_pos, size);
	i = 0;
	while (p->map2[i])
	{
		j = 0;
		while (p->map2[i][j])
		{
			if (p->map2[i][j] != '1' && p->map2[i][j] != 'l' && p->map2[i][j] != '0')
				error_generat(av);
			j++;
		}
		printf("%s\n", p->map2[i]);
		i++;
	}
}
