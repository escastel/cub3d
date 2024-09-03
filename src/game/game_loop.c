/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:59:56 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/09/03 16:41:23 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	init_game(t_data *data)
{
	data->mlx = mlx_init(S_WIDTH, S_HEIGHT, "cub3D", false);
	if (!data->mlx)
		return (EXIT_FAILURE);
	put_minimap(data);
	//mlx_key_hook(data->mlx, &hook, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	return (EXIT_SUCCESS);
}
