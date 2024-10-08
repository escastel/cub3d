/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:06:26 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/09/16 14:49:40 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

static int	check_walls(t_data *data, int i, int j)
{
	if (((i == 0 || i == data->high_map) || (j == 0 || j == data->width_map))
		&& data->map[i][j] != '1' && data->map[i][j] != ' ')
		return (print_error(data, "Unclosed map"));
	else if (i != 0 && i != data->high_map && ((data->map[i][j] == '0' \
		|| data->map[i][j] == 'N' || data->map[i][j] == 'W'
		|| data->map[i][j] == 'S' || data->map[i][j] == 'E')
		&& (data->map[i + 1][j] == ' ' || data->map[i - 1][j] == ' '
		|| data->map[i][j + 1] == ' ' || data->map[i][j - 1] == ' ')))
		return (print_error(data, "Space inside the map"));
	if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
			|| data->map[i][j] == 'W' || data->map[i][j] == 'E')
	{
		data->pos_x = j + 0.5;
		data->pos_y = i + 0.5;
	}
	return (EXIT_SUCCESS);
}

static int	check_elements(t_data *d)
{
	int	i;
	int	j;

	i = -1;
	while (d->map[++i] != NULL)
	{
		j = -1;
		while (d->map[i][++j] != '\0')
		{
			if (d->map[i][j] != '1' && d->map[i][j] != '0'
				&& d->map[i][j] != 'N' && d->map[i][j] != 'S'
				&& d->map[i][j] != 'W' && d->map[i][j] != 'E'
				&& d->map[i][j] != ' ')
				return (print_error(d, "Incorrect element"));
			if (d->map[i][j] == 'N' || d->map[i][j] == 'S'
				|| d->map[i][j] == 'W' || d->map[i][j] == 'E')
			{
				d->nbr_player++;
				d->orientation = d->map[i][j];
			}
		}
	}
	if (d->nbr_player != 1)
		return (print_error(d, "Multiple player"));
	return (EXIT_SUCCESS);
}

static int	check_sp(t_data *d)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (d->map[++i] && d->map[i])
	{
		while ((d->map[i][j] == ' '
			|| (d->map[i][j] >= 9 && d->map[i][j] <= 13)))
			j++;
		if (i == 0 && (d->map[i][j] != '1'
			|| d->map[i][ft_strlen(d->map[i]) - 1] != '1'))
			return (print_error(d, "Empty map"));
	}
	return (EXIT_SUCCESS);
}

static void	fix_map(t_data *data, int i, int j)
{
	int		len;
	char	*tmp;

	len = 0;
	tmp = NULL;
	while (data->map[++i] != NULL)
		if (ft_strlen(data->map[i]) >= len)
			len = ft_strlen(data->map[i]);
	data->width_map = len - 1;
	i = 0;
	while (data->map[i] != NULL)
	{
		j = ft_strlen(data->map[i]);
		tmp = ft_calloc(1, len + 1);
		ft_strlcpy(tmp, data->map[i], j + 1);
		while (++j <= len)
			tmp = ft_strjoin_gnl(tmp, " ");
		free(data->map[i]);
		data->map[i] = ft_strdup(tmp);
		free(tmp);
		i++;
	}
	data->high_map = i;
}

int	check_map(t_data *data)
{
	int	i;
	int	j;

	if (data->map == NULL)
		return (print_error(data, "Empty map"));
	if (check_sp(data) == 1 || check_elements(data) == 1)
		return (EXIT_FAILURE);
	fix_map(data, -1, 0);
	i = -1;
	while (data->map[++i] != NULL)
	{
		j = -1;
		if (i >= 1 || i <= data->high_map)
			if (check_close_map(data, i) == 1)
				return (EXIT_FAILURE);
		while (data->map[i][++j] != '\0')
		{
			if (check_walls(data, i, j) == 1)
				return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
