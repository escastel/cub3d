/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:42:15 by escastel          #+#    #+#             */
/*   Updated: 2024/07/24 14:29:11 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	orientation(t_player p)
{
	if (p.orientation == 'N')
	{
		p.dir_y = -1.0;
		p.p_angle = 270 * (M_PI / 180);
	}
	if (p.orientation == 'S')
	{
		p.dir_y = 1.0;
		p.p_angle = 90 * (M_PI / 180);
	}
	if (p.orientation == 'W')
	{
		p.dir_x = -1.0;
		p.p_angle = 180 * (M_PI / 180);
	}
	if (p.orientation == 'E')
	{
		p.dir_x = 0.0;
		p.p_angle = 360 * (M_PI / 180);
	}
	
}

int	ray_loop(t_data *data)
{
	double	h_inter;
	double	v_inter;
	int		rays;

	rays = 0;
	orientation(data->player);
	data->ray->ray_angle = data->player.p_angle - (data->player.fov_rd / 2); // FIRST RAY
	while (rays < S_WIDTH)
	{
		data->ray->flag = 0;
	}
	return (0);
}