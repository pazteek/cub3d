/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sprite_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 16:46:26 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/22 13:01:07 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	display_2(t_deb *deb, t_player *player, int i)
{
	float	a;

	if ((deb->objet[i][0] - player->pos_y) >= 0)
	{
		a = atanf((deb->objet[i][1] - player->pos_x) /
				(deb->objet[i][0] - player->pos_y)) + M_PI;
	}
	else
	{
		a = atanf((deb->objet[i][1] - player->pos_x) /
				(deb->objet[i][0] - player->pos_y));
	}
	if (a > M_PI)
	{
		return (a - 2 * M_PI);
	}
	else if (a <= (-M_PI))
	{
		return (a + 2 * M_PI);
	}
	return (a);
}

int		display_wall_init(float *dist, int i,
			t_player *player, t_deb *deb)
{
	*dist = sqrt(pow((deb->objet[i][1] - player->pos_x), 2) +
			pow((deb->objet[i][0] - player->pos_y), 2));
	return (-1);
}

void	display_wall(int i, float rot, t_deb *deb, t_player *player)
{
	float	dist;
	float	dist_2;
	int		x;
	float	a;
	float	angle;

	x = display_wall_init(&dist, i, player, deb);
	a = display_2(deb, player, i);
	while (++x != deb->resolution[0])
	{
		if (deb->dist[x] > dist)
		{
			angle = (rot + M_PI / 8 - (x * (M_PI / 4) / deb->resolution[0]));
			angle = (a - angle);
			dist_2 = dist * tanf(angle);
			if (angle > M_PI)
				angle -= 2 * M_PI;
			else if (angle < -M_PI)
				angle += 2 * M_PI;
			if (angle < M_PI / 4 && angle > (-M_PI / 4))
				affiche_objet(x, dist
				* cos(display_2(deb, player, i) - rot), deb, dist_2);
		}
	}
}

int		orde_sprite(t_deb *deb, t_player *player)
{
	int	i;
	int	n;
	int	a;

	i = -1;
	while (deb->objet[++i] != 0)
		deb->objet[i][2] = 0;
	i = -1;
	while (deb->objet[++i] != 0)
	{
		n = 1;
		a = -1;
		while (deb->objet[++a] != 0)
			if (sqrt(pow((deb->objet[i][1] - player->pos_x), 2) +
						pow((deb->objet[i][0] - player->pos_y), 2))
					< (sqrt(pow((deb->objet[a][1] - player->pos_x), 2) +
							pow((deb->objet[a][0] - player->pos_y), 2))))
				n++;
		a = -1;
		while (deb->objet[++a] != 0)
			if (a != i && deb->objet[a][2] == n)
				n++;
		deb->objet[i][2] = n;
	}
	return (0);
}

void	init_affiche_objet(t_deb *deb, t_player *player, float rot)
{
	int		i;
	int		a;

	if (player->rot > M_PI)
		rot = player->rot - 2 * M_PI;
	else
		rot = player->rot;
	i = -1;
	a = -1;
	orde_sprite(deb, player);
	while (deb->objet[++i] != NULL)
	{
		while (deb->objet[++a] != NULL)
			if (deb->objet[a][2] == (i + 1))
				display_wall(a, rot, deb, player);
		a = -1;
	}
}
