/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 19:17:55 by rcabezas          #+#    #+#             */
/*   Updated: 2020/12/16 19:34:44 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	create(t_minirt *r)
{
	create_cameras(r);
	select_cam(r);
	if (r->save == 1)
		create_bmp(r, BMP_FILE);
	create_window(r);
}

void	check_id(t_minirt *r)
{
	if (!ft_strcmp(r->split[0], "R"))
		parse_res(r);
	if (!ft_strcmp(r->split[0], "A"))
		parse_ambient(r);
	if (!ft_strcmp(r->split[0], "c"))
		parse_camera(r);
	if (!ft_strcmp(r->split[0], "l"))
		parse_light(r);
	if (!ft_strcmp(r->split[0], "pl"))
		parse_plane(r);
	if (!ft_strcmp(r->split[0], "sp"))
		parse_sphere(r);
	if (!ft_strcmp(r->split[0], "sq"))
		parse_square(r);
	if (!ft_strcmp(r->split[0], "cy"))
		parse_cylinder(r);
	if (!ft_strcmp(r->split[0], "tr"))
		parse_triangle(r);
	else
		return ;
}
