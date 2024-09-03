/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:59:56 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/07/25 15:08:39 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	init_game(t_data *data)
{
	data->mlx = mlx_init(S_WIDTH, S_HEIGHT, "cub3D", false);
	if (!data->mlx)
		return (EXIT_FAILURE);
	//mlx_loop_hook(data->mlx, /*funcion loop,*/ data);
	/* mlx_key_hook(data->mlx, funcion de las teclas, data); */
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	return (EXIT_SUCCESS);
}
