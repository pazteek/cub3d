/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 13:00:57 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/07 16:36:25 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float		**ft_tab_objet(int nbr_objet, char **map)
{
	int		y;
	int		x;
	float	**objet;

	y = 0;
	x = -1;
	objet = malloc(sizeof(float*) * (nbr_objet + 1));
	objet[nbr_objet] = NULL;
	while (0 != nbr_objet && map[y] != NULL)
	{
		if (map[y][++x] == '2')
		{
			objet[nbr_objet - 1] = malloc(sizeof(float) * 2);
			objet[nbr_objet - 1][0] = y + 0.5;
			objet[nbr_objet - 1][1] = x + 0.5;
			nbr_objet--;
		}
		else if (map[y][x] == '\0')
		{
			y++;
			x = -1;
		}
	}
	return (objet);
}

int		ft_size_map(char *tab)
{
	int		i;
	int		n;

	i = -1;
	n = 0;
	while (tab[++i] != '\0')
		if (tab[i] != ' ')
			n++;
	return (n);
}

void	ft_copy_map(char *tab, char *map)
{
	int	i;
	int	y;

	i = -1;
	y = 0;
	while (tab[++i] != '\0')
	{
		map[i] = tab[i];
	}
	map[i] = '\0';
}

char	**ft_malloc_struc_map(char **tab)
{
	int		i;
	int		y;
	char	**map;

	y = 0;
	i = -1;
	while (tab[++i][0] == '\0')
		;
	while (tab[i] != 0 && tab[i++][0] != '\0')
		y++;
	if (tab[i] != 0 && tab[i + 1] != 0)
	{
		ft_error(2);
		return (NULL);
	}
	map = malloc(sizeof(char*) * (y + 1));
	map[y] = 0;
	y = 0;
	i = -1;
	while (tab[++i][0] == '\0')
		;
	while (tab[i] != 0 && tab[i][0] != '\0')
	{
		map[y++] = ft_strdup(tab[i]);
		i++;
	}
	return (tab);
}

void	ft_transition(char **tab, t_deb *deb)
{
	int		i;
	int		x;
	int		objet;

	i = 0;
	objet = 0;
	while (tab[i] != NULL)
		i++;
	deb->map = malloc(sizeof(char*) * (i + 1));
	deb->map[i] = 0;
	i = 0;
	x = -1;
	while (tab[i] != NULL)
	{
		deb->map[i] = malloc(ft_strlen_cub(tab[i]) + 1);
		while (tab[i][++x] != '\0')
			if ((deb->map[i][x] = tab[i][x]) == '2')
				objet++;
		deb->map[i][x] = '\0';
		x = -1;
		i++;
	}
	deb->objet = ft_tab_objet(objet, deb->map);
}
