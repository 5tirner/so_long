/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_thing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:24:09 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/26 15:25:31 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	vars_value_nb1(int *v_a, int *v_b, int *v_c, int *v_d)
{
	*v_a = 0;
	*v_b = 0;
	*v_c = 0;
	*v_d = 0;
}

void	vars_value_nb2(t_moves *p, int *v_a, int *v_b, int *v_c)
{
	*v_a = ft_strlen(p->map) - 1;
	*v_b = 0;
	*v_c = 0;
}

void	win_func(void)
{
	ft_printf("\n--------------------\n");
	ft_printf("| Congra, You Win  |");
	ft_printf("\n--------------------\n\n");
	exit(0);
}

void	go_down_and_up_norm(t_moves *p, char *c1, char *c2)
{
	if (*c1 == 'C')
		p->coin_nbr -= 1;
	*c1 = 'P';
	*c2 = '0';
	p->mv_nb++;
	ft_printf("move number %d: down\n", p->mv_nb);
}
