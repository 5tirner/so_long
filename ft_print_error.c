/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 04:52:06 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/17 04:53:40 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_generat(char *av)
{
	write(2, "Error\n", 6);
	write(2, av, ft_strlen(av));
	write (2, ": is invalid map\n", 17);
	exit(1);
}

int	ft_cw(const char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while ((str[i]) && (str[i] == c))
			i++;
		if (str[i])
		{
			while (str[i] && str[i] != c)
				i++;
			j += 1;
		}
	}
	return (j);
}