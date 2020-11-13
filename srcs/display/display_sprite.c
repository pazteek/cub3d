/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 12:10:03 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/22 14:23:15 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

static void			ft_bgr(int *datas, int *data)
{
	*datas = *data;
}

static void			ft_pas_objet(float *z, int *v, t_deb *deb)
{
	*z += deb->fov_h / (deb->resolution[1]);
	*v += 1;
}

static int			init_var_objet(float dist_2, int o[2], int i, t_deb *deb)
{
	float a;

	a = (((float)(((float)deb->textur[4]->h) / (float)(deb->textur[4]->w)
		/ 7.0)));
	if (fabs(dist_2) >= a)
	{
		return (-1);
	}
	o[1] = (truncf((float)((dist_2 + a) / (2 * a)
					* deb->textur[4]->w)) * (deb->textur[4]->bpp / 8));
	return (i * deb->mlx->bpp / 8);
}

static int			init_var_objet_2(float *z, float *t, float r, t_deb *deb)
{
	int		v;

	*t = 0.3 - (((float)(((float)(deb->textur[4]->w) /
			(float)(deb->textur[4]->h)) / 4.0)));
	*z = atanf(*t / r);
	v = (int)((float)((float)(*z + (deb->fov_h / 2) / (float)(deb->fov_h)))
		* (float)(deb->resolution[1]));
	if (v >= deb->resolution[1])
		return (-1);
	return (v);
}

void				affiche_objet(int i, float r, t_deb *deb, float dist_2)
{
	int		v;
	float	z;
	float	t;
	int		o[3];
	int		m;

	m = init_var_objet(dist_2, o, i, deb);
	if (m != -1)
	{
		v = init_var_objet_2(&z, &t, r, deb);
		if (v != -1)
		{
			deb->dist[i] = r;
			while (tan(z) * r < (0.3) && v < deb->resolution[1])
			{
				o[2] = (int)((((((tan(z) * r - t) / (0.3 - t))))
							* deb->textur[4]->h));
				o[0] = o[2] * deb->textur[4]->sizeline + o[1];
				if (o[2] < deb->textur[4]->h && deb->textur[4]->data[o[0] + 3])
					ft_bgr((int*)(&deb->mlx->data[m + v * deb->mlx->sizeline]),
							(int*)(&deb->textur[4]->data[o[0]]));
				ft_pas_objet(&z, &v, deb);
			}
		}
	}
}
