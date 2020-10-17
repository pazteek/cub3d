/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 12:43:36 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/17 17:57:40 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_map_check_2(t_game game, int y, int x)
{
	if (ft_compare_c_to_s(game.deb->map[y][x], "NSOE"))
	{
		if (!(player_init(game.player, y, x, game.deb->map[y][x])))
			return (0);
		game.deb->map[y][x] = '0';
	}
	if (y == 0 || game.deb->map[y + 1] == 0 || x == 0)
		ft_error(3, game);
	if (game.deb->map[y][x - 1] == ' ' ||
			game.deb->map[y][x - 1] == ' ' || game.deb->map[y][x - 1] == '\0')
		return (0);
	if (x > (int)(ft_strlen(game.deb->map[y - 1]))
			|| game.deb->map[y - 1][x] == ' ')
		return (0);
	if (x > (int)(ft_strlen(game.deb->map[y + 1]))
			|| game.deb->map[y + 1][x] == ' ')
		return (0);
	return (1);
}

t_deb		ft_map_check(t_deb *deb, t_game game)
{
	int	pos;
	int	y;
	int	x;

	pos = 1;
	x = -1;
	y = -1;
	while (deb->map[++y] != 0 && pos == 1)
	{
		while (deb->map[y][++x] != '\0' && pos == 1)
			if (ft_compare_c_to_s(deb->map[y][x], "02NSOE"))
				pos = ft_map_check_2(game, y, x);
		x = -1;
	}
	if (pos == 1)
		return (*deb);
	ft_error(1, game);
	return (*deb);
}
