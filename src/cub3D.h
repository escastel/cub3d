/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:37:30 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/07/24 14:27:44 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define FOV			60
# define M_PI			3.14159265358979323846
# define S_WIDTH		1280
# define S_HEIGHT		960
# define TILE_SIZE		30
# define PLAYER_SPEED	4
# define ROTATION_SPEED	0.045

typedef	struct s_ray
{
	int 	flag;
	double	distance;
	double	ray_angle;
}			t_ray;


typedef struct s_player
{
	char	orientation;
	double	pos_x; 		// START POSITION
	double	pos_y; 		// START POSITION
	double	dir_x; 		// INITIAL DIRECTION VECTOR
	double	dir_y; 		// INITIAL DIRECTION VECTOR
	double	fov_rd;		// FOV EN RADIANES
	double	p_angle;	// ANGLE
}			t_player;

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
	t_ray		*ray;
	t_player	player;
}			t_data;

/*--- INIT_STRUCT ---*/

void	init_data(t_data *d);
void	init_player(t_player p);

/*--- PARSER ---*/

int		check_arg(char *str);
int		check_colors(char *str, int flag);
int		check_digit(char *str);
int		check_map(t_data *data);
int		check_close_map(t_data *data, int i);

/*--- READ MAP ---*/

int		get_map(t_data *data, char *str, char *line);

/*--- CUB3D UTILS ---*/

int		print_error(char *str);
int		ft_strrlen(char **str);

/*--- FREE PROGRAM ---*/

void	free_split(char **str);
void	free_all(t_data *d);

#endif