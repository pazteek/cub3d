/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 15:32:32 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/11 22:39:11 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <time.h>

void	ft_move_2(void (*f)(t_player*, char**), t_game *game)
{
	f(game->player, game->deb->map);
	int_strat(game->deb, game->player);
}

void	ft_move_3(void (*f)(t_player*), t_game *game)
{
	f(game->player);
	int_strat(game->deb, game->player);
}


int				ft_move_4(int key, t_game *game)
{
	if (key == 13)
			deb->move += 1;
	if (key == 0)
			deb->move += 2;
	if (key == 1)
			deb->move += 4;
	if (key == 2)
			deb->move += 8 ;
	if (key == 123)
			deb->move += 16;
	if (key == 124)
			deb->move += 32;
	if (key == 53)
		return (ft_end(game));
	return (0);
}


int			ft_move(int key, t_game *game)
{
	if (key == 13)
		ft_move_2(ft_move_front, &(*game));
	if (key == 0)
		ft_move_2(ft_move_left, &(*game));
	if (key == 1)
		ft_move_2(ft_move_back, &(*game));
	if (key == 2)
		ft_move_2(ft_move_right, &(*game));
	if (key == 123)
		ft_move_3(ft_rot_left, &(*game));
	if (key == 124)
		ft_move_3(ft_rot_right, &(*game));
	if (key == 53)
		return (ft_end(game));
	return (0);
}
