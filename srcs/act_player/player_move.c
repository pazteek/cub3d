/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   personage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 15:37:05 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/21 13:12:16 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		move_all(t_game *game, float a)
{
	if (-1 == colition_x(game->player, a, game->deb->map))
		game->player->pos_x -= sin(game->player->rot + a) * STEP;
	if (-1 == colition_y(game->player, a, game->deb->map))
		game->player->pos_y -= cos(game->player->rot + a) * STEP;
}

void		ft_move_right(t_game *game)
{
	float a;

	a = -M_PI / 2;
	if (!ft_xor(game->deb->mov[0], game->deb->mov[2]))
	{
		if (game->deb->mov[0] == '1')
		{
			a = -M_PI / 4;
			move_all(game, a);
		}
	}
	else
		move_all(game, a);
}

void		ft_move_left(t_game *game)
{
	float a;

	a = M_PI / 2;
	if (!ft_xor(game->deb->mov[0], game->deb->mov[2]))
	{
		if (game->deb->mov[2] == '1')
		{
			a = 3 * M_PI / 4;
			move_all(game, a);
		}
	}
	else
		move_all(game, a);
}

void		ft_move_front(t_game *game)
{
	float a;

	a = 0;
	if (0 == ft_xor(game->deb->mov[3], game->deb->mov[1]))
	{
		if (game->deb->mov[1] == '1')
		{
			a = M_PI / 4;
			move_all(game, a);
		}
	}
	else
		move_all(game, a);
}

void		ft_move_back(t_game *game)
{
	float a;

	a = M_PI;
	if (!ft_xor(game->deb->mov[3], game->deb->mov[1]))
	{
		if (game->deb->mov[3] == '1')
		{
			a = -3 * M_PI / 4;
			move_all(game, a);
		}
	}
	else
		move_all(game, a);
}
