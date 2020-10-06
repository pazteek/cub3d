/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayon.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 15:20:35 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/06 13:43:53 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <stdlib.h>

static float angle_finish( float angle, float dist_x, float dist_y)
{
	if( dist_x > 0)
	{
		if (dist_y > 0)
			return (angle + M_PI);
		 else
			return (angle);
	}
	else if (dist_y > 0)
		 return (M_PI - angle);
	 else
		return (angle);
}

static int pos_objet2(float yx[2], float player_y, float player_x, float rot)
{
	float	dist_x;
	float	dist_y;
	float	angle;
	float	dist_obj;
	if( rot < 0)
		rot += 2*M_PI;
	dist_y = yx[0] - player_y;
	dist_x = yx[1] - player_x;
	angle = (angle_finish(atanf(dist_x/dist_y), dist_x, dist_y));
	dist_obj = sqrt(pow(dist_x,2) + pow(dist_y,2)) / (cos(angle - rot));
//	printf("angle=[%f] et rot = %f \n", (angle), rot);
	yx[0] = player_y - (dist_obj * cos(rot));
	yx[1] = player_x - (dist_obj * sin(rot));
	if (angle - rot > 0 || (angle - rot) < M_PI )
		return -1;
		else
		return 1;
//	ft_printf("y=[%d] et x=[%d]\n\n",(int)(1000 * yx[0]), (int)(1000 * yx[1]));
}

int			rayon_y(float yx[2], float delt[2], float n_t[6], char **map)
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
//			printf("%f et %f  \n", yx[0], yx[1]);
	if ('1' == map[(int)(truncf(yx[0]) + a)][(int)(trunc(yx[1]))])
		return (n_t[0] + 3);
	if ('2' == map[(int)(truncf(yx[0]) + a)][(int)(trunc(yx[1]))])
	{
		return (5);
	}
	return (0);
}

static int	pos_objet(float yx[2], float n_t[6], char **map)
{
	float	y_x[2];
	float dst;
	float a;

	if (yx[0] == truncf(yx[0]))
	{
	y_x[0] = yx[0] - (0.5 * n_t[0]);
	y_x[1] = truncf(yx[1]) + 0.5;
	}
	else
	{
	y_x[0] = truncf(yx[0]) + 0.5;
	y_x[1] = yx[1] - (0.5 * n_t[1]);
	}
		pos_objet2(y_x, n_t[4], n_t[5],n_t[3]);
		return (5);
}

int			rayon_x(float yx[2], float delt[2], float n_t[6], char **map)
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
	{
		return (5);
	}
	return (0);
}

static int	udapte_delt(float rot, float delt[2], float n[3], float yx[2])
{
//	if (rot == M_PI / 2 || rot == 2 * M_PI / 2
//		|| rot == 3 * M_PI / 2 || rot == 0)
//	{
		delt[1] = dist(n[1], yx[1]);
		delt[0] = dist(n[0], yx[0]);
//	}
//		printf("%f, %f, %f\n", (delt[0]), (delt[1]), rot);
	if ((rot == (M_PI / 2) || rot == 2 * (M_PI / 2) || rot == 3 * (M_PI / 2)
			|| rot == 0) || ((delt[1] / n[2]) > delt[0]))
	{
		return (1);
	}
	return (0);
}
static int			rayon_y_objet(float yx[2], float delt[2], float n_t[4], char **map)
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
	if ('2' == map[(int)(truncf(yx[0]) + a)][(int)(trunc(yx[1]))])
	{
		yx[0] += a;
		return (pos_objet(yx, n_t, map));
	}
	if ('1' == map[(int)(truncf(yx[0]) + a)][(int)(trunc(yx[1]))])
	{
		return (1);
	}
	return (0);
}

static int			rayon_x_objet(float yx[2], float delt[2], float n_t[3], char **map)
{
	int a;
	yx[0] += (delt[1] / (n_t[2])) * n_t[0];
	yx[1] += delt[1] * n_t[1];
	if (n_t[1] == 1)
		a = 0;
	else
		a = -1;



	if ('2' == map[(int)(truncf(yx[0]))][(int)(trunc(yx[1]) + a)])
	{
		yx[1] += a;
		return pos_objet(yx, n_t, map);
	}
	if ('1' == map[(int)(truncf(yx[0]))][(int)(trunc(yx[1]) + a)])
	{
		return (1);
	}

	return (0);
}


static int			int_strat3(float yx[2], float rot, char **map)
{
	float	n_t[4];
	float	delt[2];
	int		a;

	init_var(&a, n_t, &rot);
	n_t[3] = rot;
	if ('2' == map[(int)(truncf(yx[0]))][(int)(trunc(yx[1]))])
		return pos_objet(yx, n_t, map);
	while (0 == a)
		if (udapte_delt(rot, delt, n_t, yx) == 1)
			a = rayon_y_objet(yx, delt, n_t, map);
		else
			a = rayon_x_objet(yx, delt, n_t, map);
	return (a);
}

