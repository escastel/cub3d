/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:36:34 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/05/16 15:16:03 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_leaks()
{
	system("leaks -q cub3d");
}

static void	init_struct(t_data *d)
{
	d->map = NULL;
	d->no = NULL;
	d->so = NULL;
	d->we = NULL;
	d->ea = NULL;
	d->f = NULL;
	d->c = NULL;
	d->nbr_text = 0;
	d->nbr_player = 0;
	d->width_map = 0;
	d->high_map = 0;
	d->p_pos.x = 0;
	d->p_pos.y = 0;
	d->p_pos.orientation = '\0';
}

int	main(int argc, char **argv)
{
	t_data	*data;

	atexit(ft_leaks);
	if (argc != 2 || check_arg(argv[1]) == 1)
		return (print_error("incorrect argument"));
	data = ft_calloc(1, sizeof(t_data));
	init_struct(data);
	if (get_map(data, argv[1], NULL) == 1)
		return (free_all(data), EXIT_FAILURE);
	if (check_map(data) == 1)
		return (free_all(data), EXIT_FAILURE);
	free_all(data);
	return (EXIT_SUCCESS);
}
