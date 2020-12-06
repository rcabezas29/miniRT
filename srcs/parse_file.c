/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 08:36:00 by rcabezas          #+#    #+#             */
/*   Updated: 2020/12/06 17:26:28 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
}

void	parse_rtfile(char *rt_file, t_minirt *r)
{
	int fd;

	fd = open(rt_file, O_RDONLY);
	while (get_next_line(fd, &r->line))
	{
		r->split = ft_split(r->line, ' ');
		check_id(r);
		r->split = free_split(r->split);
		free(r->line);
	}
	close(fd);
}

void	parse_res(t_minirt *r)
{
	r->res.x = ft_atoi(r->split[1]);
	if (r->res.x > 2560)
		r->res.x = 2560;
	r->res.y = ft_atoi(r->split[2]);
	if (r->res.y > 1440)
		r->res.y = 1440;
}

void	parse_ambient(t_minirt *r)
{
	r->ambient.intensity = ft_atof(r->split[1]);
	r->ambient.color = split_rgb(r->split[2]);
}

void	parse_camera(t_minirt *r)
{
	t_camera *camera;

	camera = malloc(sizeof(t_camera));
	camera->position = split_vec(r->split[1]);
	camera->orientation = split_vec(r->split[2]);
	camera->fov = atof(r->split[3]);
	ft_lstadd_back(&r->cam_list, ft_lstnew(camera));
	r->numOfCams++;
}

void	parse_light(t_minirt *r)
{
	t_object	*light;

	light = malloc(sizeof(t_object));
	light->position = split_vec(r->split[1]);
	light->ratio = ft_atof(r->split[2]);
	light->color = split_rgb(r->split[3]);
	ft_lstadd_back(&r->light_list, ft_lstnew(light));
}
