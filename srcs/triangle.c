/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 11:20:04 by rcabezas          #+#    #+#             */
/*   Updated: 2020/11/25 20:10:50 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void    triangle(t_minirt *r, t_object *obj, t_ray cam_ray, t_list *tmp)
{
    t_inter	s;

	s.v1 = resta_vec(obj->point2, obj->point1);
	s.v2 = resta_vec(obj->point3, obj->point1);
	s.pvec = cross_product(cam_ray.dir, s.v2);
	s.det = dot_product(s.v1, s.pvec);
	if (fabs(s.det) < 0.00001)
		return ;
	s.c = 1 / s.det;
	s.tvec = resta_vec(cam_ray.origin, obj->point1);
	s.a = dot_product(s.tvec, s.pvec) * s.c;
	if (s.a < 0 || s.a > 1)
		return ;
	s.tvec = cross_product(s.tvec, s.v1);
	s.b = dot_product(cam_ray.dir, s.tvec) * s.c;
	if (s.b < 0 || s.a + s.b > 1)
		return ;
	s.x = dot_product(s.v2, s.tvec) * s.c;
	if (r->a > s.x)
	{
		r->a = s.x;
		r->obj = tmp->content;
	}
}

void    triangle_s(t_minirt *r, t_object *obj, t_ray light_ray)
{
    t_inter	s;

	s.v1 = resta_vec(obj->point2, obj->point1);
	s.v2 = resta_vec(obj->point3, obj->point1);
	s.pvec = cross_product(light_ray.dir, s.v2);
	s.det = dot_product(s.v1, s.pvec);
	if (fabs(s.det) < 0.00001)
		return ;
	s.c = 1 / s.det;
	s.tvec = resta_vec(light_ray.origin, obj->point1);
	s.a = dot_product(s.tvec, s.pvec) * s.c;
	if (s.a < 0 || s.a > 1)
		return ;
	s.tvec = cross_product(s.tvec, s.v1);
	s.b = dot_product(light_ray.dir, s.tvec) * s.c;
	if (s.b < 0 || s.a + s.b > 1)
		return ;
	s.x = dot_product(s.v2, s.tvec) * s.c;
	if (r->b > s.x)
		r->b = s.x;
}