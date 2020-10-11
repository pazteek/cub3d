/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 16:00:39 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/11 22:32:43 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "time.h"

int			ft_map(t_deb *deb, char **tab, t_player *player)
{
	int	i;

	tab = ft_malloc_struc_map(tab);
	i = 0;
	ft_transition(tab, &(*deb));
	ft_map_check(&(*deb), player);
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

int			main(int argv, char **argc)
{
	int		fd;
	char	**tab;
	t_game	game;

	if (!ft_strncmp(&argc[1][ft_strlen(argc[1]) - 4], ".cub", 4)
		&& (fd = open(argc[1], O_RDONLY)) >= 0)
	{
		init_game(&game, (tab = init_tab(argc[1], fd)));
		int_strat(game.deb, game.player);
		mlx_hook(game.deb->mlx->win_ptr, 2, 1L << 1, ft_move, &game);
		if (argv == 3)
			ft_bmp((game.deb->mlx->data), game.deb->resolution);
		mlx_loop(game.deb->mlx->mlx_ptr);
	}
	return (0);
}
