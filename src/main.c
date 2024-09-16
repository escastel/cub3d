/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:36:34 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/09/16 13:46:30 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_data(t_data *d)
{
	d->map = NULL;
	d->no = NULL;
	d->so = NULL;
	d->we = NULL;
	d->ea = NULL;
	d->f = NULL;
	d->c = NULL;
	d->floor = 0;
	d->sky = 0;
	d->w_height = 0;
	d->nbr_text = 0;
	d->nbr_player = 0;
	d->width_map = 0;
	d->high_map = 0;
	d->fov_rd = FOV * (M_PI / 180);
	d->pos_x = 0;
	d->pos_y = 0;
	d->p_angle = 0;
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		return (ft_printf("Incorrect argument number\n"));
	if (check_arg(argv[1]) == 1)
		return (EXIT_FAILURE);
	data = ft_calloc(1, sizeof(t_data));
	init_data(data);
	if (get_map(data, argv[1], NULL) == 1)
		return (EXIT_FAILURE);
	if (check_map(data) == 1)
		return (EXIT_FAILURE);
	save_colors(data);
	if (init_game(data) == 1)
		return (EXIT_FAILURE);
	free_all(data);
	return (EXIT_SUCCESS);
}
