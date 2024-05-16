/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:37:30 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/05/16 14:06:58 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_position
{
	int		x;
	int		y;
	char	orientation;
}			t_position;

typedef struct s_data
{
	char		**map;
	char		**no;
	char		**so;
	char		**we;
	char		**ea;
	char		**f;
	char		**c;
	int			nbr_text;
	int			nbr_player;
	int			width_map;
	int			high_map;
	t_position	p_pos;
}			t_data;

/*--- CHECK ARGUMENTS ---*/
int		check_arg(char *str);
int		check_colors(char *str, int flag);
int		check_digit(char *str);

/*--- READ MAP ---*/
int		get_map(t_data *data, char *str, char *line);
int		check_map(t_data *data);

/*--- CUB3D UTILS ---*/
int		print_error(char *str);
int		ft_strrlen(char **str);

/*--- FREE PROGRAM ---*/
void	free_split(char **str);
void	free_all(t_data *d);

#endif