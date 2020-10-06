/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 16:00:39 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/06 13:26:56 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "time.h"

char		**dd(char **tab)
{
	int	i;

	i = 0;
//	while (tab[i] != 0)
//		ft_printf("%s\n", tab[i++]);
	return (tab);
}

int		ft_map(t_deb *deb, char **tab, t_player *player)
{
	int	i;

	tab = ft_malloc_struc_map(tab);
	i = 0;
//	while (tab[i] != 0)
//		ft_printf("%s\n", tab[i++]);
	tab = dd(tab);
	ft_transition(tab, &(*deb));
	ft_map_check(&(*deb), player);
		return 0;
}

static char	**transfert(char *argc)
{
	int		fd;
	int		i;
	char	*c;
	char	a;

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


void		init_deb(t_deb *deb, char **tab,t_player *player)
{
	t_mlx		*mlx;
	t_textur	*textur[5];
	float		*dist;
	mlx = malloc(sizeof(t_mlx));
	textur[0] = malloc(sizeof(t_textur));
	textur[1] = malloc(sizeof(t_textur));
	textur[2] = malloc(sizeof(t_textur));
	textur[3] = malloc(sizeof(t_textur));
	textur[4] = malloc(sizeof(t_textur));
	deb->mlx = mlx;
	deb->textur[0] = textur[0];
	deb->textur[1] = textur[1];
	deb->textur[2] = textur[2];
	deb->textur[3] = textur[3];
	deb->textur[4] = textur[4];
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

static void	ft_free_player(t_player *player)
{
}

static void	ft_free_all(t_game *game)
{
	ft_free_player(game->player);
	free(game->player);
	free(game->deb);
	free(game);
}

int			ft_end(int key, t_game *game)
{
	mlx_destroy_window(game->deb->mlx->mlx_ptr, game->deb->mlx->win_ptr);
	ft_free_all(game);
	exit(0);
	system("leaks ./a.out");
	return (1);
}

int			main(int argv, char **argc)
{
	int		fd;
	char	**tab;
	t_game	game;
	int		i;
	if(!ft_strncmp( &argc[1][ft_strlen(argc[1]) - 4],".cub",4) && (fd = open(argc[1], O_RDONLY)) >= 0)
	{
	init_game(&game, (tab = init_tab(argc[1], fd)));
	int_strat(game.deb, game.player);
		i = game.deb->resolution[1];
	while (i != game.deb->resolution[1])
		color_fc(game.deb, i++, 0);
//	mlx_hook(game.deb->mlx->win_ptr, 2, 1L << 1, ft_move, &game);
//	mlx_put_image_to_window(game.deb->mlx->mlx_ptr, game.deb->mlx->win_ptr,
//			game.deb->mlx->img_ptr, 0, 0);

//	ft_bpm((int*)(game.deb->mlx->data), game.deb->resolution);
//	printf(" \tresolution\n %d et %d\n\n",game.deb->resolution[0], game.deb->resolution[1]);
//	printf("\t textur\n SO:%s\n WE:%s\n EA:%s\n NO:%s\n S:%s\n\n", game.deb->textur[0]->name, game.deb->textur[1]->name,game.deb->textur[2]->name,game.deb->textur[3]->name,game.deb->textur[4]->name );
//	printf("\t f and c\n C: %d\n S: %d\n\n", game.deb->color_FC[0], game.deb->color_FC[1]);
//	printf(" \tplayer\n initiale pos_x = %f, pos_y= %f \n rot= %f (N0:0, EA:1,57 SO:3,14 WE:4,712)\n\n", game.player->pos_x,game.player->pos_y,game.player->rot );


//	mlx_hook(game.deb->mlx->win_ptr, 2, 1L << 1, ft_move, &game);
//	mlx_do_auto_repeat_off(mlx);
//	mlx_hook(win, KeyPress, KeyPressMask, press_handler, &struct);
//	mlx_hook(win, KeyRelease, KeyReleasMask, press_handler, &struct);
//	mlx_hook(game.deb->mlx->win_ptr, 17, (1L << 17), &ft_end, &game);
	mlx_loop(game.deb->mlx->mlx_ptr);
	}
	return (0);
}
