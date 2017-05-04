/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 18:35:53 by savincen          #+#    #+#             */
/*   Updated: 2017/04/13 20:09:16 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# define SPACE 0
# define TITLE 1
# define PARAMETER 2
# define LINE 3
# define DELIMITER 4
# define COMMENT 6
# define ERROR -1
# define CAMERA 0
# define LIGHT 1 
# define PLAN 2
# define SPHERE 3
# define CONE 4
# define CYLINDER 5

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	struct s_camera	*camera;
	int				height;
	int				width;
	void			*img;
	char			*data;
	int				bpp;
	int				s_l;
	int				endian;
}					t_env;

typedef struct		s_calc
{
	double			t;
	double			pixx;
	double			pixy;
	double			pixz;
	double			dirx;
	double			diry;
	double			dirz;
	double			a;
	double			b;
	double			c;
	double			impx;
	double			impy;
	double			impz;
	double			det;
	double			red;
	double			blue;
	double			green;
	double			v_pWidth;
	double			v_pHeight;
	double			v_pDist;
	double			pix_origin_x;
	double			pix_origin_y;
	double			pix_origin_z;
	double			xind;
	double			yind;
}					t_calc;

typedef struct		s_obj
{
	int				x;
	int				y;
	int				z;
	int				obj_type;
	int				index;
	int				r;
	char			*name;
	double			dir[3];
	double			rot[3];
	double			color[3];
	struct s_obj	*next;
}					t_obj;

void	raytracer(t_env *e, t_calc *v, t_obj *obj);
int		key_hook(int keycode, t_env *e);
int		check_sphere(t_obj *cam, t_calc *v, t_obj *coord);
int		check_plan(t_obj *cam, t_calc *v, t_obj *coord);
int		check_cylinder(t_obj *cam, t_calc *v, t_obj *coord);
int		check_cone(t_obj *cam, t_calc *v, t_obj *coord);
void	check_primitives(t_obj *obj, t_obj *light, t_obj *cam,  t_calc *v);
void	get_impact(t_calc *v, t_obj *cam);
void	init_light(t_obj *light);
int		calc_light(t_obj *obj, t_obj *light, t_calc *v, t_obj *cam);
void	calc_norm(t_obj *cam, t_calc *v, t_obj *obj);
void	parser(int fd, t_obj **obj);
void	free_list_obj(t_obj *obj);
/*
** CHECKERS
*/
int		same_char_line(char *str, char c);
int		check_type(char *str);
char	**get_conf(char *line, char c1, char c2);
char	*get_between_cs(char *str, char c1, char c2);
int		get_nbr(char *str);
void	get_dir_type(char *line, t_obj *obj);
void	read_line(char *line, t_obj *obj);
int		parse_camera(int fd, t_obj *obj);
int		parse_light(int fd, t_obj *obj);
int		parse_plan(int fd, t_obj *obj);
int		parse_sphere(int fd, t_obj *obj);
int		parse_cone(int fd, t_obj *obj);
int		parse_cylinder(int fd, t_obj *obj);
void	set_null(t_obj *obj);
void	verif_standarts(t_obj **obj);

/*
** ERRORS
*/
void	ft_syntax_error(char *line, int i);
void	ft_delimitor_error(int i);
void	ft_malloc_error(void);
void	ft_args_error(char *str, int i);
void	ft_file_error(int i);

#endif
