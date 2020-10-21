/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 12:18:46 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/21 16:59:11 by gbabeau          ###   ########.fr       */
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
			tab[y][n + 1] = '\0';
			y++;
			n = -1;
		}
		else
			tab[y][++n] = c[i];
	}
	tab[y][n + 1] = '\0';
	tab[y + 1] = 0;
	free(c);
	c = 0;
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
	}
	return (ft_tranf(c, tab));
}
