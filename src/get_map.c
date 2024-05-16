/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:12:27 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/05/16 15:59:45 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	save_texture(t_data *data, char **split, int i)
{
	if (!ft_strncmp(split[i], "NO", 2) && data->no == NULL)
		data->no = ft_split(split[i], ' ');
	else if (!ft_strncmp(split[i], "SO", 2) && data->so == NULL)
		data->so = ft_split(split[i], ' ');
	else if (!ft_strncmp(split[i], "WE", 2) && data->we == NULL)
		data->we = ft_split(split[i], ' ');
	else if (!ft_strncmp(split[i], "EA", 2) && data->ea == NULL)
		data->ea = ft_split(split[i], ' ');
	else if (!ft_strncmp(split[i], "F", 1) && data->f == NULL)
		data->f = ft_split(split[i], ' ');
	else if (!ft_strncmp(split[i], "C", 1) && data->c == NULL)
		data->c = ft_split(split[i], ' ');
}

static int	get_texture(t_data *data, char *line, int i, char **split)
{
	split = ft_split(line, '\n');
	while (split[++i] != NULL)
		save_texture(data, split, i);
	if ((data->no == NULL || data->so == NULL || data->we == NULL \
		|| data->ea == NULL || data->f == NULL || data->c == NULL)
		|| (data->no[1] == NULL || data->so[1] == NULL || data->we[1] == NULL \
		|| data->ea[1] == NULL || data->f[1] == NULL || data->c[1] == NULL))
		return (free_split(split), free(line),
			print_error("can't get textures"));
	if (check_colors(data->c[1], 0) == 1 || check_colors(data->f[1], 0) == 1
		|| check_digit(data->c[1]) == 1 || check_digit(data->f[1]) == 1)
		return (free_split(split), free(line),
			print_error("incorrect color argument"));
	return (free_split(split), free(line), EXIT_SUCCESS);
}

static int	read_map(t_data *data, int fd, char *line, char *full_map)
{
	while (line != NULL)
	{
		full_map = ft_strjoin_gnl (full_map, line);
		if (!full_map)
			return (EXIT_FAILURE);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (full_map)
	{
		data->map = ft_split(full_map, '\n');
		if (!data->map)
			return (print_error("can't save map"));
	}
	free(full_map);
	if (data->map == NULL)
		return (print_error("empty map"));
	return (EXIT_SUCCESS);
}

static int	read_file(t_data *data, int fd, char **texture, char *line)
{
	while (line && line[0] != ' ' && line[0] != '1')
	{
		if (((!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2) \
			|| !ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2))
				&& (line[2] == ' ' || (line[2] >= 9 && line[2] <= 13)))
			|| ((!ft_strncmp(line, "F", 1) || !ft_strncmp(line, "C", 1))
				&& (line[1] == ' ' || (line[1] >= 9 && line[1] <= 13))))
		{
			*texture = ft_strjoin_gnl(*texture, line);
			data->nbr_text++;
		}
		else if (line[0] != '\n')
		{
			free(line);
			return (print_error("invalid element in texture"));
		}
		free(line);
		line = get_next_line(fd);
	}
	if (read_map(data, fd, line, NULL) == 1)
	{
		free(line);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	get_map(t_data *data, char *str, char *line)
{
	int		fd;
	char	*texture;

	fd = open(str, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
		return (print_error("empty file"));
	texture = NULL;
	if (fd == -1)
		return (print_error("can't open file"));
	if (read_file(data, fd, &texture, line) == 1)
	{
		free(texture);
		return (EXIT_FAILURE);
	}
	if (data->nbr_text != 6)
	{
		free(texture);
		return (print_error("nbr_text incorrect"));
	}
	if (get_texture(data, texture, -1, NULL) == 1)
		return (EXIT_FAILURE);
	if (ft_strrlen(data->c) != 2 || ft_strrlen(data->f) != 2)
		return (print_error("incorrect color argument"));
	return (EXIT_SUCCESS);
}
