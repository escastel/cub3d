/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:08:51 by escastel          #+#    #+#             */
/*   Updated: 2024/09/11 19:47:44 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

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

int	get_color(mlx_texture_t *tx, int x, int y)
{
	unsigned int	color;
	uint32_t		*a;
	int				c;

	a = (uint32_t *)tx->pixels;
	c = a[y * tx->width + x];
	color = 0;
	color |= (c & 0xFF) << 24;
	color |= (c & 0xFF00) << 8;
	color |= (c & 0xFF0000) >> 8;
	color |= (c & 0xFF000000) >> 24;
	return (color);
}