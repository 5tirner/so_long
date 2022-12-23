/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_thing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:24:09 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/23 17:44:20 by zasabri          ###   ########.fr       */
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

void	vars_value_nb2(t_moves *p, int *v_a, int *v_b, int *v_c, int *v_d)
{
	*v_a = ft_strlen(p->map) - 1;
	*v_b = 0;
	*v_c = 0;
	*v_d = ft_strlen(p->map) - 1;
}

void	win_func(void)
{
	ft_printf("\n--------------------\n");
	ft_printf("| Congra, You Win! |");
	ft_printf("\n--------------------\n\n");
	exit(0);
}