/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 04:07:25 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/17 04:52:44 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map_body(char *str, char *av)
{
	int i;

	i = 0;
	if (str[0] != '1')
		error_generat(av);
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != 'P'
		&& str[i] != 'C' && str[i] != 'E' && str[i] != '\n')
			error_generat(av);
		if (str[i] == '\n' && str[i + 1] == '\n')
			error_generat(av);
		i++;
	}
	if (str[i - 1] != '1')
		error_generat(av);
}

void	ft_check_map_look(char *str, char *av)
{
	int	len;
	int	i;
	int j;
	
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	len = i;
	while (str[i])
	{
		if (str[i] == '\n'
		&& (str[i - 1] != '1' || str[i + 1] != '1'))
			error_generat(av);
		i++;
		j = 0;
		while (str[i] && str[i] != '\n')
		{
			i++;
			j++;
		}
		if (j != len)
			error_generat(av);
	}
}

void	ft_check_elements(char *str, char *av)
{
	int i;
	int p;
	int e;
	int c;
	
	i = 0;
	p = 0;
	e = 0;
	c = 0;
	while (str[i])
	{
		if (str[i] == 'C')
			c += 1;
		if (str[i] == 'P')
			p += 1;
		if (str[i] == 'E')
			e += 1;
		i++;
	}
	if (p != 1)
		error_generat(av);
	if (e != 1)
		error_generat(av);
	if (c < 1)
		error_generat(av);
}

void	check_first_last_lines(char *first, char *last, char *av)
{
	int i;
	
	i = 0;
	while (first[i])
	{
		if (first[i] != '1')
			error_generat(av);
		i++;
	}
	i = 0;
	while (last[i])
	{
		if (last[i] != '1')
			error_generat(av);
		i++;
	}
}

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
	map_str2 = ft_split(map_str, '\n');
	check_first_last_lines(map_str2[0], map_str2[i], av[1]);
}