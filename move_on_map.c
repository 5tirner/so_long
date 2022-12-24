/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_on_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:34:33 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/24 14:10:08 by zasabri          ###   ########.fr       */
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
		p->mv_nb++;
		ft_printf("move number %d: right\n", p->mv_nb);
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
		p->mv_nb++;
		ft_printf("move number %d: left\n", p->mv_nb);
	}
}

void	go_down(t_moves *p)
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
	if (p->map[v.a - 1] == 'C' || p->map[v.a - 1] == '0')
		go_down_and_up_norm(p, &p->map[v.a - 1], &p->map[v.d]);
}

void	go_up(t_moves *p)
{
	t_vars	v;

	vars_value_nb2(p, &v.a, &v.b, &v.c, &v.d);
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
	if (p->map[v.a + 1] == 'C' || p->map[v.a + 1] == '0')
		go_down_and_up_norm(p, &p->map[v.a + 1], &p->map[v.d]);
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
