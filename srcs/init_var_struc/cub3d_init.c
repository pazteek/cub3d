/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 12:58:38 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/08 16:47:36 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

	n = 0;
	i = 2;
	(void)deb;
	if (tab[1] == ' ')
		while (tab[i] != '\0')
		{
			a = 0;
			while (ft_compare_c_to_s(tab[i++], "1234567890"))
				a++;
			i--;
			if (a <= 3 && (tab[i] == ',' || tab[i] == '\0'))
			{
				if (255 < ft_atoi(&tab[i - a]))
					return (ft_error(7));
				if ((tab[i] == '\0' && n != 2) || tab[i++] != ',')
					return (ft_error(7));
				while (tab[i] != ' ' && tab[i] != '\0')
					i++;
			}
			else
				ft_error(fc);
		}
	return (1);
}
