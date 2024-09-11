/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:33:48 by escastel          #+#    #+#             */
/*   Updated: 2024/09/11 13:24:20 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static t_ray	init_ray(t_data *data, double angle)
{
	t_ray	ray;

	ray.distance = 0;
	ray.p_angle = data->p_angle;
	ray.ray_angle = angle;
	ray.origin.x = data->pos_x;
	ray.origin.y = data->pos_y;
	ray.cross_x.y = orientation(angle, 'y');
	ray.cross_y.x = orientation(angle, 'x');
	ray.cross_x.x = ray.cross_x.y / tan(angle);
	ray.cross_y.y = ray.cross_y.x * tan(angle);
	return (ray);
}

static t_coord	first_step(t_ray ray, char c)
{
	t_coord	pos;

	pos.x = ray.origin.x;
	pos.y = ray.origin.y;
	if (c == 'x')
	{
		if (ray.cross_x.y > 0)
			pos.y = ceil(pos.y);
		else
			pos.y = floor(pos.y);
		pos.x += (pos.y - ray.origin.y) / tan(ray.ray_angle);
	}
	if (c == 'y')
	{
		if (ray.cross_y.x > 0)
			pos.x = ceil(pos.x);
		else
			pos.x = floor(pos.x);
		pos.y += (pos.x - ray.origin.x) * tan(ray.ray_angle);
	}
	return (pos);
}

static double	search_walls(t_data *data, t_ray ray, char c)
{
	t_coord	pos;

	pos = first_step(ray, c);
	while (!collition_walls(data, ray, pos, c))
	{
		if (c == 'x')
		{
			pos.x += ray.cross_x.x;
			pos.y += ray.cross_x.y;
		}
		if (c == 'y')
		{
			pos.x += ray.cross_y.x;
			pos.y += ray.cross_y.y;
		}
	}
	return (get_distance(ray, pos));
}

static t_ray	throw_ray(t_data *data, double angle)
{
	t_ray	ray;
	double	distance_x;
	double	distance_y;

	ray = init_ray(data, angle);
	distance_x = search_walls(data, ray, 'x');
	distance_y = search_walls(data, ray, 'y');
	if (distance_x < distance_y)
	{
		ray.distance = distance_x;
		if (ray.cross_x.y < 0)
			ray.wall_o = 'S';
		else
			ray.wall_o = 'N';
	}
	else
	{
		ray.distance = distance_y;
		if (ray.cross_y.x < 0)
			ray.wall_o = 'E';
		else
			ray.wall_o = 'W';
	}
	return (ray);
}

void	ray_loop(t_data *data)
{
	t_ray	ray;
	double	angle;

	data->rays = 0;
	angle = data->p_angle - (data->fov_rd / 2);
	angle = correct_angle(angle);
	while (data->rays < S_WIDTH)
	{
		ray = throw_ray(data, angle);
		scale_wall(data, ray);
		angle = correct_angle(angle);
		angle += data->fov_rd / S_WIDTH;
		angle = correct_angle(angle);
		data->rays++;
	}
}
