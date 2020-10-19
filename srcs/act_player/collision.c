/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 12:10:56 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/19 14:22:47 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	colition_x(t_player *player, float dic, char **map)
{
	float	yx[2];
	int		a;

	yx[0] = player->pos_y;
	yx[1] = player->pos_x;
	a = int_strat2(yx, player->rot + dic, map);
	if (map[(int)(player->pos_y)]
			[(int)(player->pos_x - (sin(player->rot + dic) * 0.1))] != '1')
		return (-1);
	return ((int)(player->pos_x - (sin(player->rot + dic) * 0.1)));
}

int	colition_y(t_player *player, float dic, char **map)
{
	float	yx[2];
	int		a;

	yx[0] = player->pos_y;
	yx[1] = player->pos_x;
	a = int_strat2(yx, player->rot + dic, map);
	if (map[(int)(player->pos_y - (cos(player->rot + dic) * 0.1))]
			[(int)(player->pos_x)] != '1')
		return (-1);
	return ((int)(player->pos_y - (cos(player->rot + dic) * 0.1)));
}
