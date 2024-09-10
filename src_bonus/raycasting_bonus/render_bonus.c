/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:40:53 by escastel          #+#    #+#             */
/*   Updated: 2024/09/10 16:34:09 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

static int	get_color(t_ray ray)
{
	if (ray.wall_o == 'N')
		return (0x00FF00BF); // GREEN
	if (ray.wall_o == 'S') // BLUE
		return (0x0000FFBF); 
	if (ray.wall_o == 'W') //PINK
		return (0xFFFF00BF);
	if (ray.wall_o == 'E') // RED
		return (0xFF0000BF);
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
			{
				if (!(top > S_HEIGHT / 50 && top < S_HEIGHT / 50 * 8.2 && data->rays > S_HEIGHT / 50 && data->rays < S_HEIGHT / 50 * 8.2))
					mlx_put_pixel(data->raycasting, data->rays, top, color);
			}
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
				{
					if (!(copy > S_HEIGHT / 50 && copy < S_HEIGHT / 50 * 8.2 && data->rays > S_HEIGHT / 50 && data->rays < S_HEIGHT / 50 * 8.2))
						mlx_put_pixel(data->raycasting, data->rays, copy, 0x00FFFFBF);
				}
		copy++;
	}
	copy = bot;
	while (copy < S_HEIGHT) // FLOOR
	{
		if (!(data->rays < 0 || data->rays >= S_WIDTH
				|| copy < 0 || copy >= S_HEIGHT))
				{
					if (!(copy > S_HEIGHT / 50 && copy < S_HEIGHT / 50 * 8.2 && data->rays > S_HEIGHT / 50 && data->rays < S_HEIGHT / 50 * 8.2))
						mlx_put_pixel(data->raycasting, data->rays, copy, 0xFFC0CBBF);
				}
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
