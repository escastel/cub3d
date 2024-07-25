/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:49:13 by escastel          #+#    #+#             */
/*   Updated: 2024/07/25 12:19:56 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	init_player(t_data *d)
{
	d->player.pos_x = 0.0;
	d->player.pos_y = 0.0;
	d->player.dir_x = 0.0;
	d->player.dir_y = 0.0;
	d->player.fov_rd = FOV * (M_PI / 180);
	d->player.p_angle = 0.0;
	d->player.orientation = '\0';
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
	init_player(d);
	d->ray = ft_calloc(1, sizeof(t_ray));
	init_ray(d->ray);
}
