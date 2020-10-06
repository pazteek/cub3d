/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affiche.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 12:25:38 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/06 12:41:00 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <math.h>

void ft_put_m(int a, int b)
{
a = b;
}
void		mlx_pixel_put_image(t_mlx *mlx, int x, int y, int cf)
{
	int o;
	o = y * mlx->sizeline + x * mlx->bpp / 8;
	ft_put_m((int)(mlx->data[o]),mlx->c_f[cf]);
}

static void	mlx_pixel_put_image_2(t_mlx *mlx, int x, int y, int cf)
{
	int o;
	o = y * mlx->sizeline + x * mlx->bpp / 8;
	ft_put_m((int)(mlx->data[o]),mlx->c_f[cf]);
}

//static void	fc_transparant(t_mlx *mlx, int x, int y)
//{
//	while (y < 500)
//	{
//		mlx->data[(y + 500) * mlx->sizeline +
//			x * mlx->bpp / 8 + 3] = (char)(255);
//		mlx->data[(500 - y++) * mlx->sizeline +
//			x * mlx->bpp / 8 + 3] = (char)(255);
//	}
//}

void		color_fc(t_deb *deb, int i, int v)
{
	i--;
	while ((deb->resolution[1] / 2) - v > 0
		&& (deb->resolution[1] / 2) + v < deb->resolution[1])
	{
		mlx_pixel_put_image_2(deb->mlx, i, (deb->resolution[1] / 2) + v, 0);
		mlx_pixel_put_image_2(deb->mlx, i, (deb->resolution[1] / 2) - v++, 1);
	}
}

static void	ft_bgr(int *datas, int *data)
{
	*datas = *data;
}

static void	ft_pas_wall(float *z, int m[2], int *v, t_deb *deb)
{
	*z += M_PI / (4 * deb->resolution[1]);
	m[0] += deb->mlx->sizeline;
	m[1] -= deb->mlx->sizeline;
	*v += 1;
}

static void	ft_pas_objet(float *z, int m[2], int *v, t_deb *deb)
{
	*z += M_PI / (4 * deb->resolution[1]);
	m[0] += deb->mlx->sizeline;
	m[1] -= deb->mlx->sizeline;
	*v += 1;
}


static int	init_var_affiche_mur(float yx[2], int o[2], int i, t_deb *deb)
{
	if (yx[0] == truncf(yx[0]))
		o[1] = truncf((yx[1] - truncf(yx[1])) * deb->textur[0]->w)
			* deb->textur[0]->bpp / 8;
	else
		o[1] = truncf((yx[0] - truncf(yx[0])) * deb->textur[0]->w)
			* deb->textur[0]->bpp / 8;
	return (deb->resolution[1]/2 * deb->mlx->sizeline + i * deb->mlx->bpp / 8);
}

static int	init_var_objet(float dist_2, int o[2], int i, t_deb *deb)
{
	float	z;
	float	a;

	z = (deb->textur[4]->w/ deb->textur[4]->h); 
//	ft_printf("\nsett %d et %d\n",(int)(yx[1]  * 1000),(int)((truncf(yx[1]) + 0.5) * 1000));
//	ft_printf("\nsett %d et %d\n",(int)(((yx[0] - (truncf(yx[0]) + 0.5)) * 1000)),(int)(((yx[1] -(truncf(yx[1]) + 0.5)) * 1000)));
//	ft_printf("\n z = %d et a = %d",(int)(z * 1000),(int)(a * 1000));
			if(fabs(dist_2) > 0.5)
				return -1;
//	ft_printf("\n uz = %d et a = %d\n",(int)(z * 1000),(int)(a * 1000));
	o[1] = truncf((dist_2 + 0.5) * deb->textur[4]->w) * deb->textur[4]->bpp / 8;
//	ft_printf("\n o = %d et longeur de ligne de l image = %d\n",(int)(o[1] * 1000),(int)((deb->textur[4]->w * deb->textur[4]->bpp / 8) * 1000));

	return (deb->resolution[1]/2 * deb->mlx->sizeline + i * deb->mlx->bpp / 8);

}


void		affiche_mur(int i, float r, t_deb *deb, float *yx)
{
	int		v;
	float	z;
	float	t;
	int		o[3];
	int		m[2];

	t = atanf(0.3/ r);
	z = 0;
	v = 0;
	m[0] = init_var_affiche_mur(yx, o, i, deb);
	m[1] = m[0];
	while (t > z && v <= (deb->resolution[1] / 2))
	{
		o[2] = (int)((((z/t)/2)* deb->textur[0]->h));
		o[0] = (o[2] + (deb->textur[0]->h / 2)) * deb->textur[0]->sizeline
				+ o[1];
		ft_bgr((int*)(&deb->mlx->data[m[0]]),
				(int*)(&deb->textur[0]->data[o[0]]));
		o[0] = ((deb->textur[0]->h / 2) - o[2]) * deb->textur[0]->sizeline
				+ o[1];
		ft_bgr((int*)(&deb->mlx->data[m[1]]),
				(int*)(&deb->textur[0]->data[o[0]]));
		ft_pas_wall(&z, m, &v, deb);
	}
	while (z && v <= (deb->resolution[1] / 2))
	{
		ft_bgr((int*)(&deb->mlx->data[m[0]]),
				(int*)(&deb->mlx->c_f[0]));
		ft_bgr((int*)(&deb->mlx->data[m[1]]),
				(int*)((&deb->mlx->c_f[1])));
		ft_pas_wall(&z, m, &v, deb);
	}

}

void		affiche_objet(int i, float r, t_deb *deb, float dist_2)
{
	int		v;
	float	z;
	float	t;
	int		o[3];
	int		m[2];
	t = atanf(0.3 / r);
	z = atanf(0.20 / r);
	if (t > M_PI/6)
		t = M_PI/6;
	v = (int)(((t/(M_PI/6)) * (deb->resolution[0]/2)) - 1);
//		ft_printf("\n%d\n",v);
	if (v > deb->resolution[0]/2)
		v = deb->resolution[0]/2 - 1;
	m[0] = init_var_objet(dist_2, o, i, deb);
	m[1] = m[0] + (v * deb->mlx->sizeline);
	while (m[0] != -1 && t > z)
	{
		o[2] = (int)(((1-((z-atanf(0.20 / r))/(t-atanf(0.20 / r)))) * deb->textur[4]->h));

		o[0] = o[2] * deb->textur[4]->sizeline + o[1];
//		printf("m=%d, o=%d\n",m[1]/4000, o[0]/4000);
//		ft_bgr((int*)(&deb->mlx->data[m[1]]),
//				(int*)(&deb->textur[4]->data[o[0]]));
		ft_pas_objet(&z, m, &v, deb);
	}
}