float ft_whight(void)
{
return (0.5);
}
static void ft_put_t(int *a, int b)
{
	*a = b;
}
static void init_affiche_objet(t_deb *deb, t_player *player, float rot)
{
	int i;
	int x;
	float dist_2;
	float dist;
	float angle;
	float a;
	float long_objet = ft_whight();

	i = -1;
	if (player->rot > M_PI)
		rot = player->rot - 2* M_PI;
	else
		rot = player->rot;
while(deb->objet[++i] != NULL)
{

dist= sqrt(pow((deb->objet[i][1] - player->pos_x),2) + pow((deb->objet[i][0]- player->pos_y),2));
	 x = -1;
	 while(++x != 1000)
	 {
	 if(deb->dist[x]  > dist)
		{
			angle = (rot + M_PI/6 - (x * (M_PI / 3) / deb->resolution[0]));
			if ((deb->objet[i][0] - player->pos_y) > 0)
				a = atanf((deb->objet[i][1] - player->pos_x)/(deb->objet[i][0]- player->pos_y)) + M_PI;
				else
				a = atanf((deb->objet[i][1] - player->pos_x)/(deb->objet[i][0]- player->pos_y));
				dist_2  = dist * tanf(a = (a - angle));
			if (a > M_PI)
				a -= 2 * M_PI;
			else if (a < -M_PI)
				a += 2 * M_PI;
//			printf("angle = %f, et dist_2= %f et %f \n", angle, dist_2, a);
			if (a < M_PI/6 && a > - M_PI/6  && long_objet > fabs(dist_2) )
			{
				affiche_objet(x, dist, deb, dist_2);
				deb->dist[x] = dist;
			}
		}
	}
}
}


void		int_strat(t_deb *deb, t_player *player)
{
	float	rot;
	float	yx[2];
	int		i;
	float	pas;
	int		a;
	float	c;

	pas = (M_PI / 3) / deb->resolution[0];
	i = -1;
	rot = player->rot + M_PI / 6;
		yx[1] = player->pos_x;
		yx[0] = player->pos_y;

//		while (deb->objet[++i] != NULL)
//			printf("%f et %f\n", deb->objet[i][0], deb->objet[i][1]);

	i = 0;
//	while (rot > player->rot - M_PI / 6)
//	{
//			a = int_strat2(yx, rot, deb->map);
//			printf("%f et %f  \n", yx[0], yx[1]);
//		if(a != 5)
//		{
//			c = 0;
//		if (a == 1 && a == 3)
//		affiche_mur(i, deb->dist[i] = sqrt(pow(yx[1] - player->pos_x, 2)
//		+ pow(yx[0] - player->pos_y, 2)) * fabs(sin((-pas * i) + M_PI / 6)), deb, yx);
//		else
//		affiche_mur(i, deb->dist[i] = sqrt(pow(yx[1] - player->pos_x, 2)
//		+ pow(yx[0] - player->pos_y, 2)) * fabs(cos((-pas * i) + M_PI / 6)), deb, yx);
//
//		rot -= pas;
//		i++;
//		yx[1] = player->pos_x;
//		yx[0] = player->pos_y;
//		}
//	}

//	init_affiche_objet(deb, player, rot);
//	pas = (M_PI / 3) / deb->resolution[0];
//	i = 0;
//	rot = player->rot + M_PI / 6;
	i = 0;
	a = 0;
	while (i != deb->resolution[1])
	{
		while (a != deb->resolution[0])
		{
		ft_put_t((int*)(&deb->mlx->data[i * deb->mlx->sizeline + a * (deb->mlx->bpp / 8)]),deb->mlx->c_f[1]);
		a++;
		}
		i++;
		a = 0;
	}
		mlx_put_image_to_window(deb->mlx->mlx_ptr, deb->mlx->win_ptr,
			deb->mlx->img_ptr, 0, 0);
	mlx_do_sync(deb->mlx->mlx_ptr);
//	ft_bpm((int*)(deb->mlx->data), deb);
}

int			int_strat2(float yx[2], float rot, char **map)
{
	float	n_t[6];
	float	delt[2];
	int		a;

	init_var(&a, n_t, &rot);
	n_t[3] = rot;
	n_t[4] = yx[0];
	n_t[5] = yx[1];

//	if ('2' == map[(int)(truncf(yx[0]))][(int)(trunc(yx[1]))])
//		return pos_objet(yx, n_t, map);
//		printf("A\n");
	while (0 == a)
		if (udapte_delt(rot, delt, n_t, yx) == 1)
			a = rayon_y(yx, delt, n_t, map);
		else
			a = rayon_x(yx, delt, n_t, map);
	return (a);
}
