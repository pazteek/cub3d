#include "cub3d.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



static void ft_write_image_bpm(int fd,char *data, int imagesize)
{
	int i = 0;
	int a = 24;
	int b = 1000;
//	while (i != imagesize )
//	{
			printf("imagesize : %d\n", imagesize * 4);
			write(fd, data, imagesize * 4);
			
			//if( i%b ==0)
			//{
			//	i += a;
			//	b += a;
			//}
//	}
}

static void ft_header_bpm(int fd, int resolution[2])
{
	int	size = (resolution[0] *resolution[1] * 4) + 54;
	int	width = resolution[0];
	int	height = resolution[1];
	int	Reserve = 0;
	int	offset = 0x36;
	int headers = 40;
	int	color = 1;
	int	bit_pixel = 32;
	int	compresion = 0;
	int size_a = resolution[0] *resolution[1] * 4;
	int	x = 2800;
	int	y = 2800;
	int colors = 0;
	int color_i = 0;


	write(fd, "BM", 2);
	write(fd, &size, 4);
	write(fd, &Reserve, 4);
	write(fd, &offset, 4);
	write(fd, &headers, 4);
	write(fd, &width, 4);
	write(fd, &height, 4);
	write(fd, &color, 2);
	write(fd, &bit_pixel, 2);
	write(fd, &compresion, 4);
	write(fd, &size_a, 4);
	write(fd, &x, 4);
	write(fd, &y, 4);
	write(fd, &colors, 4);
	write(fd, &color_i, 4);
}

int	ft_bpm(char *data, int resolution[2])
{
	int	fd;
//	int resolution[2];
//	resolution[0] = deb->resolution[0];
//	resolution[1] = deb->resolution[1];
	fd = open("noc.bmp", O_WRONLY | O_CREAT |
	O_TRUNC, S_IRUSR | S_IWUSR);
	ft_header_bpm(fd, resolution);
	ft_write_image_bpm(fd, data, resolution[0] * resolution[1]);
		return (0);
}
