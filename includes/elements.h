/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 11:36:54 by rcabezas          #+#    #+#             */
/*   Updated: 2020/10/02 11:37:33 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENTS_H
# define ELEMENTS_H

typedef struct	s_color
{
	float	r;
	float	g;
	float	b;
}				t_color;

typedef struct	s_vec
{
	float		x;
	float		y;
	float		z;
}				t_vec;

typedef struct	s_image
{
	void	*ptr;
	char	*addr;
	int 	bpp;
	int		line_length;
	int		endian;
	
}				t_image;

typedef struct	s_ray
{
	t_vec	dir;
	t_vec	origin;
}				t_ray;

typedef struct	s_res
{
	int	x;
	int	y;
}				t_res;

typedef struct	s_inter
{
	float		a;
	float		b;
	float		c;
	float		det;
	float		t1;
	float		t2;
	float		d1;
	float		d2;
	float		x;
	t_vec		sub;
	t_vec		cross;
	t_vec		v1;
	t_vec		v2;
	t_vec		tvec;
	t_vec		pvec;
}				t_inter;

typedef struct	s_ambient
{
	float	intensity;
	t_color	color;
}				t_ambient;

typedef struct	s_camera
{
	t_vec	position;
	t_vec	orientation;
	float	fov;
	t_image	image;
	t_vec	up;
	t_vec	right;
}				t_camera;

typedef struct	s_object
{
	int		id;
	t_vec	position;
	float	diameter;
	t_color	color;
	float	ratio;
	t_vec	normal;
	float	height;
	t_vec	point1;
	t_vec	point2;
	t_vec	point3;
}				t_object;

#endif
