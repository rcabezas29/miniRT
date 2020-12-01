/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 11:37:51 by rcabezas          #+#    #+#             */
/*   Updated: 2020/12/01 17:57:22 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <fcntl.h>
#include <sys/stat.h>

# include "../libft/includes/libft.h"

# define KEY_PRESS 2
# define BMP_FILE "img.bmp"

# ifdef __APPLE__
#  include "mlx_ios/mlx.h"
#  define A_KEY 0
#  define W_KEY 13
#  define S_KEY 1
#  define D_KEY 2
#  define E_KEY 14
#  define Q_KEY 12
#  define LEFT_KEY 123
#  define RIGHT_KEY 124
#  define ESC_KEY 53
#  define LEFT_SHIFT 257
#  define ONE_KEY 18
#  define TWO_KEY 19
#  define THREE_KEY 20
#  define FOUR_KEY 21
#  define X_BTN 17
# elif defined __unix__
#  include "mlx_linux/mlx.h"
#  define A_KEY 97
#  define W_KEY 119
#  define S_KEY 115
#  define D_KEY 100
#  define LEFT_KEY 65361
#  define RIGHT_KEY 65363
#  define ESC_KEY 65307
#  define LEFT_SHIFT 65505
#  define X_BTN 33
# endif

#include "elements.h"

typedef struct  s_minirt
{
    void        *mlx_ptr;
    void        *win_ptr;
    int         save;
    char        *line;
    t_res       res;
    t_ambient   ambient;
    t_camera    *camera;
    char        **split;
    t_list      *cam_list;
    t_list      *object_list;
    t_list      *light_list;
    int         numOfObjects;
    int         numOfCams;
    float       a;
    float       b;
    t_object    *obj;
    t_color     color;
    t_vec       inter_point;
    int         current_cam;
    float       iar;
    t_vec       normal;
}               t_minirt;

int             main(int argc, char **argv);
int             check_format(char *arg, char *format);
void            create_window(t_minirt *r);
void            setup_ray(t_minirt *r);
void            refresh_window(t_minirt *r);
void            handle_errors(t_minirt *rt, int error);
int             exiting(t_minirt *r);
void            parsing_objects_errors(t_minirt *r, int error);
void	        check_id(t_minirt *r);
void            parse_rtfile(char *rt_file, t_minirt *r);
void	        parseRes(t_minirt *r);
void	        parseAmbient(t_minirt *r);
void	        parseCamera(t_minirt *r);
void	        parseLight(t_minirt *r);
void	        parsePlane(t_minirt *r);
void	        parseSphere(t_minirt *r);
void	        parseSquare(t_minirt *r);
void	        parseCylinder(t_minirt *r);
void	        parseTriangle(t_minirt *r);
int             ft_count_split(char **split);
char	        **free_split(char **split);
t_color	        split_rgb(char *rgb);
t_vec	        split_vec(char *vec);
float           vector_length(t_vec v);
t_vec           normalize_vec(t_vec v);
float           dot_product(t_vec v1, t_vec v2);
t_vec           cross_product(t_vec v1, t_vec v2);
t_vec           suma_vec(t_vec v1, t_vec v2);
t_vec           resta_vec(t_vec v1, t_vec v2);
t_vec           vec_mult(t_vec v1, float x);
t_vec           vec_div(t_vec v1, float x);
t_vec	        get_normal(t_minirt *r);
t_vec           mult_fac(t_vec v1, t_vec v2);
t_color		    create_rgb(int r, int g, int b);
t_color         color_mix(t_color c1, t_color c2);
void            color_put(t_minirt *r, int x, int y);
t_color         suma_color(t_color color1, t_color color2);
void            raytrace_start(t_minirt *r);
t_ray           build_camera_ray(t_minirt *r, int pixel_x, int pixel_y);
void            objs_intersect(t_minirt *r, t_object *obj, t_ray cam_ray, t_list *tmp);
void            intersect(t_minirt *r, t_ray camera_ray);
void            sphere(t_minirt *r, t_object *obj, t_ray cam_ray, t_list *tmp);
void            plane(t_minirt *r, t_object *obj, t_ray cam_ray, t_list *tmp);
void            square(t_minirt *r, t_object *obj, t_ray cam_ray, t_list *tmp);
void            cylinder(t_minirt *r, t_object *obj, t_ray cam_ray, t_list *tmp);
void	        cylinder_cap(t_minirt *r, t_object *obj, t_ray cam_ray, t_list *tmp);
void            triangle(t_minirt *r, t_object *obj, t_ray cam_ray, t_list *tmp);
void            sphere_s(t_minirt *r, t_object *obj, t_ray light_ray);
void            plane_s(t_minirt *r, t_object *obj, t_ray light_ray);
void            square_s(t_minirt *r, t_object *obj, t_ray light_ray);
void            cylinder_s(t_minirt *r, t_object *obj, t_ray light_ray);
void            triangle_s(t_minirt *r, t_object *obj, t_ray light_ray);
void	        cylinder_cap_s(t_minirt *r, t_object *obj, t_ray light_ray);
t_vec	        cylinder_normal(t_object *cylinder, t_vec inter_point);
t_color         raytrace_light(t_minirt *r);
t_color         apply_intensity(float intensity, t_color color);
void            light_intersect(t_minirt *r, t_object *obj, t_ray light_ray);
t_color         apply_light(t_minirt *r, t_ray light_ray, t_object *light, t_color ori_color, t_vec normal);
void            create_cameras(t_minirt *r);
void            select_cam(t_minirt *r);
int             key_press1(int keycode, t_minirt *r);
void            create_bmp(t_minirt *r, char *file_name);
void            bitmapinfoheader(t_minirt *r, int fd);
void            bitmapfileheader(t_minirt *r, int fd);
float           shadows(t_minirt *r, float dot, t_ray light);
void            objs_intersect_light(t_minirt *r, t_object *obj, t_ray light_ray);
#endif
