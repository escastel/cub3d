/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:40:53 by escastel          #+#    #+#             */
/*   Updated: 2024/09/11 19:55:58 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	draw_wall(t_data *data, t_ray ray, double top, double bot)
{
	double		x;
	double		y;
	double		f;
	int			color;
	mlx_texture_t	*tx;

	tx = get_wall(data, ray.wall_o);
	f = (double)tx->height / data->w_height;
	y = (top - (S_HEIGHT + data->w_height) / 2) * f;
	if (y < 0)
		y = 0;
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

	ray.distance *= cos(correct_angle(ray.ray_angle - ray.p_angle));
	data->w_height = (1 / ray.distance) * ((S_WIDTH / 2) / tan(data->fov_rd / 2));
	top = (S_HEIGHT / 2) - (data->w_height / 2);
	if (top < 0)
		top = 0;
	bot = (S_HEIGHT / 2) + (data->w_height / 2);
	if (bot > S_HEIGHT)
		bot = S_HEIGHT;
	draw_wall(data, ray, top, bot);
	draw_floor_sky(data, top, bot);
}
