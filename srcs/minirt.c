/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 08:55:30 by rcabezas          #+#    #+#             */
/*   Updated: 2020/12/02 17:08:59 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	refresh_window(t_minirt *r)
{
	select_cam(r);
	setup_ray(r);
	raytrace_start(r);
	mlx_put_image_to_window(r->mlx_ptr, r->win_ptr, r->camera->image.ptr, 0, 0);
}

void	setup_ray(t_minirt *r)
{
	r->camera->up = (t_vec){0, tan(r->camera->fov * M_PI / 180), 0};
	r->iar = (float)r->res.x / (float)r->res.y;
	r->camera->right = cross_product(normalize_vec(r->camera->orientation),
		r->camera->up);
	r->camera->up = cross_product(r->camera->right,
		normalize_vec(r->camera->orientation));
	r->a = 0;
}

void	create_window(t_minirt *r)
{
	r->win_ptr = mlx_new_window(r->mlx_ptr, r->res.x, r->res.y, "window");
	mlx_put_image_to_window(r->mlx_ptr, r->win_ptr, r->camera->image.ptr, 0, 0);
	mlx_hook(r->win_ptr, 17, 0, exiting, r);
	mlx_hook(r->win_ptr, KEY_PRESS, 0, &key_press1, r);
	mlx_loop(r->mlx_ptr);
}

int		check_format(char *arg, char *format)
{
	int format_length;
	int arglen;

	format_length = ft_strlen(format);
	arglen = ft_strlen(arg);
	if (format == '\0' || arg == '\0')
		return (0);
	while (format_length != 0)
	{
		if (format[format_length] != arg[arglen])
			return (0);
		format_length--;
		arglen--;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_minirt	*r;

	r = malloc(sizeof(t_minirt));
	ft_bzero(r, sizeof(t_minirt));
	if (argc < 2 || argc > 3)
		handle_errors(r, 1);
	r->mlx_ptr = mlx_init();
	if (argc == 2)
	{
		if (!check_format(argv[1], ".rt"))
			handle_errors(r, 2);
		parse_rtfile(argv[1], r);
	}
	if (argc == 3)
	{
		if (!check_format(argv[2], ".rt"))
			handle_errors(r, 2);
		if (ft_strncmp(argv[1], "--save", 6))
			handle_errors(r, 3);
		else
			r->save = 1;
		parse_rtfile(argv[2], r);
	}
	create_cameras(r);
	select_cam(r);
	if (r->save == 1)
		create_bmp(r, BMP_FILE);
	create_window(r);
	return (1);
}
