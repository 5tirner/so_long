/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_on_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:34:33 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/22 20:44:29 by zasabri          ###   ########.fr       */
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
		p->map[i] = '0';
		p->map[i - 1] = 'P';
	}
}

// void	go_up(t_moves *p)
// {
// 	int	i;
// 	int	j;
// 	int k;

// 	i = 0;
// 	j = 0;
// 	while (p->map[i] && p->map[i] != 'P')
// 		i++;
// 	k = i;
// 	while (p->map[i] && p->map[i] != '\n')
// 		i++;
// 	i += 1;
// 	while (p->map[i])
// 	{
// 		if (j == k)
// 			break;
// 		i++;
// 		j++;
// 	}
// 	if (p->map[i] == '0' || p->map[i] == 'C')
// 	{
// 		p->map[i] = 'P';
// 		p->map[k] = '0';
// 	}
// }
void	go_with_player(t_moves *param, int key)
{
	// if (key == 126 || key == 13)
	// 	go_up(param);
	// if (key == 125 || key == 1)
	// 	ft_down_move(param, key);
	if (key == 124 || key == 2)
		go_right(param);
	if (key == 123 || key == 0)
		go_left(param);
}