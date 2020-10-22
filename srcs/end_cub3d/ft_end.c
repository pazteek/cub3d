/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 16:05:13 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/22 14:22:38 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_free_textur(t_textur **textur, void *mlx_ptr)
{
	int a;

	a = 0;
	while (a != 5)
	{
		if (textur[a] != 0)
		{
			if (textur[a]->img_ptr != 0 && mlx_ptr != 0)
				mlx_destroy_image(mlx_ptr, textur[a]->img_ptr);
			if (textur[a]->name != 0)
				free(textur[a]->name);
			free(textur[a++]);
		}
	}
}

static void	ft_free_mlx(t_mlx *mlx)
{
	if (mlx->win_ptr != 0 && mlx->mlx_ptr != 0)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->img_ptr != 0 && mlx->mlx_ptr != 0)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	if (mlx->mlx_ptr != 0)
		free(mlx->mlx_ptr);
}

static void	ft_free_deb(t_deb *deb, int mode)
{
	ft_free_textur(deb->textur, deb->mlx->mlx_ptr);
	if (deb->map != 0)
		ft_free_tab((void **)deb->map);
	if (deb->objet != 0)
		ft_free_tab((void**)deb->objet);
	if (deb->dist != 0)
		free(deb->dist);
	if (deb->mlx != 0 && mode != 2)
		ft_free_mlx(deb->mlx);
}

static void	ft_free_all(t_game *game, int mode)
{
	if (game->deb != 0)
		ft_free_deb(game->deb, mode);
	if (game->player != 0)
		free(game->player);
}

int			ft_end(int suc, t_game *game)
{
	if (game != 0 && suc != 2)
		ft_free_all(game, suc);
	if (0 != suc)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
	return (1);
}
