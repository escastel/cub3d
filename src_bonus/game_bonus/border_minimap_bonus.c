/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_minimap_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:52:46 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/09/09 12:06:47 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

void	draw_border(t_data *data)
{
	int	i;
	int	j;

	i = S_HEIGHT / 50;
	while (i < S_HEIGHT)
	{
		j = S_HEIGHT / 50;
		while (j < S_HEIGHT)
		{
			if ((j < S_HEIGHT / 50 * 1.2 && i <= S_HEIGHT / 50 * 8.2)
				|| (i < S_HEIGHT / 50 * 1.2 && j <= S_HEIGHT / 50 * 8.2))
				mlx_put_pixel (data->border, i, j, BLACK);
			if ((j > S_HEIGHT / 50 && i > S_HEIGHT / 50)
				&& (j >= S_HEIGHT / 50 * 8 || i >= S_HEIGHT / 50 * 8)
				&& (j <= S_HEIGHT / 50 * 8.2 && i <= S_HEIGHT / 50 * 8.2))
				mlx_put_pixel(data->border, i, j, BLACK);
			j++;
		}
		i++;
	}
}
