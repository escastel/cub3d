/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:02:23 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/09/05 13:27:07 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	paint_square(mlx_image_t *minimap, int i, int j, int color)
{
	int	size_i;
	int	size_j;

	size_i = i + S_HEIGHT / 50;
	size_j = j + S_HEIGHT / 50;
	while (j <= size_j)
	{
		i = size_i - S_HEIGHT / 50;
		while (i <= size_i)
		{
			mlx_put_pixel(minimap, i, j, color);
			i++;
		}
		j++;
	}
}

static void	paint_player(t_data *data, int i, int j)
{
	int	size_i;
	int	size_j;

	size_i = i + (S_HEIGHT / 50 / 2);
	size_j = j + (S_HEIGHT / 50 / 2);
	while (j < size_j)
	{
		i = size_i - (S_HEIGHT / 50 / 2);
		while (i < size_i)
		{
			mlx_put_pixel(data->player, i, j, WHITE);
			i++;
		}
		j++;
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
// PONER PARCHES DE ERRORRRR
void	put_minimap(t_data *data)
{
	data->player = mlx_new_image(data->mlx, data->width_map * S_HEIGHT / 25,
			data->high_map * S_HEIGHT / 25);
	data->minimap = mlx_new_image(data->mlx, data->width_map * S_HEIGHT / 25,
			data->high_map * S_HEIGHT / 25);
	paint_minimap(data, data->minimap);
	mlx_image_to_window(data->mlx, data->minimap, 0, 0);
	data->player = mlx_new_image(data->mlx, data->width_map * S_HEIGHT / 25,
			data->high_map * S_HEIGHT / 25);
	paint_player(data, S_HEIGHT / 50, S_HEIGHT / 50);
	mlx_image_to_window(data->mlx, data->player,
		(data->pos_x - 1) * S_HEIGHT / 50, (data->pos_y - 1) * S_HEIGHT / 50);
	data->raycasting = mlx_new_image(data->mlx, S_WIDTH, S_HEIGHT);
	if (!data->raycasting)
		ft_printf("ERROR\n");
	mlx_image_to_window(data->mlx, data->raycasting, 0, 0);
}
