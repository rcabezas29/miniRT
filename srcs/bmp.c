/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:36:40 by rcabezas          #+#    #+#             */
/*   Updated: 2020/12/01 18:31:29 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	bitmapfileheader(t_minirt *r, int fd)
{
	unsigned char	*file_header;
	int				file_size;

	file_size = 14 + 40 + (r->camera->image.bpp / 8 * r->res.x + ((4 -
		(r->res.x * r->camera->image.bpp / 8) % 4) % 4)) * r->res.y;
	file_header = ft_calloc(14, sizeof(unsigned char));
	file_header[0] = 'B';
	file_header[1] = 'M';
	file_header[2] = (unsigned char)file_size;
	file_header[3] = (unsigned char)(file_size >> 8);
	file_header[4] = (unsigned char)(file_size >> 16);
	file_header[5] = (unsigned char)(file_size >> 24);
	file_header[10] = (unsigned char)(54);
	write(fd, file_header, 14);
	free(file_header);
	file_header = NULL;
}

void	bitmapinfoheader(t_minirt *r, int fd)
{
	unsigned char	*info_header;

	info_header = ft_calloc(40, sizeof(unsigned char));
	info_header[0] = (unsigned char)(40);
	info_header[4] = (unsigned char)(r->res.x);
	info_header[5] = (unsigned char)(r->res.x >> 8);
	info_header[6] = (unsigned char)(r->res.x >> 16);
	info_header[7] = (unsigned char)(r->res.x >> 24);
	info_header[8] = (unsigned char)(r->res.y);
	info_header[9] = (unsigned char)(r->res.y >> 8);
	info_header[10] = (unsigned char)(r->res.y >> 16);
	info_header[11] = (unsigned char)(r->res.y >> 24);
	info_header[12] = (unsigned char)(1);
	info_header[14] = (unsigned char)(r->camera->image.bpp);
	write(fd, info_header, 40);
	free(info_header);
	info_header = NULL;
}

void	create_bmp(t_minirt *r, char *file_name)
{
	int				i;
	int				fd;
	unsigned char	padd[3];

	i = r->res.y;
	ft_bzero(padd, 3);
	fd = open(file_name, O_CREAT | O_WRONLY, 0644);
	bitmapfileheader(r, fd);
	bitmapinfoheader(r, fd);
	while (i >= 0)
	{
		write(fd, r->camera->image.addr + (i * r->res.x *
			r->camera->image.bpp / 8), r->camera->image.line_length);
		write(fd, padd, (4 - (r->res.x * r->camera->image.bpp / 8) % 4) % 4);
		i--;
	}
	close(fd);
}
