/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 04:52:06 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/18 04:26:34 by zasabri          ###   ########.fr       */
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
