/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_on_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:34:33 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/23 01:11:21 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	go_right(t_moves *p)
{
	int	i;

	i = 0;
	while (p->map[i] && p->map[i] != 'P')
		i++;
	if (p->map[i + 1] == '0' || p->map[i + 1] == 'C')
	{
		if (p->map[i + 1] == 'C')
			p->coin_nbr -= 1;
		p->map[i + 1] = 'P';
		p->map[i] = '0';
	}
}

void	go_left(t_moves *p)
{
	int	i;

	i = 0;
	while (p->map[i] && p->map[i] != 'P')
		i++;
	if (p->map[i - 1] == '0' || p->map[i - 1] == 'C')
	{
		if (p->map[i - 1] == 'C')
			p->coin_nbr -= 1;
		p->map[i] = '0';
		p->map[i - 1] = 'P';
	}
}

void	go_down(t_moves *p)
{
	t_vars v;

	v.a = 0;
	v.b = 0;
	v.c = 0;
	v.d = 0;
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
			break;
		v.a++;
		v.c++;
	}
	if (p->map[v.a - 1] == 'C' || p->map[v.a - 1] == '0')
	{
		if (p->map[v.a - 1] == 'C')
			p->coin_nbr -= 1;
		p->map[v.a - 1] = 'P';
		p->map[v.d] = '0';
	}
}

void	go_up(t_moves *p)
{
	t_vars v;

	v.a = ft_strlen(p->map) - 1;
	v.b = 0;
	v.c = 0;
	v.d = ft_strlen(p->map) - 1;
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
			break;
		v.a--;
		v.c++;
	}
	if (p->map[v.a + 1] == 'C' || p->map[v.a + 1] == '0')
	{
		if (p->map[v.a + 1] == 'C')
			p->coin_nbr -= 1;
		p->map[v.a + 1] = 'P';
		p->map[v.d] = '0';
	}
}

void	go_with_player(t_moves *param, int key)
{
	if (key == 125 || key == 1)
		go_down(param);
	if (key == 126 || key == 13)
		go_up(param);
	if (key == 124 || key == 2)
		go_right(param);
	if (key == 123 || key == 0)
		go_left(param);
}
