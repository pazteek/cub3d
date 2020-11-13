/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 15:32:32 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/22 11:33:25 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_2(void (*f)(t_player*, char**), t_game *game)
{
	f(game->player, game->deb->map);
}

void	ft_move_3(void (*f)(t_player*), t_game *game)
{
	f(game->player);
	int_strat(game->deb, game->player);
}

int		ft_move_p(int key, t_game *game)
{
	if (key == KEY_W)
		game->deb->mov[0] = '1';
	if (key == KEY_A)
		game->deb->mov[1] = '1';
	if (key == KEY_S)
		game->deb->mov[2] = '1';
	if (key == KEY_D)
		game->deb->mov[3] = '1';
	if (key == LEFT_ROT)
		game->deb->mov[4] = '1';
	if (key == RIGHT_ROT)
		game->deb->mov[5] = '1';
	if (key == KEY_ESC)
		return (ft_end(1, game));
	return (0);
}

int		ft_move_r(int key, t_game *game)
{
	if (key == KEY_W)
		game->deb->mov[0] = 0;
	if (key == KEY_A)
		game->deb->mov[1] = 0;
	if (key == KEY_S)
		game->deb->mov[2] = 0;
	if (key == KEY_D)
		game->deb->mov[3] = 0;
	if (key == LEFT_ROT)
		game->deb->mov[4] = 0;
	if (key == RIGHT_ROT)
		game->deb->mov[5] = 0;
	return (0);
}

int		ft_move(t_game *game)
{
	if (game->deb->mov[0] == '1' && !game->deb->mov[2])
		ft_move_front(game);
	if (game->deb->mov[1] == '1' && !game->deb->mov[3])
		ft_move_left(game);
	if (game->deb->mov[2] == '1' && !game->deb->mov[0])
		ft_move_back(game);
	if (game->deb->mov[3] == '1' && !game->deb->mov[1])
		ft_move_right(game);
	if (game->deb->mov[4] == '1' && !game->deb->mov[5])
		ft_move_3(ft_rot_left, &(*game));
	if (game->deb->mov[5] == '1' && !game->deb->mov[4])
		ft_move_3(ft_rot_right, &(*game));
	int_strat(game->deb, game->player);
	return (0);
}
