/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 09:55:18 by rcabezas          #+#    #+#             */
/*   Updated: 2020/10/09 10:42:42 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void    sphere(t_minirt *r, t_object *obj, t_ray cam_ray, t_list *tmp)
{
    t_inter s;
    
    s.a = 1;
    s.b = 2 * (cam_ray.origin.x * cam_ray.dir.x + cam_ray.origin.y *
        cam_ray.dir.y + cam_ray.dir.z * cam_ray.origin.z);
    s.c = pow(cam_ray.origin.x, 2) + pow(cam_ray.origin.y, 2) +
        pow(cam_ray.origin.z, 2) - pow(obj->diameter / 2, 2);
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

void    sphere_s(t_minirt *r, t_object *obj, t_ray light_ray)
{
    t_inter s;
    
    s.a = 1;
    s.b = 2 * (light_ray.origin.x * light_ray.dir.x + light_ray.origin.y *
        light_ray.dir.y + light_ray.dir.z * light_ray.origin.z);
    s.c = pow(light_ray.origin.x, 2) + pow(light_ray.origin.y, 2) +
        pow(light_ray.origin.z, 2) - pow(obj->diameter / 2, 2);
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