/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_wall_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:08:51 by escastel          #+#    #+#             */
/*   Updated: 2024/09/13 16:11:57 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

mlx_texture_t	*get_wall(t_data *data, char o)
{
	if (o == 'N')
		return (data->wall_n);
	if (o == 'S')
		return (data->wall_s);
	if (o == 'W')
		return (data->wall_w);
	return (data->wall_e);
}

double	get_x(t_ray ray, mlx_texture_t *tx)
{
	double	x;

	x = 0;
	if (ray.wall_o == 'E' || ray.wall_o == 'W')
		x = fmod(ray.collition.y, 1.0) * tx->width;
	else
		x = fmod(ray.collition.x, 1.0) * tx->width;
	return (x);
}

unsigned long	get_color(mlx_texture_t *tx, int x, int y)
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
	uint32_t	p;

	if ((uint32_t)x >= tx->width)
		x = tx->width - 1;
	if ((uint32_t)y >= tx->height)
		y = tx->height - 1;
	p = 4 * x + (4 * y * tx->width);
	if (p <= tx->height * tx->width * tx->bytes_per_pixel)
	{
		r = tx->pixels[p];
		g = tx->pixels[p + 1];
		b = tx->pixels[p + 2];
		return (r << 24 | g << 16 | b << 8 | 0xFF);
	}
	return (0);
}