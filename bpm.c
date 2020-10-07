#include "cub3d.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



static void	ft_write_image_bpm(int fd,char *data, int imagesize)
{
	write(fd, data, imagesize * 4);
}



static void init_bmp(t_bmp *bmp,int resolution[2])
{
	bmp->size = (resolution[0] *resolution[1] * 4) + 54;
	bmp->width = resolution[0];
	bmp->height = -resolution[1];
	bmp->Reserve = 0;
	bmp->offset = 0x36;
	bmp->headers = 40;
	bmp->color = 1;
	bmp->bit_pixel = 32;
	bmp->compresion = 0;
	bmp->size_a = resolution[0] *resolution[1] * 4;
	bmp->x = 2800;
	bmp->y = 2800;
	bmp->colors = 0;
	bmp->color_i = 0;
}

static void	ft_header_bpm(int fd, int resolution[2])
{
	t_bmp bmp;

	init_bmp(&bmp, resolution);
	write(fd, "BM", 2);
	write(fd, &bmp.size, 4);
	write(fd, &bmp.Reserve, 4);
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

int			ft_bpm(char *data, int resolution[2])
{
	int	fd;
	fd = open("noc.bmp", O_WRONLY | O_CREAT |
	O_TRUNC, S_IRUSR | S_IWUSR);
	ft_header_bpm(fd, resolution);
	ft_write_image_bpm(fd, data, resolution[0] * resolution[1]);
		return (0);
}
