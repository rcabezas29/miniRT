/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 11:18:00 by rcabezas          #+#    #+#             */
/*   Updated: 2020/12/16 17:22:08 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_sphere(t_minirt *r)
{
	t_object	*sphere;

	num_characteristics(r->split, 4);
	if (!(sphere = malloc(sizeof(t_object))))
		parsing_objects_errors(1);
	check_comas(r->split[1], 2);
	sphere->position = split_vec(r->split[1]);
	check_comas(r->split[2], 0);
	sphere->diameter = ft_atof(r->split[2]);
	check_comas(r->split[3], 2);
	sphere->color = split_rgb(r->split[3]);
	sphere->id = 1;
	ft_lstadd_back(&r->object_list, ft_lstnew(sphere));
	r->numOfObjects++;
}

void	parse_plane(t_minirt *r)
{
	t_object	*plane;

	num_characteristics(r->split, 4);
	if (!(plane = malloc(sizeof(t_object))))
		parsing_objects_errors(2);
	check_comas(r->split[1], 2);
	plane->position = split_vec(r->split[1]);
	check_comas(r->split[2], 0);
	plane->normal = split_vec(r->split[2]);
	check_comas(r->split[3], 2);
	plane->color = split_rgb(r->split[3]);
	plane->id = 2;
	ft_lstadd_back(&r->object_list, ft_lstnew(plane));
	r->numOfObjects++;
}

void	parse_square(t_minirt *r)
{
	t_object	*square;

	num_characteristics(r->split, 5);
	if (!(square = malloc(sizeof(t_object))))
		parsing_objects_errors(3);
	check_comas(r->split[1], 2);
	square->position = split_vec(r->split[1]);
	check_comas(r->split[2], 2);
	square->normal = split_vec(r->split[2]);
	check_comas(r->split[3], 0);
	square->height = ft_atof(r->split[3]);
	check_comas(r->split[4], 2);
	square->color = split_rgb(r->split[4]);
	square->id = 3;
	ft_lstadd_back(&r->object_list, ft_lstnew(square));
	r->numOfObjects++;
}

void	parse_cylinder(t_minirt *r)
{
	t_object	*cylinder;

	num_characteristics(r->split, 6);
	if (!(cylinder = malloc(sizeof(t_object))))
		parsing_objects_errors(4);
	check_comas(r->split[1], 2);
	cylinder->position = split_vec(r->split[1]);
	check_comas(r->split[2], 2);
	cylinder->normal = split_vec(r->split[2]);
	check_comas(r->split[3], 0);
	cylinder->diameter = ft_atof(r->split[3]);
	check_comas(r->split[4], 0);
	cylinder->height = ft_atof(r->split[4]);
	check_comas(r->split[5], 2);
	cylinder->color = split_rgb(r->split[5]);
	cylinder->id = 4;
	ft_lstadd_back(&r->object_list, ft_lstnew(cylinder));
	r->numOfObjects++;
}

void	parse_triangle(t_minirt *r)
{
	t_object	*triangle;

	num_characteristics(r->split, 5);
	if (!(triangle = malloc(sizeof(t_object))))
		parsing_objects_errors(5);
	check_comas(r->split[1], 2);
	triangle->point1 = split_vec(r->split[1]);
	check_comas(r->split[2], 2);
	triangle->point2 = split_vec(r->split[2]);
	check_comas(r->split[3], 2);
	triangle->point3 = split_vec(r->split[3]);
	check_comas(r->split[4], 2);
	triangle->color = split_rgb(r->split[4]);
	triangle->id = 5;
	ft_lstadd_back(&r->object_list, ft_lstnew(triangle));
	r->numOfObjects++;
}
