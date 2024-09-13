/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_colors_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:38:00 by escastel          #+#    #+#             */
/*   Updated: 2024/09/13 17:19:42 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

// PUEDE TENER LEAKS YA QUE NO HEMOS LIBERADO EL DOBLE PUNTERO 

int	save_colors(t_data	*data)
{
	int	r;
	int	g;
	int	b;

	data->f = ft_split(data->f[1], ',');
	data->c = ft_split(data->c[1], ',');
	r = ft_atoi(data->f[0]);
	g = ft_atoi(data->f[1]);
	b = ft_atoi(data->f[2]);
	data->floor = r << 24 | g << 16 | b << 8 | 0xFF;
	r = ft_atoi(data->c[0]);
	g = ft_atoi(data->c[1]);
	b = ft_atoi(data->c[2]);
	data->sky = r << 24 | g << 16 | b << 8 | 0xFF;
	return (0);
}
