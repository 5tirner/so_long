/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 01:03:43 by zasabri           #+#    #+#             */
/*   Updated: 2022/12/16 22:35:35 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

int	main(void)
{
	t_moves param;

	param.moves_number = 0;
	param.mlx= mlx_init();
	param.win = mlx_new_window(param.mlx, 500, 500, "game");
	ft_show(&param);
	mlx_key_hook(param.win, moves, &param);
	mlx_loop(param.mlx);
}