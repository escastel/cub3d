/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:40:53 by escastel          #+#    #+#             */
/*   Updated: 2024/09/11 14:55:22 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static int	get_color(t_ray ray)
{
	if (ray.wall_o == 'N')
		return (0x007F0040); // GREEN
	if (ray.wall_o == 'S') // BLUE
		return (0xADD8E640);
	if (ray.wall_o == 'W') //PINK
		return (0xFFC0CB40);
	if (ray.wall_o == 'E') // RED
		return (0xFF000040);
	return (-1);
}

static void	draw_wall(t_data *data, t_ray ray, double top, double bot)
{
	int	color;

	color = get_color(ray);
	if (color == -1)
		return ;
	while (top < bot)
	{
		if (!(data->rays < 0 || data->rays >= S_WIDTH
				|| top < 0 || top >= S_HEIGHT))
			mlx_put_pixel(data->raycasting, data->rays, top, color);
		top++;
	}
}

static void	draw_floor_sky(t_data *data, double top, double bot)
{
	int	copy;

	copy = 0;
	while (copy < top) // SKY
	{
		if (!(data->rays < 0 || data->rays >= S_WIDTH
				|| copy < 0 || copy >= S_HEIGHT))
			mlx_put_pixel(data->raycasting, data->rays, copy, data->sky);
		copy++;
	}
	copy = bot;
	while (copy < S_HEIGHT) // FLOOR
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
	double	w_height;

	ray.distance *= cos(correct_angle(ray.ray_angle - ray.p_angle));
	w_height = (1 / ray.distance) * ((S_WIDTH / 2) / tan(data->fov_rd / 2));
	top = (S_HEIGHT / 2) - (w_height / 2);
	if (top < 0)
		top = 0;
	bot = (S_HEIGHT / 2) + (w_height / 2);
	if (bot > S_HEIGHT)
		bot = S_HEIGHT;
	draw_wall(data, ray, top, bot);
	draw_floor_sky(data, top, bot);
}
