/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin_nbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 00:17:26 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/23 00:23:25 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	coin_nbr(t_moves *p)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (p->map[i])
	{
		if (p->map[i] == 'C')
			j++;
		i++;
	}
	return (j);
}