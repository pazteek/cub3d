/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_fc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 12:18:42 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/07 12:21:51 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <math.h>

void		ft_put_m(int a, int b)
{
	a = b;
}

void		mlx_pixel_put_image(t_mlx *mlx, int x, int y, int cf)
{
	int	o;

	o = y * mlx->sizeline + x * mlx->bpp / 8;
	ft_put_m((int)(mlx->data[o]), mlx->c_f[cf]);
}

static void	mlx_pixel_put_image_2(t_mlx *mlx, int x, int y, int cf)
{
	int	o;

	o = y * mlx->sizeline + x * mlx->bpp / 8;
	ft_put_m((int)(mlx->data[o]), mlx->c_f[cf]);
}

void		color_fc(t_deb *deb, int i, int v)
{
	i--;
	while ((deb->resolution[1] / 2) - v > 0
		&& (deb->resolution[1] / 2) + v < deb->resolution[1])
	{
		mlx_pixel_put_image_2(deb->mlx, i, (deb->resolution[1] / 2) + v, 0);
		mlx_pixel_put_image_2(deb->mlx, i, (deb->resolution[1] / 2) - v++, 1);
	}
}
