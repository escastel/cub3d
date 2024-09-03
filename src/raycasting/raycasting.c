/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:33:48 by escastel          #+#    #+#             */
/*   Updated: 2024/09/03 13:27:46 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

t_ray	init_ray(t_data *data, double angle)
{
	t_ray	ray;

	ray.flag = 0;
	ray.distance = 0;
	ray.ray_angle = angle;
	ray.origin.x = data->pos_x;
	ray.origin.y = data->pos_y;
	ray.cross_x.y = orientation(angle, 'y');
	ray.cross_y.x = orientation(angle, 'x');
	ray.cross_x.x = ray.cross_x.y / tan(angle);
	ray.cross_y.y = ray.cross_y.x * tan(angle);
}

t_coord	first_step(t_ray ray, char c)
{
	t_coord	pos;

	if (c == 'x')
	{
		ray.cross_x.y
	}
}

double	get_distance(t_data *data, t_ray ray, char c)
{
	t_coord	pos;

	pos = first_step(ray, c);
}

void	throw_ray(t_data *data, double angle)
{
	t_ray	ray;
	double	distance_x;
	double	distance_y;
	
	ray = init_ray(data, angle);
	distance_x = get_distance(data, ray, 'x');
	distance_y = get_distance(data, ray, 'y');
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
}
