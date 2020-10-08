/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   personage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 15:37:05 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/08 12:15:38 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
