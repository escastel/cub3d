/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:36:34 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/09/06 16:00:58 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2 || check_arg(argv[1]) == 1)
		return (print_error("incorrect argument"));
	data = ft_calloc(1, sizeof(t_data));
	init_data(data);
	if (get_map(data, argv[1], NULL) == 1)
		return (free_all(data), EXIT_FAILURE);
	if (check_map(data) == 1)
		return (free_all(data), EXIT_FAILURE);
	if (init_game(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	free_all(data);
	return (EXIT_SUCCESS);
}
