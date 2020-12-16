/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_norm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 18:05:05 by rcabezas          #+#    #+#             */
/*   Updated: 2020/12/16 18:50:27 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_inter		cylinder_calc(t_ray cam_ray, t_object *obj)
{
	t_inter s;

	s.sub = resta_vec(cam_ray.origin, obj->position);
	s.cross = cross_product(cam_ray.dir, obj->normal);
	s.pvec = cross_product(s.sub, obj->normal);
	s.a = dot_product(s.cross, s.cross);
	s.b = 2 * dot_product(s.cross, s.pvec);
	s.c = dot_product(s.pvec, s.pvec) - (pow(obj->diameter / 2, 2)
		* dot_product(obj->normal, obj->normal));
	s.det = pow(s.b, 2) - (4 * s.a * s.c);
	s.a = 2 * s.a;
	s.det = sqrt(s.det);
	s.t1 = (-s.b - s.det) / s.a;
	s.t2 = (-s.b + s.det) / s.a;
	s.d1 = vector_length(resta_vec(obj->position,
		suma_vec(cam_ray.origin, vec_mult(cam_ray.dir, s.t1))));
	s.d2 = vector_length(resta_vec(obj->position,
		suma_vec(cam_ray.origin, vec_mult(cam_ray.dir, s.t2))));
	s.x = sqrt(pow(obj->diameter / 2, 2) + pow(obj->height / 2, 2));
	return (s);
}
