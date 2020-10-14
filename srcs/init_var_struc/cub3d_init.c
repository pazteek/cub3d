/**************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 12:58:38 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/14 18:02:25 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stdio.h"

int		ft_real(t_deb *deb, char *tab)
{
	int	i;
	int	n;

	n = 0;
	i = 1;
	if (tab[i] == ' ')
		while (tab[i] != '\0')
		{
			if (tab[i] != ' ')
				ft_error(5);
			while (tab[i] != '\0' && tab[i] == ' ')
				i++;
			if (n != 2 && ft_compare_c_to_s(tab[i], "123456789"))
				deb->resolution[n++] = ft_atoi(&tab[i]);
			else if (tab[i] != '\0')
				ft_error(5);
			while (ft_compare_c_to_s(tab[i], "0123456789"))
				i++;
		}
	else
		ft_error(5);
	if (n != 2)
		ft_error(5);
	init_deb_mlx(deb->mlx, deb->resolution);
	return (1);
}

int		ft_color_fc(t_deb *deb, char *tab, int fc)
{
	int n;
	int i;
	int a;
	int img_color;

	n = 0;
	i = 2;
	img_color = 0;
	if (tab[1] == ' ')
		while (tab[i] != '\0')
		{
			a = 0;
			while (ft_compare_c_to_s(tab[i++], "1234567890"))
				a++;
			i--;
			if (a <= 3 && (tab[i] == ',' || tab[i] == '\0'))
			{
				if (ft_atoi(&tab[i - a]) > 255)
					return (ft_error(7));
				printf("%d\n",ft_atoi(&tab[i - a]));
				img_color += ft_atoi(&tab[i - a]) * pow(256, 3 - n);
				if ((tab[i] == '\0' && n != 2) || tab[i++] != ',')
					return (ft_error(7));
				n++;
			}
			else
				ft_error(fc);
		}
	deb->mlx->c_f[fc] = mlx_get_color_value(deb->mlx->mlx_ptr, img_color);
	return (1);
}
