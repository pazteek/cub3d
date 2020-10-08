/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 16:05:13 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/08 16:06:07 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "time.h"

static void	ft_free_player(t_player *player)
{
	player = 0;
}

static void	ft_free_all(t_game *game)
{
	ft_free_player(game->player);
	free(game->player);
	free(game->deb);
	free(game);
}

int			ft_end(t_game *game)
{
	mlx_destroy_window(game->deb->mlx->mlx_ptr, game->deb->mlx->win_ptr);
	ft_free_all(game);
	exit(0);
	system("leaks ./a.out");
	return (1);
}
