/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:30:36 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/09/16 13:17:09 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	print_error(t_data *data, char *str)
{
	ft_printf("Error: %s\n", str);
	free_all(data);
	return (EXIT_FAILURE);
}

int	ft_strrlen(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
void	free_canvas(t_data *d)
{
	if (d->wall_n)
		mlx_delete_texture(d->wall_n);
	if (d->wall_s)
		mlx_delete_texture(d->wall_s);
	if (d->wall_w)
		mlx_delete_texture(d->wall_w);
	if (d->wall_e)
		mlx_delete_texture(d->wall_e);
	if (d->raycasting)
		mlx_delete_image(d->mlx, d->raycasting);
}

void	free_all(t_data *d)
{
	if (d->map != NULL)
		free_split(d->map);
	if (d->no != NULL)
		free_split(d->no);
	if (d->so != NULL)
		free_split(d->so);
	if (d->we != NULL)
		free_split(d->we);
	if (d->ea != NULL)
		free_split(d->ea);
	if (d->f != NULL)
		free_split(d->f);
	if (d->c != NULL)
		free_split(d->c);
	free_canvas(d);
	free(d);
}
