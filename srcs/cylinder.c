/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 10:15:46 by rcabezas          #+#    #+#             */
/*   Updated: 2020/11/25 21:00:05 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	cylinder_cap(t_minirt *r, t_object *obj, t_ray cam_ray, t_list *tmp)
{
	t_inter s;

	s.sub = suma_vec(obj->position, vec_mult(obj->normal, obj->height / 2));
	s.t1 = (dot_product(obj->normal, cam_ray.dir) + vector_length(s.sub)) / dot_product(obj->normal, cam_ray.dir);
	s.t2 = (dot_product(obj->normal, cam_ray.dir) - vector_length(s.sub)) / dot_product(obj->normal, cam_ray.dir);
	s.d1 = vector_length(resta_vec(s.sub, suma_vec(cam_ray.origin, vec_mult(cam_ray.dir, s.t1))));
	s.d2 = vector_length(resta_vec(s.sub, suma_vec(cam_ray.origin, vec_mult(cam_ray.dir, s.t2))));
	if (s.t1 > 0 && s.d1 < obj->diameter / 2 && s.t1 < r->a)
	{
		r->a = s.t1;
    	r->obj = tmp->content;
		r->normal = obj->normal;
	}
	if (s.t2 > 0 && s.d2 < obj->diameter / 2 && s.t2 < r->a)
	{
		r->a = s.t2;
    	r->obj = tmp->content;
		r->normal = vec_mult(obj->normal, -1);
	}
}

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
    
	s.sub = resta_vec(cam_ray.origin, obj->position);
	s.cross = cross_product(cam_ray.dir, obj->normal);
	s.pvec = cross_product(s.sub, obj->normal);
	s.a = dot_product(s.cross, s.cross);
	s.b = 2 * dot_product(s.cross, s.pvec);
	s.c = dot_product(s.pvec, s.pvec) - (pow(obj->diameter / 2, 2)
		* dot_product(obj->normal, obj->normal));
	s.det = pow(s.b, 2) - (4 * s.a * s.c);
	if (s.det < 0)
		return ;
	s.a = 2 * s.a;
	s.det = sqrt(s.det);
	s.t1 = (-s.b - s.det) / s.a;
	s.t2 = (-s.b + s.det) / s.a;
	s.d1 = vector_length(resta_vec(obj->position, suma_vec(cam_ray.origin, vec_mult(cam_ray.dir, s.t1))));
	s.d2 = vector_length(resta_vec(obj->position, suma_vec(cam_ray.origin, vec_mult(cam_ray.dir, s.t2))));
	s.x = sqrt(pow(obj->diameter / 2, 2) + pow(obj->height / 2, 2));
	if (s.t1 > 0 && s.t1 < r->a && s.d1 < s.x)
	{
		r->a = s.t1;
    	r->obj = tmp->content;
		r->normal = cylinder_normal(obj, vec_mult(suma_vec(cam_ray.origin, cam_ray.dir), r->a));
	}
	if (s.t2 >= 0 && r->a > s.t2 && s.d2 < s.x)
	{
  		r->a = s.t2;
    	r->obj = tmp->content;
		r->normal = cylinder_normal(obj, vec_mult(suma_vec(cam_ray.origin, cam_ray.dir), r->a));
	}
	else
		cylinder_cap(r, obj, cam_ray, tmp);
}

void    cylinder_s(t_minirt *r, t_object *obj, t_ray light_ray)
{
  	t_inter s;
    
	s.sub = resta_vec(light_ray.origin, obj->position);
	s.cross = cross_product(light_ray.dir, obj->normal);
	s.pvec = cross_product(s.sub, obj->normal);
	s.a = dot_product(s.cross, s.cross);
	s.b = 2 * dot_product(s.cross, s.pvec);
	s.c = dot_product(s.pvec, s.pvec) - (pow(obj->diameter / 2, 2)
		* dot_product(obj->normal, obj->normal));
	s.det = pow(s.b, 2) - (4 * s.a * s.c);
	if (s.det < 0)
		return ;
	s.a = 2 * s.a;
	s.det = sqrt(s.det);
	s.t1 = (-s.b - s.det) / s.a;
	s.t2 = (-s.b + s.det) / s.a;
	s.d1 = vector_length(resta_vec(obj->position, suma_vec(light_ray.origin, vec_mult(light_ray.dir, s.t1))));
	s.d2 = vector_length(resta_vec(obj->position, suma_vec(light_ray.origin, vec_mult(light_ray.dir, s.t2))));
	s.x = sqrt(pow(obj->diameter / 2, 2) + pow(obj->height / 2, 2));
	if (s.t1 > 0 && s.t1 < r->b && s.d1 < s.x)
		r->b = s.t1;
	if (s.t2 >= 0 && r->b > s.t2 && s.d2 < s.x)
  		r->b = s.t2;
	else
		cylinder_cap_s(r, obj, light_ray);
}

void	cylinder_cap_s(t_minirt *r, t_object *obj, t_ray light_ray)
{
	t_inter s;

	s.sub = suma_vec(obj->position, vec_mult(obj->normal, obj->height / 2));
	s.t1 = (dot_product(obj->normal, light_ray.dir) + vector_length(s.sub)) / dot_product(obj->normal, light_ray.dir);
	s.t2 = (dot_product(obj->normal, light_ray.dir) - vector_length(s.sub)) / dot_product(obj->normal, light_ray.dir);
	s.d1 = vector_length(resta_vec(s.sub, suma_vec(light_ray.origin, vec_mult(light_ray.dir, s.t1))));
	s.d2 = vector_length(resta_vec(s.sub, suma_vec(light_ray.origin, vec_mult(light_ray.dir, s.t2))));
	if (s.t1 > 0 && s.d1 < obj->diameter / 2 && s.t1 < r->b)
		r->b = s.t1;
	if (s.t2 > 0 && s.d2 < obj->diameter / 2 && s.t2 < r->b)
		r->b = s.t2;
}