/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:59:56 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/09/06 15:59:24 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

int	init_game(t_data *data)
{
	data->p_angle = get_player_angle(data->orientation);
	data->mlx = mlx_init(S_WIDTH, S_HEIGHT, "cub3D", false);
	if (!data->mlx)
		return (EXIT_FAILURE);
	put_minimap(data);
	mlx_loop_hook(data->mlx, &hook, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	return (EXIT_SUCCESS);
}
