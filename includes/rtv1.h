/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 18:35:53 by savincen          #+#    #+#             */
/*   Updated: 2017/05/15 21:57:43 by savincen         ###   ########.fr       */
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
	int				height;
	int				width;
	void			*img;
	char			*data;
	int				bpp;
	int				s_l;
	int				endian;
}					t_env;

typedef struct		s_vect
{
	double			x;
	double			y;
	double			z;
}					t_vect;

typedef struct		s_calc
{
	double			t;	//distance par rapport a la camera
	double			l;	//distance par rapport a la lumiere
	t_vect			pix;
	t_vect			dir;
	t_vect			pos;
	t_vect			*imp;
	double			dist1;
	double			dist2;
	double			red;
	double			blue;
	double			green;
	double			v_pWidth;
	double			v_pHeight;
	double			v_pDist;
	t_vect			pix_origin;
	double			xind;
	double			yind;
	double			theta;
	double			shadow;
	int				count;
}					t_calc;

typedef struct		s_obj
{
	t_vect			*pos;
	int				obj_type;
	int				index;
	int				r;
	char			*name;
	t_vect			*dir;
	t_vect			*rot;
	t_vect			*color;
	struct s_obj	*next;
}					t_obj;

void				raytracer(t_env *e, t_calc *v, t_obj *obj);
int					key_hook(int keycode, t_env *e);
int					check_sphere(t_obj *cam, t_calc *v, t_obj *coord);
int					check_plan(t_obj *cam, t_calc *v, t_obj *coord);
int					check_cylinder(t_obj *cam, t_calc *v, t_obj *coord);
int					check_cone(t_obj *cam, t_calc *v, t_obj *coord);
void				check_primitives(t_obj *obj, t_obj *cam,  t_calc *v);
t_vect				get_impact(t_calc *v, t_vect pos, t_vect dir);
void				init_light(t_obj *light);
int					calc_light(t_obj *obj, t_obj *lht, t_calc *v, t_vect vct);
t_vect				calc_sphere_norm(t_obj *cam, t_calc *v, t_obj *obj);
t_vect				calc_plan_norm(t_obj *cam, t_calc *v, t_obj *obj);
t_vect				calc_cylinder_norm(t_obj *cam, t_calc *v, t_obj *obj);
t_vect				calc_cone_norm(t_obj *cam, t_calc *v, t_obj *obj);
void				parser(int fd, t_obj **obj);
void				free_list_obj(t_obj *obj);
int					calc_shadow(t_obj *lht, t_calc *v, t_obj *cur, t_obj *cam);
void				set_color(t_calc *v, double i);
t_vect				rotation(t_vect *vect, t_vect *angle);
t_vect				inv_rotation(t_vect *vect, t_vect *angle);
/*
** CHECKERS
*/
int					same_char_line(char *str, char c);
int					check_type(char *str);
char				**get_conf(char *line, char c1, char c2);
char				*get_between_cs(char *str, char c1, char c2);
int					get_nbr(char *str);
void				get_dir_type(char *line, t_obj *obj);
void				read_line(char *line, t_obj *obj);
int					parse_camera(int fd, t_obj *obj);
int					parse_light(int fd, t_obj *obj);
int					parse_plan(int fd, t_obj *obj);
int					parse_sphere(int fd, t_obj *obj);
int					parse_cone(int fd, t_obj *obj);
int					parse_cylinder(int fd, t_obj *obj);
void				set_null(t_obj *obj);
void				verif_standarts(t_obj **obj);

/*
** ERRORS
*/
void				ft_syntax_error(char *line, int i);
void				ft_delimitor_error(int i);
void				ft_malloc_error(void);
void				ft_args_error(char *str, int i);
void				ft_file_error(int i);

double				dot_product(t_vect *v1, t_vect *v2);
t_vect				normalize(t_vect *vect);
t_vect				copy_vect(t_vect *vect);
t_vect				new_vect(double x, double y, double z);

#endif
