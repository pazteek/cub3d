/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 15:32:32 by gbabeau           #+#    #+#             */
/*   Updated: 2020/09/26 14:15:10 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <time.h>

static void	ft_move_2(void (*f)(t_player*, char**), t_game *game)
{
	f(game->player, game->deb->map);
	int_strat(game->deb, game->player);
}

static void	ft_dev(t_player *player, char **map)
{
	int	i;
	int	a;

	i = 0;
	a = -1;
	ft_printf("\n\t dev\n");
	while (map[i] != 0)
	{
		while (map[i][++a] != '\0')
		{
			if (i != (int)floorf(player->pos_y) 
				|| a != (int)floorf(player->pos_x))
				write(1, &map[i][a], 1);
			else
				write(1, "G", 1);
		}
		write(1, "\n", 1);
		a = -1;
		i++;
	}
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
		ft_move_2(ft_rot_left, &(*game));
	if (key == 124)
		ft_move_2(ft_rot_right, &(*game));
	if (key == 53)
		return (ft_end(0, game));
	return (0);
}
