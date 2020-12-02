/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 09:33:49 by rcabezas          #+#    #+#             */
/*   Updated: 2020/12/02 17:37:10 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	square(t_minirt *r, t_object *obj, t_ray cam_ray, t_list *tmp)
{
	t_inter	s;
	t_vec	d;

	s.a = dot_product(resta_vec(cam_ray.origin, obj->position), obj->normal);
	s.b = dot_product(cam_ray.dir, obj->normal);
	if (s.b == 0 || (s.a < 0 && s.b < 0) || (s.a > 0 && s.b > 0))
		return ;
	s.t1 = -s.a / s.b;
	d = resta_vec(suma_vec(vec_mult(cam_ray.dir, s.t1),
		cam_ray.origin), obj->position);
	s.t2 = obj->height / 2;
	if (fabs(d.x) > s.t2 || fabs(d.y) > s.t2 || fabs(d.z) > s.t2)
		return ;
	if (s.t1 > 0 && r->a > s.t1)
	{
		r->a = s.t1;
		r->obj = tmp->content;
	}
}

void	square_s(t_minirt *r, t_object *obj, t_ray light_ray)
{
	t_inter	s;
	t_vec	d;

	s.a = dot_product(resta_vec(light_ray.origin, obj->position), obj->normal);
	s.b = dot_product(light_ray.dir, obj->normal);
	if (s.b == 0 || (s.a < 0 && s.b < 0) || (s.a > 0 && s.b > 0))
		return ;
	s.t1 = -s.a / s.b;
	d = resta_vec(suma_vec(vec_mult(light_ray.dir, s.t1),
		light_ray.origin), obj->position);
	s.t2 = obj->height / 2;
	if (fabs(d.x) > s.t2 || fabs(d.y) > s.t2 || fabs(d.z) > s.t2)
		return ;
	if (s.t1 > 0 && r->b > s.t1)
		r->b = s.t1;
}
