/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 12:03:06 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/21 14:30:17 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static void	ft_write_image_bmp(int fd, char *data, int imagesize)
{
	write(fd, data, imagesize * 4);
}

static void	init_bmp(t_bmp *bmp, int resolution[2])
{
	bmp->size = (resolution[0] * resolution[1] * 4) + 54;
	bmp->width = resolution[0];
	bmp->height = -resolution[1];
	bmp->reserve = 0;
	bmp->offset = 0x36;
	bmp->headers = 40;
	bmp->color = 1;
	bmp->bit_pixel = 32;
	bmp->compresion = 0;
	bmp->size_a = resolution[0] * resolution[1] * 4;
	bmp->x = 2800;
	bmp->y = 2800;
	bmp->colors = 0;
	bmp->color_i = 0;
}

static void	ft_header_bmp(int fd, int resolution[2])
{
	t_bmp bmp;

	init_bmp(&bmp, resolution);
	write(fd, "BM", 2);
	write(fd, &bmp.size, 4);
	write(fd, &bmp.reserve, 4);
	write(fd, &bmp.offset, 4);
	write(fd, &bmp.headers, 4);
	write(fd, &bmp.width, 4);
	write(fd, &bmp.height, 4);
	write(fd, &bmp.color, 2);
	write(fd, &bmp.bit_pixel, 2);
	write(fd, &bmp.compresion, 4);
	write(fd, &bmp.size_a, 4);
	write(fd, &bmp.x, 4);
	write(fd, &bmp.y, 4);
	write(fd, &bmp.colors, 4);
	write(fd, &bmp.color_i, 4);
}

int			ft_bmp(char *data, int resolution[2], t_game game)
{
	int	fd;

	fd = open("cub3d.bmp", O_WRONLY | O_CREAT |
	O_TRUNC, S_IRUSR | S_IWUSR);
	ft_header_bmp(fd, resolution);
	ft_write_image_bmp(fd, data, resolution[0] * resolution[1]);
	ft_end(1, &game);
	return (0);
}

void		ft_check_bmp(char *argc, t_game game)
{
	if (!ft_strncmp(argc, "--save", 6))
		ft_bmp((game.deb->mlx->data), game.deb->resolution, game);
	else
		ft_error(18, game);
}
