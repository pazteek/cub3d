/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 13:06:13 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/07 16:18:53 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			player_init(t_player *player, int y, int x, char pos)
{
	if (player->pos_x != -1)
		return (0);
	if (pos == 'N')
		player->rot = 0;
	else if (pos == 'S')
		player->rot = M_PI;
	else if (pos == 'O')
		player->rot = M_PI / 2;
	else
		player->rot = 3 * M_PI / 2;
	player->pos_x = x + 0.5;
	player->pos_y = y + 0.5;
	return (1);
}

static int	ini_cub_cub(t_deb *deb, char **tab, int i)
{
	if (!ft_strncmp("R", tab[i], 1))
		return (ft_real(&(*deb), tab[i]));
	else if (!ft_strncmp("F", tab[i], 1))
		ft_color_fc(&(*deb), tab[i], 0);
	else if (!ft_strncmp("C", tab[i], 1))
		return (ft_color_fc(&(*deb), tab[i], 1));
	else if (!ft_strncmp("NO", tab[i], 2))
		return (ft_textur_wall(&(*deb), tab[i], 0));
	else if (!ft_strncmp("EA", tab[i], 2))
		return (ft_textur_wall(&(*deb), tab[i], 1));
	else if (!ft_strncmp("SO", tab[i], 2))
		return (ft_textur_wall(&(*deb), tab[i], 2));
	else if (!ft_strncmp("WE", tab[i], 2))
		return (ft_textur_wall(&(*deb), tab[i], 3));
	else if (!ft_strncmp("S", tab[i], 1))
		return (ft_textur_objet(&(*deb), tab[i]));
	else if (tab[i][0] == '\0')
		return (0);
	else
		return (ft_error(1));
	return (1);
}

void		ft_deb(char **tab, t_deb *deb, t_player *player)
{
	int	i;
	int	n;

	n = 0;
	i = -1;
	while (n != 8 && tab[++i] != 0 && tab[i][0] != '1')
	{
		n += ini_cub_cub(deb, tab, i);
	}
	if (n == 8)
		n = ft_map(&(*deb), &tab[i + 1], player);
	else if (n >= 0)
		ft_error(10);
}

void		init_deb_mlx(t_mlx *mlx, int resolution[2])
{
	unsigned int	img_color;
	int				a;
	int				b;
	int				c;
	int				i;

	img_color = mlx_get_color_value(mlx->mlx_ptr, 0xffff00);
	mlx->c_f[0] = img_color;
	img_color = mlx_get_color_value(mlx->mlx_ptr, 0xff0000);
	mlx->c_f[1] = img_color;
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, resolution[0], resolution[1],
					"cub3d");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, resolution[0], resolution[1]);
	mlx->data = mlx_get_data_addr(mlx->img_ptr, &(mlx->bpp),
	&(mlx->sizeline), &(mlx->endian));
}
