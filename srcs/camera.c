/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 12:51:54 by rcabezas          #+#    #+#             */
/*   Updated: 2020/09/30 12:51:54 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void    create_cameras(t_minirt *r)
{
    t_list  *tmp;
    int i;

    tmp = r->cam_list;
    i = 0;
    while (tmp)
    {
        r->camera = tmp->content;
        r->camera->image.ptr = mlx_new_image(r->mlx_ptr, r->res.x, r->res.y);
        r->camera->image.addr = mlx_get_data_addr(r->camera->image.ptr, &r->camera->image.bpp, &r->camera->image.line_length, &   r->camera->image.endian);
        setup_ray(r);
        raytrace_start(r);
        tmp = tmp->next;
        i++;
    }
}

void    select_cam(t_minirt *r)
{
    int i;
    t_list *tmp;

    i = 1;
    tmp = r->cam_list;
    while (tmp)
    {
        if (r->current_cam == i)
        {
            r->camera = tmp->content;
            r->current_cam++;
            if (r->current_cam == r->numOfCams)
                r->current_cam = 0;
            return ;
        }
        i++;
        tmp = tmp->next;
    }
}