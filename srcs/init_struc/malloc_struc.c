/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_struc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 16:03:11 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/08 16:06:52 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "time.h"

void		init_deb(t_deb *deb, char **tab, t_player *player)
{
	t_mlx		*mlx;
	t_textur	*textur[5];
	float		*dist;
	int			i;

	i = -1;
	mlx = malloc(sizeof(t_mlx));
	deb->mlx = mlx;
	while (++i != 5)
	{
		textur[i] = malloc(sizeof(t_textur));
		deb->textur[i] = textur[i];
	}
	dist = malloc(sizeof(float) * 10000);
	deb->dist = dist;
	deb->mlx->mlx_ptr = mlx_init();
	ft_deb(tab, deb, player);
}

void		init_game(t_game *game, char **tab)
{
	t_deb		*deb;
	t_player	*player;

	deb = malloc(sizeof(t_deb));
	player = malloc(sizeof(t_player));
	player->pos_x = -1;
	game->deb = deb;
	game->player = player;
	init_deb(game->deb, tab, game->player);
}
