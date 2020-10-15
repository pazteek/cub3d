/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 16:05:13 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/15 19:59:00 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "time.h"

static void	ft_free_player(t_player *player)
{
	player = 0;
}
static void ft_free_textur(t_textur **textur)
{
	int a;

	a = 0;
	while (a != 5)
	{
		free(textur[a]->data);
		free(textur[a]->img_ptr);
		free(textur[a]->name);
		free(textur[a++]);
	}
}

static void	ft_free_all(t_game *game)
{
	free(game->deb->mlx->mlx_ptr);
	free(game->deb->mlx);
	ft_free_player(game->player);
	free(game->player);
	ft_free_tab((void **)game->deb->map);
	ft_free_textur(game->deb->textur);
	ft_free_tab((void**)game->deb->objet);
	free(game->deb->dist);
	free(game->deb);
}

int			ft_end(t_game *game)
{
	mlx_destroy_image(game->deb->mlx->mlx_ptr,game->deb->mlx->img_ptr);
	mlx_destroy_window(game->deb->mlx->mlx_ptr, game->deb->mlx->win_ptr);
	ft_free_all(game);
	system("leaks Cub3d");
	exit(0);
	return (1);
}
