/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 12:10:03 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/11 20:37:31 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <math.h>

static float display_2(t_deb *deb, t_player *player, int i)
{
float a;

				if ((deb->objet[i][0] - player->pos_y) > 0)
					a = atanf((deb->objet[i][1] - player->pos_x) /
					(deb->objet[i][0] - player->pos_y)) + M_PI;
				else
					a = atanf((deb->objet[i][1] - player->pos_x) /
					(deb->objet[i][0] - player->pos_y));
				if (a > M_PI)
					return (a - 2 * M_PI);
				else if (a < (-M_PI))
					return (a + 2 * M_PI);
				return a;
}

static int display_wall_init(float *dist, int i, t_player *player, t_deb *deb)
{

		*dist = sqrt(pow((deb->objet[i][1] - player->pos_x), 2) +
		pow((deb->objet[i][0] - player->pos_y), 2));
		return (-1);

}

static void display_wall(int i, float rot, t_deb *deb, t_player *player)
{
	float	dist;
	float	dist_2;
	int		x;
	float	a;
	float angle;

	x = display_wall_init(&dist, i, player, deb);
	while (++x != deb->resolution[0])
	{
		if (deb->dist[x] > dist)
		{
			angle = (rot + M_PI / 6 - (x * (M_PI / 3) / deb->resolution[0]));
			a = display_2(deb, player, i);
			dist_2 = dist * tanf(a = (a - angle));
			if (a < M_PI / 6 && a > (-M_PI / 6))
			{
				affiche_objet(x, dist, deb, dist_2);
				deb->dist[x] = dist;
			}
		}
	}
}

void		init_affiche_objet(t_deb *deb, t_player *player, float rot)
{
	int		i;

	if (player->rot > M_PI)
		rot = player->rot - 2 * M_PI;
	else
		rot = player->rot;

	i = -1;
	while (deb->objet[++i] != NULL)
			display_wall(i, rot, deb, player);
}

static void	ft_bgr(int *datas, int *data)
{
	*datas = *data;
}

static void	ft_pas_objet(float *z, int m[2], int *v, t_deb *deb)
{
	*z += M_PI / (4 * deb->resolution[1]);
	m[0] += deb->mlx->sizeline;
	m[1] -= deb->mlx->sizeline;
	*v += 1;
}

static int	init_var_objet(float dist_2, int o[2], int i, t_deb *deb)
{
	float	z;

	z = (deb->textur[4]->w / deb->textur[4]->h);
	if (fabs(dist_2) >= 0.5)
		return (-1);
	o[1] = truncf((dist_2 + 0.5) * deb->textur[4]->w) * deb->textur[4]->bpp / 8;
	return (deb->resolution[1] / 2 * deb->mlx->sizeline
			+ i * deb->mlx->bpp / 8);
}

static int init_var_objet_2(float *z, float *t, float r, t_deb *deb)
{
	int v;

	*t = atanf(0.3 / r);
	*z = atanf(0.20 / r);
	if (*t > M_PI / 6)
		*t = M_PI / 6;
	v = (int)(((*t / (M_PI / 6)) * (deb->resolution[0] / 2)) - 1);
	if (v > deb->resolution[0] / 2)
		v = deb->resolution[0] / 2 - 1;
	return (v);
}

void		affiche_objet(int i, float r, t_deb *deb, float dist_2)
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
		o[2] = (int)(((1 - ((z - atanf(0.20 / r)) / (t - atanf(0.20 / r))))
		* deb->textur[4]->h));
		o[0] = o[2] * deb->textur[4]->sizeline + o[1];
	if(o[2] != deb->textur[4]->h && deb->textur[4]->data[o[0]+3] == 0)
		ft_bgr((int*)(&deb->mlx->data[m[1]]),
			(int*)(&deb->textur[4]->data[o[0]]));
		ft_pas_objet(&z, m, &v, deb);
	}
}
