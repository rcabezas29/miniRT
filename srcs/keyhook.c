/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:06:33 by rcabezas          #+#    #+#             */
/*   Updated: 2020/11/11 19:34:17 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int     key_press1(int keycode, t_minirt *r)
{
    if (keycode == W_KEY)
        r->camera->position.y++;
    else if (keycode == S_KEY)
        r->camera->position.y--;
    else if (keycode == A_KEY)
        r->camera->position.x--;
    else if (keycode == D_KEY)
        r->camera->position.x++;
    else if (keycode == Q_KEY)
        r->camera->orientation.x -= 0.1;
    else if (keycode == E_KEY)
        r->camera->orientation.x += 0.1;
    else if (keycode == ESC_KEY)
        exiting(r);
    else
        return (0);
    refresh_window(r);
    return (1);
}