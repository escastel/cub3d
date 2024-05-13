/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:35:03 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/05/06 13:20:22 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_digit(char *str)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	split = ft_split(str, ',');
	while (split[i] != NULL)
	{
		j = 0;
		while (split[i][j] != '\0')
		{
			if (ft_isdigit(split[i][j]) == EXIT_FAILURE)
				return (EXIT_FAILURE);
			j++;
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
