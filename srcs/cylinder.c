/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 10:15:46 by rcabezas          #+#    #+#             */
/*   Updated: 2020/10/29 17:16:25 by rcabezas         ###   ########.fr       */
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
    
  	s.a = pow(cam_ray.dir.x, 2) + pow(cam_ray.dir.z, 2);
  	s.b = 2 * (cam_ray.origin.x * cam_ray.dir.x + cam_ray.origin.z * cam_ray.dir.z);
  	s.c = pow(cam_ray.origin.x, 2) + pow(cam_ray.origin.z, 2) - pow(obj->diameter / 2, 2);
  	if ((s.det = pow(s.b, 2) - 4 * s.a * s.c) <= 0)
   		return ;
  	s.t1 = (-s.b + sqrt(s.det)) / 2 * s.a;
  	s.t2 = (-s.b - sqrt(s.det)) / 2 * s.a;
	s.x = fabs(vector_length(resta_vec(obj->position, suma_vec(cam_ray.origin, vec_mult(cam_ray.dir, s.t1)))));
	s.d1 = sqrt((pow(obj->height / 2, 2)) + pow(obj->diameter / 2, 2));
	if (s.x > s.d1)
		return ;
	if (s.t1 >= 0 && r->a > s.t1)
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
