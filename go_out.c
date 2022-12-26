/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 23:21:58 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/26 18:59:41 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	if_right(t_moves *p, int key)
{
	int	i;

	i = 0;
	while (p->map[i] && p->map[i] != 'P')
		i++;
	if (p->map[i + 1] == 'E')
		win_func(p, key);
}

void	if_left(t_moves *p, int key)
{
	int	i;

	i = 0;
	while (p->map[i] && p->map[i] != 'P')
		i++;
	if (p->map[i - 1] == 'E')
		win_func(p, key);
}

void	if_down(t_moves *p, int key)
{
	t_vars	v;

	vars_value_nb1(&v.a, &v.b, &v.c, &v.d);
	while (p->map[v.a] && p->map[v.a] != 'P')
	{
		if (p->map[v.a] == '\n')
			v.b = 0;
		v.a++;
		v.b++;
		v.d++;
	}
	while (p->map[v.a] && p->map[v.a] != '\n')
		v.a++;
	v.a += 1;
	while (p->map[v.a] && p->map[v.a] != '\n')
	{
		if (v.b == v.c)
			break ;
		v.a++;
		v.c++;
	}
	if (p->map[v.a - 1] == 'E')
		win_func(p, key);
}

void	if_up(t_moves *p, int key)
{
	t_vars	v;

	v.d = ft_strlen(p->map) - 1;
	vars_value_nb2(p, &v.a, &v.b, &v.c);
	while (p->map[v.a] && p->map[v.a] != 'P')
	{
		if (p->map[v.a] == '\n')
			v.b = 0;
		v.a--;
		v.b++;
		v.d--;
	}
	while (p->map[v.a] && p->map[v.a] != '\n')
		v.a--;
	v.a -= 1;
	while (p->map[v.a] && p->map[v.a] != '\n')
	{
		if (v.b == v.c)
			break ;
		v.a--;
		v.c++;
	}
	if (p->map[v.a + 1] == 'E')
		win_func(p, key);
}

void	get_out(t_moves *param, int key)
{
	if (key == 125 || key == 1)
		if_down(param, key);
	if (key == 126 || key == 13)
		if_up(param, key);
	if (key == 124 || key == 2)
		if_right(param, key);
	if (key == 123 || key == 0)
		if_left(param, key);
}
