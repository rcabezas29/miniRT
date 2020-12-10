/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:12:03 by rcabezas          #+#    #+#             */
/*   Updated: 2020/12/10 18:32:14 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_lists(t_minirt *r)
{
	t_list *tmp;
	t_camera *cam;
	t_object *obj;

	tmp = r->cam_list;
	while (tmp)
	{
		cam = tmp->content;
		if (cam->image.ptr)
			mlx_destroy_image(r->mlx_ptr, cam->image.ptr);
		free(cam);
		tmp = tmp->next;
	}
	tmp = r->object_list;
	while (tmp)
	{
		obj = tmp->content;
		free(obj);
		obj = NULL;
		tmp = tmp->next;
	}
	tmp = r->light_list;
	while (tmp)
	{
		obj = tmp->content;
		free(obj);
		tmp = tmp->next;
	}
}