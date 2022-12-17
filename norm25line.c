/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm25line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 04:48:18 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/17 04:48:22 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	ft_checkmap(t_moves *param, char **av)
{
	char	*line;
	char	*map_str;
	int		i;
	char	**map_str2;
	
	map_str = ft_calloc(1, 1);
	i = ft_cw(map_str, '\n');
	if (ft_strnstr(av[1] , ".ber", ft_strlen(av[1])) == 0)
		error_generat(av[1]);
	param->fd = open(av[1], O_RDONLY, 0777);
	line = get_next_line(param->fd);
	if (!line)
		error_generat(av[1]);
	while (line)
	{
		map_str = ft_strj(map_str, line);
		line = get_next_line(param->fd);
	}
	ft_check_map_body(map_str, av[1]);
	ft_check_map_look(map_str, av[1]);
	ft_check_elements(map_str, av[1]);
	map_str2 = ft_spli(map_str, '\n');
	check_first_last_lines(map_str2[0], map_str2[i], av);
}