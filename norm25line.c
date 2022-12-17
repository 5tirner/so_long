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
		if (str[i - 2] != '1')
			error_generat(av);
		if (j != len)
			error_generat(av);
	}
}