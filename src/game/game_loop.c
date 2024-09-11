/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:59:56 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/09/11 19:21:36 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	init_game(t_data *data)
{
	data->wall_n = mlx_load_png(data->no[1]);
	if (!data->wall_n)
		return (EXIT_FAILURE);
	data->wall_s = mlx_load_png(data->so[1]);
	if (!data->wall_s)
		return (EXIT_FAILURE);
	data->wall_w = mlx_load_png(data->we[1]);
	if (!data->wall_w)
		return (EXIT_FAILURE);
	data->wall_e = mlx_load_png(data->ea[1]);
	if (!data->wall_e)
		return (EXIT_FAILURE);
	data->p_angle = get_player_angle(data->orientation);
	data->mlx = mlx_init(S_WIDTH, S_HEIGHT, "cub3D", false);
	if (!data->mlx)
		return (EXIT_FAILURE);
	draw_map(data);
	mlx_loop_hook(data->mlx, &hook, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	return (EXIT_SUCCESS);
}
