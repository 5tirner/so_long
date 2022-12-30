/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 05:41:25 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/30 17:47:47 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_width(char *av)
{
	int		i;
	char	*str;
	char	*str_map;
	int		fd;

	str_map = ft_calloc(1, 1);
	fd = open(av, O_RDONLY, 0777);
	str = get_next_line(fd);
	while (str)
	{
		str_map = ft_strj(str_map, str);
		free(str);
		str = get_next_line(fd);
	}
	i = 0;
	while (str_map[i] && str_map[i] != '\n')
		i++;
	free(str_map);
	return (50 * i);
}

int	ft_l(char *av)
{
	char	*str;
	char	*str_map;
	char	**str_map2;
	int		i;
	int		fd;

	str_map = ft_calloc(1, 1);
	fd = open(av, O_RDONLY, 0777);
	str = get_next_line(fd);
	while (str)
	{
		str_map = ft_strj(str_map, str);
		free(str);
		str = get_next_line(fd);
	}
	str_map2 = ft_split(str_map, '\n');
	free(str_map);
	i = 0;
	while (str_map2[i])
		i++;
	free_allocation(str_map2);
	return (i * 50);
}
