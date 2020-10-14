/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 12:50:56 by rcabezas          #+#    #+#             */
/*   Updated: 2020/10/07 09:04:08 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void    plane(t_minirt *r, t_object *obj, t_ray cam_ray, t_list *tmp)
{
    t_inter s;

    s.a = dot_product(resta_vec(cam_ray.origin, obj->position), obj->normal);
    s.b = dot_product(cam_ray.dir, obj->normal);
    if (s.b == 0 || (s.a < 0 && s.b < 0) || (s.a > 0 && s.b > 0))
        return ;
    s.t1 = -s.a / s.b;
    if (s.t1 < 0 || r->a < s.t1)
        return ;
    r->a = s.t1;
    r->obj = tmp->content;
}

void    plane_s(t_minirt *r, t_object *obj, t_ray light_ray)
{
    t_inter s;

    s.a = dot_product(resta_vec(light_ray.origin, obj->position), obj->normal);
    s.b = dot_product(light_ray.dir, obj->normal);
    if (s.b == 0 || (s.a < 0 && s.b < 0) || (s.a > 0 && s.b > 0))
        return ;
    s.t1 = -s.a / s.b;
    if (s.t1 < 0 || r->b < s.t1)
        return ;
    r->b = s.t1;
}