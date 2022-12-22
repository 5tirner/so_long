/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 01:03:43 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/22 12:03:24 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./libft/libft.h"

int	main(int ac, char **av)
{
	t_moves	p;
	char	*str;

	if (ac == 2)
	{
		p.map = ft_calloc(1, 1);
		p.mv_nb = 0;
		p.fd = open(av[1], O_RDONLY, 0777);
		str = get_next_line(p.fd);
		if (!str)
			error_generat(av[1]);
		while (str)
		{
			p.map = ft_strj(p.map, str);
			str = get_next_line(p.fd);
		}
		ft_checkmap(&p, av);
		p.mlx = mlx_init();
		p.win = mlx_new_window(p.mlx, ft_width(av[1]), ft_l(av[1]), "so_long");
		ft_graphic_map(&p, av[1]);
		mlx_key_hook(p.win, moves, &p);
		mlx_loop(p.mlx);
	}
	else
		ft_printf("Invalid number of argement\n");
}
