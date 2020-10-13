/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 15:32:32 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/13 13:29:26 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <time.h>

void	ft_move_2(void (*f)(t_player*, char**), t_game *game)
{
	f(game->player, game->deb->map);
}

void	ft_move_3(void (*f)(t_player*), t_game *game)
{
	f(game->player);
	int_strat(game->deb, game->player);
}


int				ft_move_p(int key, t_game *game)
{
	if (key == 13)
			game->deb->mov[0] = '1';
	if (key == 0)
			game->deb->mov[1] = '1';
	if (key == 1)
			game->deb->mov[2] = '1';
	if (key == 2)
			game->deb->mov[3] += '1';
	if (key == 123)
			game->deb->mov[4] = '1';
	if (key == 124)
			game->deb->mov[5] = '1';
	if (key == 53)
		return (ft_end(game));
	return (0);
}

int				ft_move_r(int key, t_game *game)
{
	if (key == 13)
			game->deb->mov[0] = 0;
	if (key == 0)
			game->deb->mov[1] = 0;
	if (key == 1)
			game->deb->mov[2] = 0;
	if (key == 2)
			game->deb->mov[3] = 0 ;
	if (key == 123)
			game->deb->mov[4] = 0;
	if (key == 124)
			game->deb->mov[5] = 0;
	if (key == 53)
		return (ft_end(game));
	return (0);
}


int			ft_move(t_game *game)
{
	int a;
	a = 0;
	if (game->deb->mov[a++]== '1')
	{
		ft_move_2(ft_move_front, &(*game));
	}
	if (game->deb->mov[a++]== '1')
	{
		ft_move_2(ft_move_left, &(*game));
	}
	if (game->deb->mov[a++]== '1')
	{
		ft_move_2(ft_move_back, &(*game));
	}
	if (game->deb->mov[a++]== '1')
	{
		ft_move_2(ft_move_right, &(*game));
	}
	if (game->deb->mov[a++]== '1')
	{
		ft_move_3(ft_rot_left, &(*game));
	}
	if (game->deb->mov[a++]== '1')
	{
		ft_move_3(ft_rot_right, &(*game));
	}
	int_strat(game->deb, game->player);
	return (0);
}
