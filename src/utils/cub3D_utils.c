/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:30:36 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/07/25 12:05:47 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

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
