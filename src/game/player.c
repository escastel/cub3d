/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:53:47 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/09/05 13:28:28 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	player_move(t_data *data)
{
	double	angle;

	angle = data->p_angle;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		move(data, cos(angle), sin(angle));
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move(data, -cos(angle), -sin(angle));
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		move(data, cos(angle - M_PI / 2), sin(angle - M_PI / 2));
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		move(data, cos(angle + M_PI / 2), sin(angle + M_PI / 2));
}
