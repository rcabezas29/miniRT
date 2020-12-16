/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 11:43:33 by rcabezas          #+#    #+#             */
/*   Updated: 2020/12/16 19:32:09 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	suma_vec(t_vec v1, t_vec v2)
{
	t_vec	v;

	v.x = v1.x + v2.x;
	v.y = v1.y + v2.y;
	v.z = v1.z + v2.z;
	return (v);
}

t_vec	resta_vec(t_vec v1, t_vec v2)
{
	t_vec	v;

	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;
	v.z = v1.z - v2.z;
	return (v);
}

t_vec	vec_mult(t_vec v1, float x)
{
	t_vec	v;

	v.x = v1.x * x;
	v.y = v1.y * x;
	v.z = v1.z * x;
	return (v);
}

t_vec	vec_div(t_vec v1, float x)
{
	t_vec	v;

	v.x = v1.x / x;
	v.y = v1.y / x;
	v.z = v1.z / x;
	return (v);
}

t_vec	get_normal(t_minirt *r)
{
	t_vec	norm_vec;

	if (r->obj->id == 1)
		norm_vec = (normalize_vec(resta_vec(r->inter_point, r->obj->position)));
	if (r->obj->id == 2 || r->obj->id == 3 || r->obj->id == 5)
		norm_vec = normalize_vec(r->obj->normal);
	else if (r->obj->id == 4)
		norm_vec = r->normal;
	return (norm_vec);
}
