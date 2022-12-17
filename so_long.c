/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 01:03:43 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/17 01:33:47 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
# include "./libft/libft.h"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		t_moves param;

		param.moves_number = 0;
		ft_checkmap(&param, av);
		param.mlx= mlx_init();
		param.win = mlx_new_window(param.mlx, 500, 500, "game");
		ft_show(&param);
		mlx_key_hook(param.win, moves, &param);
		mlx_loop(param.mlx);
	}
	else
		printf("Invalid number of argement\n");
}