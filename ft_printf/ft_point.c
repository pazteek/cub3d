/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:46:46 by gbabeau           #+#    #+#             */
/*   Updated: 2020/02/01 19:26:39 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_flags_point_1(int i, char **variable, char *variable_f)
{
	i = ft_strlen(*variable);
	while (--i >= 0 &&
		ft_compare_c_to_s((*variable)[i], "0123456789abcdefABCDEF"))
		variable_f[i] = (*variable)[i];
	variable_f[ft_strlen((*variable))] = '\0';
	ft_efface((*variable));
	return (variable_f);
}

char		*ft_flags_point_0(int nbr, char **variable)
{
	char	*variable_f;
	int		i;
	int		a;
	int		n;

	a = -1;
	i = ft_strlen((*variable));
	if (nbr == 0 && !(ft_compare_s_to_s("123456789abcdefABCDEF", (*variable))))
		return (*variable = ft_flags_0(0, &(*variable), 'd'));
	if (nbr <= 0)
		return (*variable);
	if (nbr > i)
		return (ft_flags_0(nbr, &(*variable), 'd'));
	if (!(variable_f = malloc(i + 1)))
		return (0);
	while (!(ft_compare_c_to_s((*variable)[++a], "0123456789abcdefABCDEF")))
		if ((variable_f[a] = (*variable)[a]) == '-')
			n = 1;
	i = nbr - ft_strlen(&(*variable)[a]);
	while (--i >= 0)
		variable_f[--a] = '0';
	if (n == 1)
		variable_f[0] = '-';
	return (variable_f = ft_flags_point_1(i, &(*variable), variable_f));
}

char		*ft_flags_point(int nbr, char **variable)
{
	char	*variable_f;
	int		a;

	a = -1;
	if (nbr >= 0 && (int)ft_strlen((*variable)) > nbr)
	{
		if (!(variable_f = malloc(nbr + 1)))
			return (0);
		while ((*variable)[a + 1] != '\0' && ++a < nbr)
			variable_f[a] = (*variable)[a];
		variable_f[a] = '\0';
		ft_efface((*variable));
		return (variable_f);
	}
	return (*variable);
}
