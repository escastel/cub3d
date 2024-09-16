/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_colors_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:38:00 by escastel          #+#    #+#             */
/*   Updated: 2024/09/16 14:27:55 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

int	save_colors(t_data	*data)
{
	int		r;
	int		g;
	int		b;
	char	**aux;

	aux = ft_split(data->f[1], ',');
	free_split(data->f);
	data->f = aux;
	aux = ft_split(data->c[1], ',');
	free_split(data->c);
	data->c = aux;
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
