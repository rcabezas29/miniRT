/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_objs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:49:01 by rcabezas          #+#    #+#             */
/*   Updated: 2020/12/22 21:01:58 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		move_objs(t_minirt *r, int key)
{
	t_object	*obj;

	obj = choose_obj(r);
	key == 124 ? obj->position.x += 1 : 0;
	key == 126 ? obj->position.y += 1 : 0;
	key == 6 ? obj->position.z += 1 : 0;
	key == 123 ? obj->position.x -= 1 : 0;
	key == 125 ? obj->position.y -= 1 : 0;
	key == 7 ? obj->position.z -= 1 : 0;
}

void		rotate_objs(t_minirt *r, int key)
{
	t_list		*tmp;
	t_object	*obj;

	obj = NULL;
	tmp = r->object_list;
	while (tmp)
	{
		obj = tmp->content;
		if (obj->id == 1 || obj->id == 5)
		{
			tmp = tmp->next;
			continue ;
		}
		key == 35 ? obj->normal.x += 0.1 : 0;
		key == 31 ? obj->normal.y += 0.1 : 0;
		key == 34 ? obj->normal.z += 0.1 : 0;
		key == 37 ? obj->normal.x -= 0.1 : 0;
		key == 40 ? obj->normal.y -= 0.1 : 0;
		key == 38 ? obj->normal.z -= 0.1 : 0;
		tmp = tmp->next;
	}
}

void		move_lights(t_minirt *r, int key)
{
	t_list		*tmp;
	t_object	*light;

	light = NULL;
	tmp = r->light_list;
	while (tmp)
	{
		light = tmp->content;
		if (key == 15)
			light->position.x++;
		else if (key == 17)
			light->position.y++;
		else if (key == 16)
			light->position.z++;
		else if (key == 3)
			light->position.x--;
		else if (key == 5)
			light->position.y--;
		else if (key == 4)
			light->position.z--;
		tmp = tmp->next;
	}
}

t_object	*choose_obj(t_minirt *r)
{
	t_object	*obj;
	int			i;
	t_list		*tmp;

	i = 0;
	tmp = r->object_list;
	while (i < r->obj_to_move && tmp)
	{
		tmp = tmp->next;
		i++;
	}
	obj = tmp->content;
	return (obj);
}
