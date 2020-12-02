/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 09:55:18 by rcabezas          #+#    #+#             */
/*   Updated: 2020/12/02 17:33:25 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	sphere(t_minirt *r, t_object *obj, t_ray cam_ray, t_list *tmp)
{
	t_inter	s;

	s.sub = resta_vec(cam_ray.origin, obj->position);
	s.a = dot_product(cam_ray.dir, cam_ray.dir);
	s.b = 2 * dot_product(cam_ray.dir, s.sub);
	s.c = dot_product(s.sub, s.sub) - pow(obj->diameter / 2, 2);
	s.det = pow(s.b, 2) - (4 * s.a * s.c);
	if (s.det < 0)
		return ;
	s.det = sqrt(s.det);
	s.a = 2 * s.a;
	s.t1 = (-s.b - s.det) / s.a;
	s.t2 = (-s.b + s.det) / s.a;
	if (s.t1 >= 0 && r->a > s.t1)
	{
		r->a = s.t1;
		r->obj = tmp->content;
	}
	else if (s.t2 >= 0 && r->a > s.t2)
	{
		r->a = s.t2;
		r->obj = tmp->content;
	}
}

void	sphere_s(t_minirt *r, t_object *obj, t_ray light_ray)
{
	t_inter	s;

	s.sub = resta_vec(light_ray.origin, obj->position);
	s.a = dot_product(light_ray.dir, light_ray.dir);
	s.b = 2 * dot_product(light_ray.dir, s.sub);
	s.c = dot_product(s.sub, s.sub) - pow(obj->diameter / 2, 2);
	s.det = pow(s.b, 2) - (4 * s.a * s.c);
	if (s.det < 0)
		return ;
	s.det = sqrt(s.det);
	s.a = 2 * s.a;
	s.t1 = (-s.b - s.det) / s.a;
	s.t2 = (-s.b + s.det) / s.a;
	if (s.t1 >= 0 && r->b > s.t1)
		r->b = s.t1;
	else if (s.t2 >= 0 && r->b > s.t2)
		r->b = s.t2;
}
