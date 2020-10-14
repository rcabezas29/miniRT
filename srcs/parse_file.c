/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 08:36:00 by rcabezas          #+#    #+#             */
/*   Updated: 2020/10/14 11:06:15 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_id(t_minirt *r)
{
	if (!ft_strcmp(r->split[0], "R"))
		parseRes(r);
	if (!ft_strcmp(r->split[0], "A"))
		parseAmbient(r);
	if (!ft_strcmp(r->split[0], "c"))
		parseCamera(r);
	if (!ft_strcmp(r->split[0], "l"))
		parseLight(r);
	if (!ft_strcmp(r->split[0], "pl"))
		parsePlane(r);
	if (!ft_strcmp(r->split[0], "sp"))
		parseSphere(r);
	if (!ft_strcmp(r->split[0], "sq"))
		parseSquare(r);
	if (!ft_strcmp(r->split[0], "cy"))
		parseCylinder(r);
	if (!ft_strcmp(r->split[0], "tr"))
		parseTriangle(r);
}

void    parse_rtfile(char *rt_file, t_minirt *r)
{
    int fd;
		
	fd = open(rt_file, O_RDONLY);
	while (get_next_line(fd, &r->line))
	{
		r->split = ft_split(r->line, ' ');
		check_id(r);
		r->split = free_split(r->split);
	}
	close(fd);
}

void	parseRes(t_minirt *r)
{
	r->res.x = ft_atoi(r->split[1]);
	r->res.y = ft_atoi(r->split[2]);
}

void	parseAmbient(t_minirt *r)
{
	r->ambient.intensity = ft_atof(r->split[1]);
	r->ambient.color = split_rgb(r->split[2]);
}

void	parseCamera(t_minirt *r)
{
	t_camera *camera;
	
	camera = malloc(sizeof(t_camera));
	camera->position = split_vec(r->split[1]);
	camera->orientation = split_vec(r->split[2]);
	camera->fov = atof(r->split[3]);
	ft_lstadd_back(&r->cam_list, ft_lstnew(camera));
	r->numOfCams++;
}

void	parseLight(t_minirt *r)
{
	t_object	*light;

	light = malloc(sizeof(t_object));
	light->position = split_vec(r->split[1]);
	light->ratio = ft_atof(r->split[2]);
	light->color = split_rgb(r->split[3]);
	ft_lstadd_back(&r->light_list, ft_lstnew(light));
}