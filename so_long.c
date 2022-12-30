/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 01:03:43 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/30 16:23:49 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_var_value(t_moves *p, char *av)
{
		p->coin_mv = 0;
		p->map = ft_calloc(1, 1);
		p->mv_nb = 1;
		p->fd = open(av, O_RDONLY, 0777);
		p->l = 0;
		p->k = 0;
}

int	main(int ac, char **av)
{
	t_moves	p;

	if (ac == 2)
	{
		ft_checkmap(&p, av);
		ft_var_value(&p, av[1]);
		p.str = get_next_line(p.fd);
		while (p.str)
		{
			p.map = ft_strj(p.map, p.str);
			free(p.str);
			p.str = get_next_line(p.fd);
		}
		p.coin_nbr = coin_nbr(&p);
		p.map2 = ft_split(p.map, '\n');
		all_is_good(&p, av[1]);
		p.mlx = mlx_init();
		p.win = mlx_new_window(p.mlx, ft_width(av[1]), ft_l(av[1]), "so_long");
		ft_graphic_map(&p, av[1]);
		mlx_hook(p.win, 2, 0, moves, &p);
		mlx_loop(p.mlx);
	}
	else
		ft_printf("Invalid number of argement\n");
}
