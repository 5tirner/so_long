/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:34:31 by zasabri           #+#    #+#             */
/*   Updated: 2022/11/08 20:33:32 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*buffer_to_stock(int fd, char *stock)
{
	char	*buff;
	int		i;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	i = 1;
	while (!ft_strchr(stock, '\n') && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			if (!stock)
				return (NULL);
			return (stock);
		}
		buff[i] = '\0';
		stock = ft_strjoin(stock, buff);
	}
	free(buff);
	return (stock);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stock[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stock[fd] = buffer_to_stock(fd, stock[fd]);
	if (!stock[fd])
		return (NULL);
	line = ft_pre_save(stock[fd]);
	stock[fd] = ft_sec_save(stock[fd]);
	return (line);
}
