/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:30:36 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/09/06 16:00:45 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

int	print_error(char *str)
{
	ft_printf("Error: %s\n", str);
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
	free(d);
}
