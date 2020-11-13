/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_struc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 16:03:11 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/22 14:02:52 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			init_deb(t_deb *deb, char **tab, t_game *game)
{
	deb->mlx->mlx_ptr = mlx_init();
	ft_deb(tab, game);
	return (1);
}

static void	ft_mlx_zero(t_mlx *mlx)
{
	mlx->mlx_ptr = 0;
	mlx->win_ptr = 0;
	mlx->img_ptr = 0;
	mlx->c_f[0] = 0;
	mlx->c_f[1] = 0;
}

static void	ft_deb_zero(t_deb *deb, t_game *game)
{
	int			i;
	t_textur	*textur[5];

	i = -1;
	deb->mlx = 0;
	deb->map = 0;
	deb->objet = 0;
	deb->dist = 0;
	deb->mlx = 0;
	while (++i != 5)
		deb->textur[i] = 0;
	i = -1;
	while (++i != 5)
	{
		if (!(textur[i] = malloc(sizeof(t_textur))))
			ft_error(15, *game);
		deb->textur[i] = textur[i];
		deb->textur[i]->name = NULL;
		deb->textur[i]->img_ptr = NULL;
	}
}

static void	ft_malloc(t_game *game)
{
	t_deb		*deb;
	t_mlx		*mlx;
	t_player	*player;

	game->deb = 0;
	game->player = 0;
	if (!(deb = malloc(sizeof(t_deb))))
		ft_error(15, *game);
	game->deb = deb;
	ft_deb_zero(game->deb, game);
	if (!(mlx = malloc(sizeof(t_mlx))))
		ft_error(15, *game);
	game->deb->mlx = mlx;
	ft_mlx_zero(game->deb->mlx);
	if (!(player = malloc(sizeof(t_player))))
		ft_error(15, *game);
	game->player = player;
}

void		init_game(t_game *game, char **tab)
{
	ft_malloc(game);
	game->player->pos_x = -1;
	game->deb->mov[0] = 0;
	game->deb->mov[1] = 0;
	game->deb->mov[2] = 0;
	game->deb->mov[3] = 0;
	game->deb->mov[4] = 0;
	game->deb->mov[5] = 0;
	init_deb(game->deb, tab, game);
}
