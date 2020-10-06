/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   personage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 15:37:05 by gbabeau           #+#    #+#             */
/*   Updated: 2020/09/28 14:49:15 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	colition_x(t_player *player, float dic, char **map)
{
	float	yx[2];
	int a;
	yx[0] = player->pos_y;
	yx[1] = player->pos_x;
	a = int_strat2(yx, player->rot + dic, map);
	if (map[(int)(player->pos_y)][(int)(player->pos_x - (sin(player->rot+ dic) *0.2))]!='1')
		return (1);
	return (0);
}



static int	colition_y(t_player *player, float dic, char **map)
{
	float	yx[2];
	int a;
	yx[0] = player->pos_y;
	yx[1] = player->pos_x;
	a = int_strat2(yx, player->rot + dic, map);
	if (map[(int)(player->pos_y - (cos(player->rot+ dic) * 0.2))][(int)(player->pos_x)]!='1')
		return (1);
	return (0);
}

void		ft_move_right(t_player *player, char **map)
{
	if (colition_x(player, -M_PI / 2, map))
		player->pos_x += cos(player->rot) * 0.2;
	if (colition_y(player, -M_PI / 2, map))
		player->pos_y -= sin(player->rot) * 0.2;
}

void		ft_move_left(t_player *player, char **map)
{
	if (colition_x(player, M_PI / 2, map))
		player->pos_x -= cos(player->rot) * 0.2;
	if (colition_y(player, M_PI / 2, map))
		player->pos_y += sin(player->rot) * 0.2;
}

void		ft_move_front(t_player *player, char **map)
{
	if (colition_x(player, 0, map))
		player->pos_x -= sin(player->rot) * 0.2;
	if (colition_y(player, 0, map))
		player->pos_y -= cos(player->rot) * 0.2;
}

void		ft_move_back(t_player *player, char **map)
{
	if (colition_x(player, M_PI, map))
		player->pos_x += sin(player->rot) * 0.2;
	if (colition_y(player, M_PI, map))
		player->pos_y += cos(player->rot) * 0.2;
}

void		ft_rot_right(t_player *player, char **map)
{
	player->rot -= M_PI / 25;
	if (player->rot < 0)
		player->rot += (2 * M_PI);
}

void		ft_rot_left(t_player *player, char **map)
{
	player->rot += M_PI / 25;
	if (player->rot >= 2 * M_PI)
		player->rot -= (2 * M_PI);
}
