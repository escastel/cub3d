/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:02:23 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/09/13 17:08:09 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

static void	center_minimap(mlx_image_t *minimap, mlx_image_t *player)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (player->instances[0].x + x < S_HEIGHT / 20)
		x++;
	while (player->instances[0].y + y < S_HEIGHT / 20)
		y++;
	while (player->instances[0].x + x > S_HEIGHT / 20)
		x--;
	while (player->instances[0].y + y > S_HEIGHT / 20)
		y--;
	player->instances[0].x += x + S_HEIGHT / 50;
	player->instances[0].y += y + S_HEIGHT / 50;
	minimap->instances[0].x += x + S_HEIGHT / 50;
	minimap->instances[0].y += y + S_HEIGHT / 50;
}

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
			mlx_put_pixel(minimap, i++, j, color);
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
			mlx_put_pixel(data->player, i++, j, WHITE);
		j++;
	}
}

static void	paint_minimap(t_data *data, mlx_image_t *minimap)
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

void	draw_map(t_data *data)
{
	data->minimap = mlx_new_image(data->mlx, data->width_map * S_HEIGHT / 25,
			data->high_map * S_HEIGHT / 25);
	data->player = mlx_new_image(data->mlx, data->width_map * S_HEIGHT / 25,
			data->high_map * S_HEIGHT / 25);
	data->raycasting = mlx_new_image(data->mlx, S_WIDTH, S_HEIGHT);
	if (!data->minimap || !data->player || !data->raycasting)
	{
		ft_printf("Error: Can't create image\n");
		return ;
	}
	paint_minimap(data, data->minimap);
	paint_player(data, S_HEIGHT / 50 - (S_HEIGHT / 50 / 4),
		S_HEIGHT / 50 - (S_HEIGHT / 50 / 4));
	mlx_image_to_window(data->mlx, data->minimap, 0, 0);
	mlx_image_to_window(data->mlx, data->player,
		(data->pos_x - 1) * S_HEIGHT / 50, (data->pos_y - 1) * S_HEIGHT / 50);
	center_minimap(data->minimap, data->player);
	mlx_image_to_window(data->mlx, data->raycasting, 0, 0);
	draw_border(data);
}
