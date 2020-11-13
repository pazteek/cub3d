/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 12:10:56 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/21 11:06:38 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	colition_x(t_player *player, float dic, char **map)
{
	float	yx[2];

	yx[0] = player->pos_y;
	yx[1] = player->pos_x;
	int_strat2(yx, player->rot + dic, map);
	if (map[(int)(player->pos_y)]
			[(int)(player->pos_x - (sin(player->rot + dic) * STEP * 2))] != '1')
		return (-1);
	return ((int)(player->pos_x - (sin(player->rot + dic) * STEP * 2)));
}

int	colition_y(t_player *player, float dic, char **map)
{
	float	yx[2];

	yx[0] = player->pos_y;
	yx[1] = player->pos_x;
	int_strat2(yx, player->rot + dic, map);
	if (map[(int)(player->pos_y - (cos(player->rot + dic) * STEP * 2))]
			[(int)(player->pos_x)] != '1')
		return (-1);
	return ((int)(player->pos_y - (cos(player->rot + dic) * STEP * 2)));
}
