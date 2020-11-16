/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 08:46:42 by rcabezas          #+#    #+#             */
/*   Updated: 2020/11/16 19:09:54 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void    raytrace_start(t_minirt *r)
{
    int i;
    int j;
    t_ray camera_ray;

    i = 0;
    while (i < r->res.x)
    {
        j = 0;
        while (j < r->res.y)
        {
            r->color = create_rgb(0, 0, 0);
            r->obj = NULL;
            camera_ray = build_camera_ray(r, i, j);
            intersect(r, camera_ray);
            color_put(r, i, j);
            j++;
        }
        i++;
    }
}

t_ray   build_camera_ray(t_minirt *r, int pixel_x, int pixel_y)
{
    t_ray   ray;
	float	norm_x;
	float	norm_y;
	t_vec	image_point;

	norm_x = ((pixel_x / (float)r->res.x) - 0.5);
	norm_y = ((pixel_y / (float)r->res.y) - 0.5);
	r->res.x < r->res.y ? norm_x *= r->iar : 0;
	r->res.x > r->res.y ? norm_y /= r->iar : 0;
    ray.origin = r->camera->position;
	image_point = suma_vec(suma_vec(suma_vec(vec_mult(r->camera->right, norm_x),
		vec_mult(r->camera->up, norm_y)), ray.origin),
		normalize_vec(r->camera->orientation));
	ray.dir = normalize_vec(resta_vec(image_point, ray.origin));
	return (ray);
}

void intersect(t_minirt *r, t_ray camera_ray)
{
    t_list  *tmp;
    
    r->obj = NULL;
    r->a = 2147483647;
    tmp = r->object_list;
    while (tmp)
    {
        objs_intersect(r, tmp->content, camera_ray, tmp);
        r->inter_point = suma_vec(camera_ray.origin, vec_mult(camera_ray.dir, r->a));
        tmp = tmp->next;
    }
    if (r->obj)
    {
        r->color = r->obj->color;
        r->color = raytrace_light(r);
    }
}

void    objs_intersect(t_minirt *r, t_object *obj, t_ray cam_ray, t_list *tmp)
{
    if (obj->id == 1)
		sphere(r, obj, cam_ray, tmp);
	else if (obj->id == 2)
		plane(r, obj, cam_ray, tmp);
    else if (obj->id == 3)
		square(r, obj, cam_ray, tmp);
	else if (obj->id == 4)
		cylinder(r, obj, cam_ray, tmp);
	else if (obj->id == 5)
		triangle(r, obj, cam_ray, tmp);
}