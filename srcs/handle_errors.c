/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 12:57:34 by rcabezas          #+#    #+#             */
/*   Updated: 2020/11/04 19:46:24 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void    handle_errors(t_minirt *r, int error)
{
    if (error == 1)
        ft_putstr_fd("Número de argumentos incorrecto", 1);
    if (error == 2)
        ft_putstr_fd("No has pasado un archivo válido", 1);
    if (error == 3)
        ft_putstr_fd("El 1º argumento no es --save", 1);
    exiting(r);
}

void    parsing_objects_errors(t_minirt *r, int error)
{
    if (error == 1)
        ft_putstr_fd("Error al leer la esfera", 1);
    if (error == 2)
        ft_putstr_fd("Error al leer el plano", 1);
    exiting(r);
}

int     exiting(t_minirt *r)
{
    mlx_destroy_image(r->mlx_ptr, r->camera->image.ptr);
    ft_lstclear(&r->cam_list, free);
    ft_lstclear(&r->object_list, free);
    ft_lstclear(&r->light_list, free);
    mlx_clear_window(r->mlx_ptr, r->win_ptr);
    mlx_destroy_window(r->mlx_ptr, r->win_ptr);
    exit(EXIT_SUCCESS);
    return (1);
}