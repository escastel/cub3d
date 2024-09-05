/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:44:23 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/09/04 18:34:40 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	clean_wall(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < S_WIDTH)
	{
		x = 0;
		while (x < S_WIDTH)
		{
			mlx_put_pixel(/*imagen*/, x, y, TRANSPARENT);
			mlx_put_pixel(/*imagen*/, x, y, TRANSPARENT);
			x++;
		}
		y++;
	}
}

void	hook(void *param)
{
	t_data	*data;

	data = param;
	ray_loop(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	player_move(data);
}
