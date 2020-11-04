/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:36:40 by rcabezas          #+#    #+#             */
/*   Updated: 2020/11/04 21:02:02 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void    create_bmp(t_minirt *r, char *file_name)
{
    int     i;
    int     fd;

    i = r->res.y;
    fd = open(file_name, O_CREAT | O_WRONLY, 0644);
    while (i >= 0)
    {
        write (fd, r->camera->image.addr + (i * r->res.x * r->camera->image.bpp / 8), r->camera->image.line_length);
        i--;
    }
    close (fd);
}