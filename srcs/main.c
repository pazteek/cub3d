/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 16:00:39 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/22 13:35:07 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int			ft_map(t_deb *deb, char **tab, t_game game)
{
	ft_transition(tab, &(*deb));
	ft_map_check(&(*deb), game);
	return (0);
}

char		**init_tab(char *argc, int fd)
{
	int		i;
	char	a;
	char	*c;

	fd = open(argc, O_RDONLY);
	i = 0;
	while (read(fd, &a, 1) > 0)
		i++;
	if (!(c = malloc(sizeof(char*) * (i + 1))))
		return (0);
	c[i] = '\0';
	close(fd);
	fd = open(argc, O_RDONLY);
	while (read(fd, &c[0], i) > 0)
		;
	return (tri(c));
}

static int	end_cross(int a, t_game *game)
{
	ft_end(2, game);
	return (a);
}

void		ft_mlx_hook(t_game game)
{
	mlx_hook(game.deb->mlx->win_ptr, 10, (1L << 21), ft_focus, &game);
	mlx_hook(game.deb->mlx->win_ptr, 2, 1L, ft_move_p, &game);
	mlx_hook(game.deb->mlx->win_ptr, 3, 2L, ft_move_r, &game);
	mlx_loop_hook(game.deb->mlx->mlx_ptr, &ft_move, &game);
	mlx_hook(game.deb->mlx->win_ptr, 17, (1L << 17), end_cross, &game);
	mlx_loop(game.deb->mlx->mlx_ptr);
}

int			main(int argv, char **argc)
{
	int		fd;
	char	**tab;
	t_game	game;

	game.deb = NULL;
	game.player = NULL;
	if (argv == 2 || argv == 3)
	{
		if (!ft_strncmp(&argc[1][ft_strlen(argc[1]) - 4], ".cub", 4)
		&& ((fd = open(argc[1], O_RDONLY))) >= 0)
		{
			init_game(&game, (tab = init_tab(argc[1], fd)));
			int_strat(game.deb, game.player);
			if (argv == 3)
				ft_check_bmp(argc[2], game);
			ft_mlx_hook(game);
		}
		else if (fd == -1)
			ft_error(10, game);
		else
			ft_error(11, game);
	}
	else
		ft_error(12, game);
	return (0);
}
