/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:35:03 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/09/06 16:00:19 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

int	check_close_map(t_data *data, int i)
{
	int	j;

	j = 0;
	while (data->map[i][j] != '\0')
	{
		if (data->map[i][j] == '1')
			break ;
		else if (data->map[i][j] == '0' || data->map[i][j] == 'W'
			|| data->map[i][j] == 'N' || data->map[i][j] == 'E'
			|| data->map[i][j] == 'S')
			return (print_error("unclosed map"));
		j++;
	}
	j = ft_strlen(data->map[i]) - 1;
	while (j > 0)
	{
		if (data->map[i][j] == '1')
			break ;
		else if (data->map[i][j] == '0' || data->map[i][j] == 'W'
			|| data->map[i][j] == 'N' || data->map[i][j] == 'E'
			|| data->map[i][j] == 'S')
			return (print_error("unclosed map"));
		j--;
	}
	return (EXIT_SUCCESS);
}

int	check_digit(char *str)
{
	int		i;
	int		j;
	char	**split;

	if (str == NULL)
		return (EXIT_FAILURE);
	i = 0;
	split = ft_split(str, ',');
	while (split[i] != NULL)
	{
		j = -1;
		while (split[i][++j] != '\0')
		{
			if (ft_isdigit(split[i][j]) == EXIT_FAILURE)
			{
				free_split(split);
				return (EXIT_FAILURE);
			}
		}
		i++;
	}
	free_split(split);
	if (i != 3)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_colors(char *str, int flag)
{
	char	**split;
	int		i;

	split = NULL;
	i = -1;
	while (str[++i] != '\0')
		if (str[i] == ',')
			flag++;
	if (flag != 2)
		return (EXIT_FAILURE);
	split = ft_split(str, ',');
	i = -1;
	while (split[++i] != NULL)
	{
		if (ft_atoi(split[i]) > 255 || ft_atoi(split[i]) < 0)
			return (free_split(split), EXIT_FAILURE);
	}
	free_split(split);
	return (EXIT_SUCCESS);
}

int	check_arg(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (str[i - 1] == 'b' && str[i - 2] == 'u' && str[i - 3] == 'c'
		&& str[i - 4] == '.')
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}
