/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:53:47 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/09/06 11:37:53 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	move(t_data *data, double x, double y)
{
	static double	fract_x = 0.0;
	static double	fract_y = 0.0;
	double			int_x;
	double			int_y;

	if (x == 0 && y == 0)
		return ;
	fract_x += x;
	fract_y += y;
	int_x = fract_x;
	int_y = fract_y;
	if (int_x != 0)
	{
		data->pos_x += int_x / (S_HEIGHT / 50 + 0.0);
		data->minimap->instances[0].x -= int_x;
		fract_x -= int_x;
	}
	if (int_y != 0)
	{
		data->pos_y += int_y / (S_HEIGHT / 50 + 0.0);
		data->minimap->instances[0].y -= int_y;
		fract_y -= int_y;
	}
}

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
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->p_angle -= 1.0 * (M_PI / 180);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		data->p_angle += 1.0 * (M_PI / 180);
	if (data->p_angle < 0 * (M_PI / 180))
		data->p_angle += 360 * (M_PI / 180);
	if (data->p_angle >= 360 * (M_PI / 180))
		data->p_angle -= 360 * (M_PI / 180);
}
