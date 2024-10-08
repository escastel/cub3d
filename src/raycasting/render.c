/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:40:53 by escastel          #+#    #+#             */
/*   Updated: 2024/09/16 12:50:58 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	draw_wall(t_data *data, t_ray ray, double top, double bot)
{
	double			x;
	double			y;
	double			f;
	unsigned long	color;
	mlx_texture_t	*tx;

	tx = get_wall(data, ray.wall_o);
	f = (double)tx->height / data->w_height;
	y = 0;
	if (data->w_height > S_HEIGHT)
		y = (data->w_height - S_HEIGHT) / 2 * f;
	x = get_x(ray, tx);
	while (top < bot)
	{
		color = get_color(tx, (int)x, (int)y);
		if (!(data->rays < 0 || data->rays >= S_WIDTH
				|| top < 0 || top >= S_HEIGHT))
			mlx_put_pixel(data->raycasting, data->rays, top, color);
		y += f;
		top++;
	}
}

static void	draw_floor_sky(t_data *data, double top, double bot)
{
	int	copy;

	copy = 0;
	while (copy < top)
	{
		if (!(data->rays < 0 || data->rays >= S_WIDTH
				|| copy < 0 || copy >= S_HEIGHT))
			mlx_put_pixel(data->raycasting, data->rays, copy, data->sky);
		copy++;
	}
	copy = bot;
	while (copy < S_HEIGHT)
	{
		if (!(data->rays < 0 || data->rays >= S_WIDTH
				|| copy < 0 || copy >= S_HEIGHT))
			mlx_put_pixel(data->raycasting, data->rays, copy, data->floor);
		copy++;
	}
}

void	scale_wall(t_data *data, t_ray ray)
{
	double	top;
	double	bot;

	data->w_height = ((S_WIDTH / 2) / tan(correct_angle(data->fov_rd / 2))) \
	/ ray.distance;
	top = (S_HEIGHT / 2) - (data->w_height / 2);
	if (top < 0)
		top = 0;
	bot = (S_HEIGHT / 2) + (data->w_height / 2);
	if (bot > S_HEIGHT)
		bot = S_HEIGHT;
	draw_floor_sky(data, top, bot);
	draw_wall(data, ray, top, bot);
}
