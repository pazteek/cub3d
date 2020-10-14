/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 12:01:26 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/14 17:34:43 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <math.h>

static int	init_var_affiche_mur(float yx[2], int o[2], int i, t_deb *deb)
{
	if (yx[0] == truncf(yx[0]))
		o[1] = truncf((yx[1] - truncf(yx[1])) * deb->textur[deb->wall]->w)
			* deb->textur[deb->wall]->bpp / 8;
	else
		o[1] = truncf((1 - (yx[0] - truncf(yx[0]))) * deb->textur[deb->wall]->w)
			* deb->textur[deb->wall]->bpp / 8;
	return (deb->resolution[1] / 2 * deb->mlx->sizeline
			+  i * deb->mlx->bpp / 8);
}

static void	ft_bgr(int *datas, int *data)
{
	*datas = *data;
}

void		ft_pas_wall(float *z, int m[2], int *v, t_deb *deb)
{
	*z += M_PI / (4 * deb->resolution[1]);
	m[0] += deb->mlx->sizeline;
	m[1] -= deb->mlx->sizeline;
	*v += 1;
}

void		affiche_mur(int i, float r, t_deb *deb, float *yx)
{
	int		v;
	float	z_t[2];
	int		o[3];
	int		m[2];

	z_t[1] = atanf(0.3 / r);
	z_t[0] = 0;
	v = 0;
	m[0] = init_var_affiche_mur(yx, o, i, deb);
	m[1] = m[0];
	while (z_t[1] > z_t[0] && v <= (deb->resolution[1] / 2))
	{
		o[2] = (int)((((z_t[0] / z_t[1]) / 2) * deb->textur[deb->wall]->h));
		o[0] = (o[2] + (deb->textur[deb->wall]->h / 2)) * deb->textur[deb->wall]->sizeline
				+ o[1];
		if (v != deb->resolution[1] / 2)
		ft_bgr((int*)(&deb->mlx->data[m[0]]),
				(int*)(&deb->textur[deb->wall]->data[o[0]]));
		o[0] = ((deb->textur[deb->wall]->h / 2) - o[2])
			* deb->textur[deb->wall]->sizeline + o[1];
		ft_bgr((int*)(&deb->mlx->data[m[1]]),
				(int*)(&deb->textur[deb->wall]->data[o[0]]));
		ft_pas_wall(&z_t[0], m, &v, deb);
	}
	display_fc(z_t[0], deb, m, v);
}
