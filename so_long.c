/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 01:03:43 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/19 03:49:06 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./libft/libft.h"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		t_moves	param;

		param.mv_nb = 0;
		ft_checkmap(&param, av);
		param.mlx = mlx_init();
		param.win = mlx_new_window(param.mlx, ft_map_3ord(av[1]), ft_map_tol(av[1]), "game");
		ft_graphic_map(&param, av[1]);
		mlx_key_hook(param.win, moves, &param);
		mlx_loop(param.mlx);
	}
	else
		printf("Invalid number of argement\n");
}
