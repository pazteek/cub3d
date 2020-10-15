/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 16:32:15 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/15 19:37:25 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stdio.h"

int		ft_real(t_deb *deb, char *tab)
{
	int	i;
	int	n;
	float *dist;
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
	if (!(dist = malloc(sizeof(float) * 10000)))
		return (0);
	deb->dist = dist;
	return (1);
}

int		cloro_fc_2(char *tab, int *i, int *a, int *n)
{
	int img_color;

	img_color = ft_atoi(&tab[*i - *a]) * pow(256, 2 - *n);
	if (((tab[*i] != '\0' && *n != 2) && tab[*i] != ',')
			|| ft_atoi(&tab[*i - *a]) > 255)
		return (ft_error(7));
	*n += 1;
	while (tab[*i] == ' ')
		*i += 1;
	if (tab[*i] != '\0')
		*i += 1;
	return (img_color);
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
			if (a <= 4 && (tab[i] == ',' || tab[i] == '\0'))
				img_color += cloro_fc_2(tab, &i, &a, &n);
			else ft_error(7);
		}
	else
		ft_error(7);
	deb->mlx->c_f[fc] = mlx_get_color_value(deb->mlx->mlx_ptr, img_color);
	return (1);
}
