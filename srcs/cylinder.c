/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 10:15:46 by rcabezas          #+#    #+#             */
/*   Updated: 2020/10/13 12:06:40 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

void    cylinder_s(t_minirt *r, t_object *obj, t_ray light_ray)
{
  t_inter s;
    
  	s.a = pow(light_ray.dir.x, 2) + pow(light_ray.dir.z, 2);
  	s.b = 2 * (light_ray.origin.x * light_ray.dir.x + light_ray.origin.z * light_ray.dir.z);
  	s.c = pow(light_ray.origin.x, 2) + pow(light_ray.origin.z, 2) - pow(obj->diameter / 2, 2);
  	if ((s.det = pow(s.b, 2) - 4 * s.a * s.c) <= 0)
   		return ;
  	s.t1 = (-s.b + sqrt(s.det)) / 2 * s.a;
  	s.t2 = (-s.b - sqrt(s.det)) / 2 * s.a;
	s.x = fabs(vector_length(resta_vec(obj->position, suma_vec(light_ray.origin, vec_mult(light_ray.dir, s.t1)))));
	s.d1 = sqrt((pow(obj->height / 2, 2)) + pow(obj->diameter / 2, 2));
	if (s.x > s.d1)
		return ;
	if (s.t1 >= 0 && r->b > s.t1)
		r->b = s.t1;
  	if (s.t2 >= 0 && r->b > s.t2)
  		r->b = s.t2;
}