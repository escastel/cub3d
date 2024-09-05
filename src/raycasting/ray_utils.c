/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:11:56 by escastel          #+#    #+#             */
/*   Updated: 2024/09/05 18:58:06 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

double	get_player_angle(char c)
{
	double	angle;

	if (c == 'N')
		angle = 270 * (M_PI / 180);
	if (c == 'S')
		angle = 90 * (M_PI / 180);
	if (c == 'W')
		angle = 180 * (M_PI / 180);
	if (c == 'E')
		angle = 360 * (M_PI / 180);
	return (angle);
}

double	orientation(double angle, char c)
{
	if (c == 'x')
		if (angle < (3 * M_PI / 2) && angle > (M_PI / 2))
			return (-1);
	if (c == 'y')
		if (angle > M_PI && angle < (2 * M_PI))
			return (-1);
	return (1);
}

double	correct_angle(double angle)
{
	if (angle < 0)
		angle += 360 * (M_PI / 180);
	if (angle >= (360 * (M_PI / 180)))
		angle -= 360 * (M_PI / 180);
	return (angle);
}

double	get_distance(t_ray ray, t_coord wall)
{
	t_coord	diff;
	/* double	delta;
	double	distance; */
	double	hypotenuse;

	diff.x = wall.x - ray.origin.x;
	diff.y = wall.y - ray.origin.y;
	hypotenuse = sqrt(pow(diff.x, 2) + pow(diff.y, 2));
	/* delta = ray.p_angle - ray.ray_angle;
	distance = hypotenuse * cos(delta); */
	return (hypotenuse);
}

int	collition_walls(t_data *data, t_ray ray, t_coord pos, char c)
{
	int	x;
	int	y;

	x = (int)pos.x;
	y = (int)pos.y;
	if (c == 'x')
	{
		if (sin(ray.ray_angle) < 0)
			y -= 1;
	}
	if (c == 'y')
	{
		if (cos(ray.ray_angle) < 0)
			x -= 1;
	}
	if (x < 0 || y < 0 || y >= data->high_map || x > data->width_map)
		return (1);
	if (data->map[y][x] == '1')
		return (1);
	return (0);
}
