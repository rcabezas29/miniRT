/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 10:15:46 by rcabezas          #+#    #+#             */
/*   Updated: 2020/12/16 18:45:41 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	cylinder_cap(t_minirt *r, t_object *obj, t_ray cam_ray, t_list *tmp)
{
	t_inter s;

	s.a = dot_product(resta_vec(cam_ray.origin, obj->position), obj->normal);
	s.b = dot_product(cam_ray.dir, obj->normal);
	if (s.b == 0 || (s.a < 0 && s.b < 0) || (s.a > 0 && s.b > 0))
		return ;
	s.t1 = -s.a / s.b;
	s.d1 = vector_length(resta_vec(obj->position,
		suma_vec(cam_ray.origin, vec_mult(cam_ray.dir, s.t1))));
	if (s.t1 < 0 || r->a < s.t1 || s.d1 > sqrt(pow(obj->height / 6, 2) +
		pow(obj->diameter / 2, 2)))
		return ;
	r->a = s.t1;
	r->obj = tmp->content;
}

t_vec	cylinder_normal(t_object *cylinder, t_vec inter_point)
{
	t_inter s;
	t_vec	normal;

	s.sub = resta_vec(cylinder->position, inter_point);
	s.a = sqrt(pow(vector_length(s.sub), 2) - pow(cylinder->height / 2, 2));
	s.cross = suma_vec(cylinder->position, vec_mult(cylinder->normal, s.a));
	normal = normalize_vec(resta_vec(inter_point, s.cross));
	return (normal);
}

void	cylinder(t_minirt *r, t_object *obj, t_ray cam_ray, t_list *tmp)
{
	t_inter	s;

	s = cylinder_calc(cam_ray, obj);
	if (s.t1 > 0 && s.t1 < r->a && s.d1 < s.x)
	{
		r->a = s.t1;
		r->obj = tmp->content;
		r->normal = cylinder_normal(obj,
			vec_mult(suma_vec(cam_ray.origin, cam_ray.dir), r->a));
	}
	if (s.t2 >= 0 && r->a > s.t2 && s.d2 < s.x)
	{
		r->a = s.t2;
		r->obj = tmp->content;
		r->normal = cylinder_normal(obj,
			vec_mult(suma_vec(cam_ray.origin, cam_ray.dir), r->a));
	}
	else
		cylinder_cap(r, obj, cam_ray, tmp);
}

void	cylinder_s(t_minirt *r, t_object *obj, t_ray light_ray)
{
	t_inter	s;

	s = cylinder_calc(light_ray, obj);
	if (s.t1 > 0 && s.t1 < r->b && s.d1 < s.x)
		r->b = s.t1;
	if (s.t2 >= 0 && r->b > s.t2 && s.d2 < s.x)
		r->b = s.t2;
	else
		r->normal = obj->normal;
}

void	cylinder_cap_s(t_minirt *r, t_object *obj, t_ray light_ray)
{
	t_inter	s;

	s.a = dot_product(resta_vec(light_ray.origin, obj->position), obj->normal);
	s.b = dot_product(light_ray.dir, obj->normal);
	if (s.b == 0 || (s.a < 0 && s.b < 0) || (s.a > 0 && s.b > 0))
		return ;
	s.t1 = -s.a / s.b;
	s.d1 = vector_length(resta_vec(obj->position,
		suma_vec(light_ray.origin, vec_mult(light_ray.dir, s.t1))));
	if (s.t1 < 0 || r->b < s.t1 ||
		pow(s.d1, 2) > pow(obj->height / 6, 2) + pow(obj->diameter / 2, 2))
		return ;
	r->b = s.t1;
}
