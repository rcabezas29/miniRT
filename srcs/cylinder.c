/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 10:15:46 by rcabezas          #+#    #+#             */
/*   Updated: 2020/12/16 21:10:37 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
