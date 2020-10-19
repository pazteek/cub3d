/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_fc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 12:18:42 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/19 18:28:35 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_bgr(int *datas, int *data)
{
	*datas = *data;
}

void		display_fc(float z, t_deb *deb, int m[2], int v)
{
	while (z && v <= (deb->resolution[1] / 2))
	{
		if (v != (deb->resolution[1] / 2))
			ft_bgr((int*)(&deb->mlx->data[m[0]]),
					(int*)(&deb->mlx->c_f[0]));
		ft_bgr((int*)(&deb->mlx->data[m[1]]),
				(int*)((&deb->mlx->c_f[1])));
		ft_pas_wall(&z, m, &v, deb);
	}
}
