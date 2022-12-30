/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 04:52:06 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/30 18:52:15 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_generat(char *av)
{
	ft_printf("Error\n");
	ft_printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
	ft_printf("| %s: is invalid map        |\n", av);
	ft_printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
	exit(0);
}

int	quit(void)
{
	exit(0);
	return (0);
}
