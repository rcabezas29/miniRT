/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 11:18:00 by rcabezas          #+#    #+#             */
/*   Updated: 2020/10/07 09:55:27 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


void	parseSphere(t_minirt *r)
{
	t_object    *sphere;
	
	sphere = malloc(sizeof(t_object));
	sphere->position = split_vec(r->split[1]);
	sphere->diameter = ft_atof(r->split[2]);
	sphere->color = split_rgb(r->split[3]);
	sphere->id = 1;
	ft_lstadd_back(&r->object_list, ft_lstnew(sphere));
	r->numOfObjects++;
}

void	parsePlane(t_minirt *r)
{
	t_object    *plane;

	plane = malloc(sizeof(t_object));
	plane->position = split_vec(r->split[1]);
	plane->normal = split_vec(r->split[2]);
	plane->color = split_rgb(r->split[3]);
	plane->id = 2;
	ft_lstadd_back(&r->object_list, ft_lstnew(plane));
	r->numOfObjects++;
}

void	parseSquare(t_minirt *r)
{
	t_object    *square;

	square = malloc(sizeof(t_object));
	square->position = split_vec(r->split[1]);
	square->normal = split_vec(r->split[2]);
	square->height = ft_atof(r->split[3]);
	square->color = split_rgb(r->split[4]);
	square->id = 3;
	ft_lstadd_back(&r->object_list, ft_lstnew(square));
	r->numOfObjects++;
}

void	parseCylinder(t_minirt *r)
{
	t_object    *cylinder;

	cylinder = malloc(sizeof(t_object));
	cylinder->position = split_vec(r->split[1]);
	cylinder->normal = split_vec(r->split[2]);
	cylinder->diameter = ft_atof(r->split[3]);
	cylinder->height = ft_atof(r->split[4]);
	cylinder->color = split_rgb(r->split[5]);
	cylinder->id = 4;
	ft_lstadd_back(&r->object_list, ft_lstnew(cylinder));
	r->numOfObjects++;
}

void	parseTriangle(t_minirt *r)
{
	t_object    *triangle;

	triangle = malloc(sizeof(t_object));
	triangle->point1 = split_vec(r->split[1]);
	triangle->point2 = split_vec(r->split[2]);
	triangle->point3 = split_vec(r->split[3]);
	triangle->color = split_rgb(r->split[4]);
	triangle->id = 5;
	ft_lstadd_back(&r->object_list, ft_lstnew(triangle));
	r->numOfObjects++;
}
