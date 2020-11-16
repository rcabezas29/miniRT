/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 09:55:18 by rcabezas          #+#    #+#             */
/*   Updated: 2020/11/16 21:11:50 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void    sphere(t_minirt *r, t_object *obj, t_ray cam_ray, t_list *tmp)
{
    t_inter s;
    float radio;
    
    radio = obj->diameter / 2;
    s.sub = resta_vec(obj->position, cam_ray.origin);
    s.a = vector_length(s.sub);
    s.d1 = dot_product(s.sub, cam_ray.dir);
    s.a = pow(s.a, 2);
    if (s.d1 < 0 && s.a > pow(radio, 2))
        return ;
    s.d2 = s.a - pow(s.d1, 2);
    if (s.d2 > pow(radio, 2))
        return ;
    s.d2 = sqrt(s.d2);
    s.x = sqrt(pow(radio, 2) - pow(s.d2, 2));
    s.t1 = s.d1 - s.d2;
    s.t2 = s.d1 - s.d2;
    if (s.a > pow(radio, 2) && s.t1 < r->a)
    {
        r->a = s.t1;
        r->obj = tmp->content;
    }
    else if (s.a <= pow(radio, 2) && s.t2 < r->a)
    {
        r->a = s.t2;
        r->obj = tmp->content;
    }
}
