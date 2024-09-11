/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:37:30 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/09/11 14:57:50 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define FOV			60
# define M_PI			3.14159265358979323846
# define S_WIDTH		1280
# define S_HEIGHT		960
# define PINK 			0xF8A4A7ff
# define BLACK 			0x000000ff
# define WHITE 			0xffffffff
# define TRANSPARENT 	0x00000000

typedef struct s_coord
{
	double	x;
	double	y;
}				t_coord;

typedef struct s_ray
{
	char	wall_o;
	double	p_angle;
	double	distance;
	double	ray_angle;
	t_coord	origin;
	t_coord	cross_x;
	t_coord	cross_y;
}			t_ray;

typedef struct s_data
{
	char		**map;
	char		**no;
	char		**so;
	char		**we;
	char		**ea;
	char		**f;
	char		**c;
	char		orientation;
	int			rays;
	int			floor;
	int			sky;
	int			nbr_text;
	int			nbr_player;
	int			width_map;
	int			high_map;
	double		fov_rd;
	double		pos_x;
	double		pos_y;
	double		p_angle;
	mlx_t		*mlx;
	mlx_image_t	*raycasting;
}			t_data;

/*--- INIT_STRUCT ---*/

void	init_data(t_data *d);

/*--- PARSER ---*/

int		check_arg(char *str);
int		check_colors(char *str, int flag);
int		check_digit(char *str);
int		check_map(t_data *data);
int		check_close_map(t_data *data, int i);
int		save_colors(t_data	*data);

/*--- READ MAP ---*/

int		get_map(t_data *data, char *str, char *line);

/*--- GAME ---*/
int		init_game(t_data *data);
void	draw_map(t_data *data);
void	hook(void *param);
void	player_move(t_data *data);

/*--- RAYCASTING ---*/

void	ray_loop(t_data *data);
void	scale_wall(t_data *data, t_ray ray);

/*--- RAYCASTING UTILS ---*/

double	get_player_angle(char c);
double	correct_angle(double angle);
double	orientation(double angle, char c);
double	get_distance(t_ray ray, t_coord wall);
int		collition_walls(t_data *data, t_ray ray, t_coord pos, char c);

/*--- CUB3D UTILS ---*/

int		print_error(char *str);
int		ft_strrlen(char **str);

/*--- FREE PROGRAM ---*/

void	free_split(char **str);
void	free_all(t_data *d);

#endif