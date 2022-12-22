/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 23:21:58 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/23 00:41:32 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	if_right(t_moves *p)
{
	int	i;

	i = 0;
	while (p->map[i] && p->map[i] != 'P')
		i++;
	if (p->map[i + 1] == 'E')
	{
		ft_printf("\nWINNER WINNER WINNER\n");
		exit(0);
	}
}

void	if_left(t_moves *p)
{
	int	i;

	i = 0;
	while (p->map[i] && p->map[i] != 'P')
		i++;
	if (p->map[i - 1] == 'E')
	{
		ft_printf("\nWINNER WINNER WINNER\n");
		exit(0);
	}
}

void	if_down(t_moves *p)
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
	if (p->map[v.a - 1] == 'E')
	{
		ft_printf("\nWINNER WINNER WINNER\n");
		exit(0);
	}
}

void	if_up(t_moves *p)
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
	if (p->map[v.a + 1] == 'E')
	{
		ft_printf("\nWINNER WINNER WINNER\n");
		exit(0);
	}
}

void	get_out(t_moves *param, int key)
{
	if (key == 125 || key == 1)
		if_down(param);
	if (key == 126 || key == 13)
		if_up(param);
	if (key == 124 || key == 2)
		if_right(param);
	if (key == 123 || key == 0)
		if_left(param);
}