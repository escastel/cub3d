/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:11:56 by escastel          #+#    #+#             */
/*   Updated: 2024/09/03 13:26:34 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/* int	check_walls(t_data *data, int x, int y)
{
	if (data->map[y][x] = '1')
		return (1);
	return (0);
}

int	check_limits(t_data *data, int next_x, int next_y)
{
	if (next_x < 0 || next_y < 0 || next_x >= data->width_map || next_y >= data->high_map)
		return (1);
	return (0);

} */
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
