/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayon.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 15:20:35 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/07 13:22:48 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <stdlib.h>

int				rayon_y(float yx[2], float delt[2], float n_t[6], char **map)
{
	float	a;

	yx[1] += n_t[2] * delt[0] * n_t[1];
	yx[0] += delt[0] * n_t[0];
	if (n_t[0] == 1)
		a = 0;
	else
		a = -1;
	if (0 > (int)(truncf(yx[0]) + a))
		a -= yx[0];
	if ('1' == map[(int)(truncf(yx[0]) + a)][(int)(trunc(yx[1]))])
		return (n_t[0] + 3);
	if ('2' == map[(int)(truncf(yx[0]) + a)][(int)(trunc(yx[1]))])
		return (5);
	return (0);
}

int				rayon_x(float yx[2], float delt[2], float n_t[6], char **map)
{
	float	a;

	yx[0] += (delt[1] / (n_t[2])) * n_t[0];
	yx[1] += delt[1] * n_t[1];
	if (n_t[1] == 1)
		a = 0;
	else
		a = -1;
	if ('1' == map[(int)(truncf(yx[0]))][(int)(trunc(yx[1]) + a)])
		return (n_t[1] + 2);
	if ('2' == map[(int)(truncf(yx[0]))][(int)(trunc(yx[1]) + a)])
		return (5);
	return (0);
}

static int		udapte_delt(float rot, float delt[2], float n[3], float yx[2])
{
	delt[1] = dist(n[1], yx[1]);
	delt[0] = dist(n[0], yx[0]);
	if ((rot == (M_PI / 2) || rot == 2 * (M_PI / 2) || rot == 3 * (M_PI / 2)
				|| rot == 0) || ((delt[1] / n[2]) > delt[0]))
	{
		return (1);
	}
	return (0);
}

static int		init_int_strat(float *pas, float yx[2],
								t_player *play, t_deb *deb)
{
	*pas = (M_PI / 3) / deb->resolution[0];
	yx[1] = play->pos_x;
	yx[0] = play->pos_y;
	return (play->rot + M_PI / 6);
}

void			int_strat(t_deb *deb, t_player *player)
{
	float	rot;
	float	yx[2];
	int		i;
	float	pas;
	int		a;

	rot = init_int_strat(&pas, yx, player, deb);
	i = 0;
	while (rot > player->rot - M_PI / 6)
	{
		a = int_strat2(yx, rot, deb->map);
		if (a != 5)
		{
			affiche_mur(i, deb->dist[i] = sqrt(pow(yx[1] - player->pos_x, 2)
				+ pow(yx[0] - player->pos_y, 2))
				* cos(-pas * i + M_PI / 6), deb, yx);
			rot -= pas;
			i++;
			yx[1] = player->pos_x;
			yx[0] = player->pos_y;
		}
	}
	mlx_put_image_to_window(deb->mlx->mlx_ptr, deb->mlx->win_ptr,
			deb->mlx->img_ptr, 0, 0);
	mlx_do_sync(deb->mlx->mlx_ptr);
}

int				int_strat2(float yx[2], float rot, char **map)
{
	float	n_t[6];
	float	delt[2];
	int		a;

	init_var(&a, n_t, &rot);
	n_t[3] = rot;
	n_t[4] = yx[0];
	n_t[5] = yx[1];
	while (0 == a)
		if (udapte_delt(rot, delt, n_t, yx) == 1)
			a = rayon_y(yx, delt, n_t, map);
		else
			a = rayon_x(yx, delt, n_t, map);
	return (a);
}
