/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 12:10:03 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/15 17:57:31 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <math.h>

static void			ft_bgr(int *datas, int *data)
{
	*datas = *data;
}

static void			ft_pas_objet(float *z, int m[2], int *v, t_deb *deb)
{
	*z += M_PI / (4 * deb->resolution[1]);
	m[0] += deb->mlx->sizeline;
	m[1] -= deb->mlx->sizeline;
	*v += 1;
}

static int			init_var_objet(float dist_2, int o[2], int i, t_deb *deb)
{
	float	z;

	z = (deb->textur[4]->w / deb->textur[4]->h);
	if (fabs(dist_2) >= 0.5)
		return (-1);
	o[1] = truncf((dist_2 + 0.5) * deb->textur[4]->w) * deb->textur[4]->bpp / 8;
	return (deb->resolution[1] / 2 * deb->mlx->sizeline
			+ i * deb->mlx->bpp / 8);
}

static int			init_var_objet_2(float *z, float *t, float r, t_deb *deb)
{
	int		v;

	*t = atanf(0.3 / r);
	*z = atanf(0.10 / r);
	if (*t > M_PI / 6)
		*t = M_PI / 6;
	v = (int)(((*t / (M_PI / 6)) * (deb->resolution[0] / 2)) - 1);
	if (v > deb->resolution[0] / 2)
		v = deb->resolution[0] / 2 - 1;
	return (v);
}

void				affiche_objet(int i, float r, t_deb *deb, float dist_2)
{
	int		v;
	float	z;
	float	t;
	int		o[3];
	int		m[2];

	v = init_var_objet_2(&z, &t, r, deb);
	m[0] = init_var_objet(dist_2, o, i, deb);
	m[1] = m[0] + (v * deb->mlx->sizeline);
	while (m[0] != -1 && t > z)
	{
		o[2] = (int)(((1 - ((z - atanf(0.10 / r)) / (t - atanf(0.10 / r))))
					* deb->textur[4]->h));
		o[0] = o[2] * deb->textur[4]->sizeline + o[1];
		if (o[2] != deb->textur[4]->h && deb->textur[4]->data[o[0] + 3] == 0)
			ft_bgr((int*)(&deb->mlx->data[m[1]]),
					(int*)(&deb->textur[4]->data[o[0]]));
		ft_pas_objet(&z, m, &v, deb);
	}
}
