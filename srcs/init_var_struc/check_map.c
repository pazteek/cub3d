/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 12:43:36 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/08 14:58:14 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_map_check_2(t_deb *deb, int y, int x, t_player *player)
{
	if (ft_compare_c_to_s(deb->map[y][x], "NSOE"))
	{
		if (!(player_init(player, y, x, deb->map[y][x])))
			return (0);
		deb->map[y][x] = '0';
	}
	if (y == 0 || deb->map[y + 1] == 0 || x == 0)
		ft_error(3);
	if (deb->map[y][x - 1] == ' ' ||
			deb->map[y][x - 1] == ' ' || deb->map[y][x - 1] == '\0')
		return (0);
	if (x > (int)(ft_strlen(deb->map[y - 1])) || deb->map[y - 1][x] == ' ')
		return (0);
	if (x > (int)(ft_strlen(deb->map[y + 1])) || deb->map[y + 1][x] == ' ')
		return (0);
	return (1);
}

t_deb		ft_map_check(t_deb *deb, t_player *player)
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
				pos = ft_map_check_2(&(*deb), y, x, player);
		x = -1;
	}
	if (pos == 1)
		return (*deb);
	ft_error(1);
	return (*deb);
}
