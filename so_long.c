/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 01:03:43 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/22 11:34:27 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./libft/libft.h"

int	main(int ac, char **av)
{
	t_moves	p;

	if (ac == 2)
	{
		p.mv_nb = 0;
		p.k = 0;
		ft_checkmap(&p, av);
		p.mlx = mlx_init();
		p.win = mlx_new_window(p.mlx, ft_width(av[1]), ft_l(av[1]), "game");
		ft_graphic_map(&p, av[1]);
		mlx_key_hook(p.win, moves, &p);
		mlx_loop(p.mlx);
	}
	else
		ft_printf("Invalid number of argement\n");
}
