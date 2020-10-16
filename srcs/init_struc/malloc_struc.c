/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_struc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 16:03:11 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/16 10:46:05 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "time.h"

int		init_deb(t_deb *deb, char **tab, t_game *game)
{
	t_mlx		*mlx;
	t_textur	*textur[5];
	int			i;

	i = -1;
	if(!(mlx = malloc(sizeof(t_mlx))))
		return (0);
	deb->mlx = mlx;
	while (++i != 5)
	{
		if(!(textur[i] = malloc(sizeof(t_textur))))
			return (0);
		deb->textur[i] = textur[i];
	}
	deb->mlx->mlx_ptr = mlx_init();
	ft_deb(tab, game);
	return (1);
}

void		init_game(t_game *game, char **tab)
{
	t_deb		*deb;
	t_player	*player;

	deb = malloc(sizeof(t_deb));
	player = malloc(sizeof(t_player));
	player->pos_x = -1;
	game->deb = deb;
	deb->mov[0] = 0;
	deb->mov[1] = 0;
	deb->mov[2] = 0;
	deb->mov[3] = 0;
	deb->mov[4] = 0;
	deb->mov[5] = 0;
	game->player = player;
	init_deb(game->deb, tab, game);
}
