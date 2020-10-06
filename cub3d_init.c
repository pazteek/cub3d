/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 12:58:38 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/05 14:59:28 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_strlen_u(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

static char	**ft_tranf(char *c, char **tab)
{
	int		n;
	int		y;
	int		i;

	i = -1;
	y = 0;
	n = -1;
	while (c[++i] != '\0')
	{
		if (c[i] == '\n')
		{
//			printf("y=%d",n);
			tab[y][n+1] = '\0';
//			printf("y=%d",n);
			y++;
			n = -1;
//			printf("%s\n", tab[y-1]);
		}
		else
			tab[y][++n] = c[i];
	}
	tab[y][n+1] = '\0';
	tab[y+1] = 0;
	return (tab);
}

char		**tri(char *c)
{
	char	**tab;
	int		nb;
	int		n;
	int		y;
	int		i;

	i = 0;
	y = 1;
	nb = 0;
	n = 0;
	while (c[i] != '\0')
		if (c[i++] == '\n')
			y++;
	tab = malloc(sizeof(char*) * (y + 1));
	tab[y] = NULL;
	while (nb < y)
	{
		tab[nb] = malloc(sizeof(char) * (ft_strlen_u(&c[n]) + 1));
		n += (ft_strlen_u(&c[n]) + 1);
		nb++;
//		printf("%d et %d \n",nb , y);
	}
	return (ft_tranf(c, tab));
}

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
	return 1;
}

int		ft_color_fc(t_deb *deb, char *tab, int fc)
{
	int n;
	int i;
	int a;

	a = 0;
	n = 0;
	i = 2;
//	printf("%s\n", tab);
	deb->color_FC[fc] = 0;
	if (tab[1] == ' ')
		while (tab[i] != '\0')
		{
			a = 0;
			while(ft_compare_c_to_s(tab[i++], "1234567890"))
					a++;
			i--;

			if(a <= 3  && (tab[i]== ',' || tab[i] == '\0'))
			{
				if (255 < ft_atoi(&tab[i - a]))
					return ft_error(7);
//				printf("c ou f=%d\n",(deb->color_FC[fc] += ft_atoi(&tab[i - a]) * pow(2, 8 * (2 - n++))));
				if ((tab[i] == '\0' && n != 2) || tab[i++] != ',')
					return ft_error(7);
				while (tab[i] != ' ' && tab[i] != '\0')
					i++;
			}
		else
			ft_error(7);
//	printf("\t%d\n",i);
}
	return 1;
}
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
			deb->textur[dirc]->name, &deb->textur[0]->w, &deb->textur[0]->h);
			deb->textur[dirc]->data = mlx_get_data_addr(deb->textur[0]->img_ptr,
			&deb->textur[dirc]->bpp, &deb->textur[0]->sizeline,
			&deb->textur[dirc]->endian);
			if (deb->textur[dirc]->data == 0)
				ft_error(3);
		}
			return (1);
}

int		ft_textur_objet(t_deb *deb, char *tab)
{
	int n;
	int i;

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
			return 1;
}
