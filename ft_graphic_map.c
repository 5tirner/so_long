/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 04:01:35 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/18 05:48:52 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_graphic_map(t_moves *p,char **av)
{
	char	*str;
	char	*str_map;
	int fd;

	str_map = ft_calloc(1, 1);
	(*p).fd = open(av[1], O_RDONLY, 0777);
	str = get_next_line(p->fd);
	while (str)
	{
		str_map = ft_strj(str_map, str);
		str = get_next_line(p->fd);
	}
}