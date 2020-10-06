/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:44:04 by gbabeau           #+#    #+#             */
/*   Updated: 2020/02/04 16:15:54 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_flags_0_point(int nbr, char **variable)
{
	char	*variable_f;
	int		i;
	int		a;

	a = -1;
	i = ft_strlen((*variable));
	if (i > nbr)
		return (*variable);
	if (!(variable_f = malloc(nbr + 1)))
		return (0);
	while (++a < nbr - i)
		variable_f[a] = ' ';
	while ((*variable)[a - (nbr - i)] != '\0')
	{
		variable_f[a] = (*variable)[a - (nbr - i)];
		a++;
	}
	variable_f[a] = '\0';
	ft_efface((*variable));
	return (variable_f);
}

static char	*ft_flags_0_neg(int nbr, char **variable, char str)
{
	char	*variable_f;
	int		a;
	int		size;

	size = ft_strlen(*variable);
	a = -1;
	if (str != 'i' && str != 'd')
		nbr++;
	variable_f = malloc(nbr + 1);
	variable_f[nbr] = '\0';
	while (size-- != 1)
		variable_f[--nbr] = (*variable)[size];
	variable_f[--nbr] = '0';
	while (nbr > 1)
		variable_f[--nbr] = '0';
	variable_f[0] = '-';
	ft_efface((*variable));
	return (variable_f);
}

static char	*ft_flags_0_pos(int nbr, char **variable)
{
	char	*variable_f;
	int		a;
	int		size;

	size = ft_strlen(*variable);
	if (!ft_compare_s_to_s("-0123456789abcdefABCDEF", (*variable)))
		return (ft_flags_tiret(10, &(*variable)));
	a = -1;
	if (!(variable_f = malloc(nbr + 1)))
		return (0);
	variable_f[nbr] = '\0';
	while (size-- != 0)
		variable_f[--nbr] = (*variable)[size];
	while (nbr > 0)
		variable_f[--nbr] = '0';
	ft_efface((*variable));
	return (variable_f);
}

static char	*ft_0_s(int nbr, int size, char **variable)
{
	char	*variable_f;
	int		a;

	a = 0;
	if (size > nbr)
		return (*variable);
	if (!(variable_f = malloc(nbr + 1)))
		return (0);
	while (a < nbr - size)
		variable_f[a++] = '0';
	a--;
	while (++a < nbr)
		variable_f[a] = (*variable)[a + size - nbr];
	variable_f[a] = '\0';
	return (variable_f);
}

char		*ft_flags_0(int nbr, char **variable, char str)
{
	char	*variable_f;
	int		size;

	size = ft_strlen(*variable);
	if (str == 's')
		return (variable_f = ft_0_s(nbr, size, &(*variable)));
	if (nbr == 0)
	{
		if ((ft_compare_c_to_s(str, "diup") && ft_atoi(*variable) == 0)
		|| (str == 'x' && ft_atoi_base(*variable, "0123456789abcdef") == 0)
		|| (str == 'X' && ft_atoi_base(*variable, "0123456789ABCDEF") == 0))
		{
			if (!(variable_f = malloc(1)))
				return (0);
			variable_f[0] = '\0';
			ft_efface((*variable));
			return (variable_f);
		}
		return (*variable);
	}
	if (size > nbr)
		return (*variable);
	if ((*variable)[0] != '-')
		return (variable_f = ft_flags_0_pos(nbr, &(*variable)));
	return (variable_f = ft_flags_0_neg(nbr, &(*variable), str));
}
