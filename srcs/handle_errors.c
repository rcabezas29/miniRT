/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 12:57:34 by rcabezas          #+#    #+#             */
/*   Updated: 2020/12/03 18:54:43 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void    handle_errors(int error)
{
    if (error == 1)
        ft_putstr_fd("ERROR\nNúmero de argumentos incorrecto", 1);
    if (error == 2)
        ft_putstr_fd("ERROR\nNo has pasado un archivo válido", 1);
    if (error == 3)
        ft_putstr_fd("ERROR\nEl 1º argumento no es --save", 1);
    exit(EXIT_SUCCESS);
}

void    parsing_objects_errors(int error)
{
    if (error == 1)
        ft_putstr_fd("ERROR\nError al leer la esfera", 1);
    if (error == 2)
        ft_putstr_fd("ERROR\nError al leer el plano", 1);
    if (error == 3)
        ft_putstr_fd("ERROR\nError al leer el cuadrado", 1);
    if (error == 4)
        ft_putstr_fd("ERROR\nError al leer el cilindro", 1);
    if (error == 5)
        ft_putstr_fd("ERROR\nError al leer el triangulo", 1);
    if (error == 6)
        ft_putstr_fd("ERROR\nError al leer la camara", 1);
    if (error == 7)
        ft_putstr_fd("ERROR\nError al leer la luz", 1);
    exit (EXIT_SUCCESS);
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