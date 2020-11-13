/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 12:16:52 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/21 14:46:58 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		test_textur(char *name, t_game game)
{
	int	fd;

	fd = 0;
	if (0 != ft_strncmp(&name[ft_strlen(name) - 4], ".xpm", 4))
		ft_error(3, game);
	if (0 > (fd = open(name, O_RDONLY)))
		ft_error(3, game);
	close(fd);
	return (1);
}

int		ft_textur_wall(t_deb *deb, char *tab, int dirc, t_game game)
{
	int i;

	i = 2;
	if (tab[i] != '\0' && tab[i] == ' ')
	{
		while (tab[i] == ' ')
			i++;
		if (tab[i] != '.')
			return (ft_error(13, game));
		if (deb->textur[dirc]->name != NULL)
			return (ft_error(13, game));
		deb->textur[dirc]->name = ft_strdup(&tab[i]);
		test_textur(deb->textur[dirc]->name, game);
		deb->textur[dirc]->img_ptr = mlx_xpm_file_to_image(deb->mlx->mlx_ptr,
		deb->textur[dirc]->name, &deb->textur[dirc]->w, &deb->textur[dirc]->h);
		deb->textur[dirc]->data = mlx_get_data_addr(deb->textur[dirc]->img_ptr,
				&deb->textur[dirc]->bpp, &deb->textur[dirc]->sizeline,
				&deb->textur[dirc]->endian);
		if (deb->textur[dirc]->data == 0)
			ft_error(3, game);
	}
	return (1);
}
