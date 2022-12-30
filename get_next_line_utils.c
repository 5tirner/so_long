/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:13:11 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/29 22:32:05 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strch(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strj(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	str = malloc((ft_strl(s1) + ft_strl(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
		str[k++] = s1[i++];
	while (s2[j])
		str[k++] = s2[j++];
	str[k] = '\0';
	free(s1);
	return (str);
}

char	*ft_pre_save(char *stock)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!*stock)
		return (NULL);
	while (stock[i] && stock[i] != '\n')
		i++;
	if (stock[i] == '\n')
		i += 1;
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (stock[i] && stock[i] != '\n')
		str[j++] = stock[i++];
	if (stock[i] == '\n')
		str[j++] = stock[i++];
	str[j] = '\0';
	return (str);
}

char	*ft_sec_save(char *stock)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (!stock[i])
	{
		free(stock);
		return (NULL);
	}
	str = malloc(ft_strl(stock) - i);
	if (!str)
		return (NULL);
	i += 1;
	j = 0;
	while (stock[i])
		str[j++] = stock[i++];
	str[j] = '\0';
	free(stock);
	return (str);
}
