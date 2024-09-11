/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:49:13 by escastel          #+#    #+#             */
/*   Updated: 2024/09/11 15:10:52 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

void	init_data(t_data *d)
{
	d->map = NULL;
	d->no = NULL;
	d->so = NULL;
	d->we = NULL;
	d->ea = NULL;
	d->f = NULL;
	d->c = NULL;
	d->floor = 0;
	d->sky = 0;
	d->nbr_text = 0;
	d->nbr_player = 0;
	d->width_map = 0;
	d->high_map = 0;
	d->fov_rd = FOV * (M_PI / 180);
	d->pos_x = 0;
	d->pos_y = 0;
	d->p_angle = 0;
}
