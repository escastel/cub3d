/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:02:23 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/09/03 17:45:54 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	paint_square(mlx_image_t *minimap, int x, int y, int color)
{
	int	size_x;
	int	size_y;

	size_x = x + S_HEIGHT / 50;
	size_y = y + S_HEIGHT / 50;
	while (y <= size_y)
	{
		x = size_x - S_HEIGHT / 50;
		while (x <= size_x)
			mlx_put_pixel(minimap, x++, y, color);
		y++;
	}
}

static void	paint_player(t_data *data, int x, int y)
{
	int	size_x;
	int	size_y;

	size_x = x + (S_HEIGHT / 50 / 2);
	size_y = y + (S_HEIGHT / 50 / 2);
	while (y < size_y)
	{
		x = size_x - (S_HEIGHT / 50 / 2);
		while (x < size_x)
		{
			mlx_put_pixel(data->player, x, y, WHITE);
			x++;
		}
		y++;
	}
}

void	paint_minimap(t_data *data, mlx_image_t *minimap)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				paint_square(minimap, j * S_HEIGHT / 50,
					i * S_HEIGHT / 50, BLACK);
			else if (data->map[i][j] == ' ')
				paint_square(minimap, j * S_HEIGHT / 50,
					i * S_HEIGHT / 50, TRANSPARENT);
			else
				paint_square(minimap, j * S_HEIGHT / 50,
					i * S_HEIGHT / 50, PINK);
			j++;
		}
		i++;
	}
}

void	put_minimap(t_data *data)
{
	data->minimap = mlx_new_image(data->mlx, data->width_map * S_HEIGHT / 25,
			data->high_map * S_HEIGHT / 25);
	data->player = mlx_new_image(data->mlx, data->width_map * S_HEIGHT / 25,
			data->high_map * S_HEIGHT / 25);
	paint_minimap(data, data->minimap);
	paint_player(data, S_HEIGHT / 50, S_HEIGHT / 50);
	mlx_image_to_window(data->mlx, data->minimap, 0, 0);
	mlx_image_to_window(data->mlx, data->player,
		(data->pos_x - 1) * S_HEIGHT / 50, (data->pos_y - 1) * S_HEIGHT / 50);
}
