/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayon.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 15:20:35 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/21 13:15:11 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rayon_y(float yx[2], float delt[2], float n_t[6], char **map)
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
		return (2 + n_t[0]);
	if ('2' == map[(int)(truncf(yx[0]) + a)][(int)(trunc(yx[1]))])
		return (5);
	return (0);
}

int	rayon_x(float yx[2], float delt[2], float n_t[6], char **map)
{
	float	a;

	yx[0] += (delt[1] / (n_t[2])) * (n_t[0]);
	yx[1] += delt[1] * n_t[1];
	if (n_t[1] == 1)
		a = 0;
	else
		a = -1;
	if ('1' == map[(int)(truncf(yx[0]))][(int)(trunc(yx[1]) + a)])
		return (3 + n_t[1]);
	if ('2' == map[(int)(truncf(yx[0]))][(int)(trunc(yx[1]) + a)])
		return (5);
	return (0);
}
