/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 12:16:52 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/16 16:11:18 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_textur_wall(t_deb *deb, char *tab, int dirc)
{
	int n;
	int i;

	n = 0;
	i = 2;
	if (tab[i] != '\0' && tab[i] == ' ')
	{
		while (tab[i] == ' ')
			i++;
		deb->textur[dirc]->name = ft_strdup(&tab[i]);
		deb->textur[dirc]->img_ptr = mlx_xpm_file_to_image(deb->mlx->mlx_ptr,
		deb->textur[dirc]->name, &deb->textur[dirc]->w, &deb->textur[dirc]->h);
		deb->textur[dirc]->data = mlx_get_data_addr(deb->textur[dirc]->img_ptr,
				&deb->textur[dirc]->bpp, &deb->textur[dirc]->sizeline,
				&deb->textur[dirc]->endian);
		if (deb->textur[dirc]->data == 0)
			ft_error(3);
	}
	return (1);
}

int		ft_textur_objet(t_deb *deb, char *tab)
{
	int	n;
	int	i;

	i = 2;
	n = 0;
	while (tab[i] == ' ')
		i++;
	deb->textur[4]->name = ft_strdup(&tab[i]);
	deb->textur[4]->img_ptr = mlx_xpm_file_to_image(deb->mlx->mlx_ptr,
			deb->textur[4]->name, &deb->textur[4]->w, &deb->textur[4]->h);
	deb->textur[4]->data = mlx_get_data_addr(deb->textur[4]->img_ptr,
			&deb->textur[4]->bpp, &deb->textur[4]->sizeline,
			&deb->textur[4]->endian);
	if (deb->textur[4]->data == 0)
		ft_error(3);
	return (1);
}
