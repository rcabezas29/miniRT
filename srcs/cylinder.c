/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 10:15:46 by rcabezas          #+#    #+#             */
/*   Updated: 2020/11/23 21:00:37 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	cylinder_normal(t_object *cylinder, t_vec inter_point)
{
	t_vec	normal;
	float	solucion1;
	float	solucion2;
	t_vec	vec_cyl;
	t_vec 	p_height;

	vec_cyl = normalize_vec(cylinder->normal);
	solucion1 = (pow(inter_point.x - cylinder->position.x, 2) +
		(pow(inter_point.y - cylinder->position.y, 2) +
		(pow(inter_point.z - cylinder->position.z, 2))));
	solucion2 = pow(cylinder->diameter / 2 ,2) +
		pow((vec_cyl.x * (inter_point.x - cylinder->position.x) + vec_cyl.y *
		(inter_point.y - cylinder->position.y) + vec_cyl.z *
		(inter_point.z - cylinder->position.z)), 2);
	if (solucion1 == solucion2)
	{
		p_height = suma_vec(vec_mult(vec_cyl, sqrt(pow(vector_length(resta_vec(inter_point, cylinder->position)), 2) -
			pow((cylinder->diameter / 2), 2))), cylinder->position);
		normal = normalize_vec(resta_vec(inter_point, p_height));
	}
	else
	{
		normal = vec_cyl;
	}
	
	return (normal);
}

void    cylinder(t_minirt *r, t_object *obj, t_ray cam_ray, t_list *tmp)
{
  	t_inter s;
    
	s.sub = resta_vec(mult_fac(cam_ray.dir, cam_ray.dir), mult_fac(mult_fac(cam_ray.dir, cam_ray.dir), dot_product(obj->normal, obj->normal)));
	s.a = s.sub.x + s.sub.y + s.sub.z;
	s.pvec =  vec_mult(mult_fac(cam_ray.dir, resta_vec(resta_vec(mult_fac(obj->position, mult_fac(obj->normal, obj->normal)), mult_fac(cam_ray.origin, mult_fac(obj->normal, obj->normal))), cam_ray.origin), 2);
	s.b = s.pvec.x + s.pvec.y + s.pvec.z;
	s.tvec = mult_fac(mult_fac(obj->normal, obj->normal), resta_vec(resta_vec(vec_mult(mult_fac(obj->position, cam_ray.origin), 2), mult_fac(cam_ray.origin, cam_ray.origin)), mult_fac(obj->position, obj->position));
	s.c = s.tvec.x + s.tvec.y + s.tvec.z - obj->diameter / 2;
	s.det = sqrt(pow(s.b, 2) - 4 * s.a * s.c);
	s.t1 = (-s.b + s.det) / (2 * s.a);
	s.t2 = (-s.b - s.det) / (2 * s.a);
	if (s.t1 > 0 && s.t1 < r->a)
	{
		r->a = s.t1;
    	r->obj = tmp->content;
	}
	if (s.t2 >= 0 && r->a > s.t2)
	{
  		r->a = s.t2;
    	r->obj = tmp->content;
	}
}
