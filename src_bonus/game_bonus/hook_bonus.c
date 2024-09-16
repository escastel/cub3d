/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:44:23 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/09/16 12:53:04 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

static void	clean_wall(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < S_HEIGHT)
	{
		x = 0;
		while (x < S_WIDTH)
		{
			if (!(y > S_HEIGHT / 50 && x < S_HEIGHT / 50 * 8.2
					&& y < S_HEIGHT / 50 * 8.2 && x > S_HEIGHT / 50))
				mlx_put_pixel(data->raycasting, x, y, TRANSPARENT);
			x++;
		}
		y++;
	}
}

static void	move_camara_mouse(t_data *data)
{
	mlx_set_cursor_mode(data->mlx, 0x00034002);
	mlx_get_mouse_pos(data->mlx, &data->m_x, &data->m_y);
	data->p_angle += correct_angle(((data->m_x - (S_WIDTH / 2)) / 50)
			* (M_PI / 180));
	mlx_set_mouse_pos(data->mlx, S_WIDTH / 2, S_HEIGHT / 2);
}

void	hook(void *param)
{
	t_data	*data;

	data = param;
	clean_wall(data);
	ray_loop(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	player_move(data);
	move_camara_mouse(data);
}
