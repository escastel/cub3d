/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:49:13 by escastel          #+#    #+#             */
/*   Updated: 2024/07/24 14:28:05 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	init_player(t_player p)
{
	p.pos_x = 0.0;
	p.pos_y = 0.0;
	p.dir_x = 0.0;
	p.dir_y = 0.0;
	p.fov_rd = FOV * (M_PI / 180);
	p.p_angle = 0.0;
	p.orientation = '\0';
}

void	init_ray(t_ray *ray)
{
	ray->ray_angle = 0.0;
	ray->distance = 0.0;
	ray->flag = 0;
}
void	init_data(t_data *d)
{
	d->map = NULL;
	d->no = NULL;
	d->so = NULL;
	d->we = NULL;
	d->ea = NULL;
	d->f = NULL;
	d->c = NULL;
	d->nbr_text = 0;
	d->nbr_player = 0;
	d->width_map = 0;
	d->high_map = 0;
	init_player(d->player);
	d->ray = ft_calloc(1, sizeof(t_ray));
	init_ray(d->ray);
}