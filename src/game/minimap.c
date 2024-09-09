/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:02:23 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/09/09 15:51:45 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	draw_map(t_data *data)
{
	data->raycasting = mlx_new_image(data->mlx, S_WIDTH, S_HEIGHT);
	if (!data->raycasting)
	{
		ft_printf("Error: Can't create image\n");
		return ;
	}
	mlx_image_to_window(data->mlx, data->raycasting, 0, 0);
}
