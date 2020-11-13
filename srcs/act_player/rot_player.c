/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 12:12:09 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/21 13:12:31 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void		ft_rot_right(t_player *player)
{
	player->rot -= M_PI / 100;
	if (player->rot < 0)
		player->rot += (2 * M_PI);
}

void		ft_rot_left(t_player *player)
{
	player->rot += M_PI / 100;
	if (player->rot >= 2 * M_PI)
		player->rot -= (2 * M_PI);
}
