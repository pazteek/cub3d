/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:11:26 by gbabeau           #+#    #+#             */
/*   Updated: 2020/01/30 14:29:13 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_flags_0_c(int nbr, char **variable)
{
	char	*variable_f;
	int		a;
	int		size;

	size = 0;
	while ((*variable)[size] != 'x' || (*variable)[size + 1] != '\0')
		size++;
	a = -1;
	if (!(variable_f = malloc(nbr + 2)))
		return (0);
	variable_f[nbr + 1] = '\0';
	variable_f[nbr] = 'x';
	while (size-- != 0)
		variable_f[--nbr] = (*variable)[size];
	while (nbr > 0)
		variable_f[--nbr] = '0';
	ft_efface((*variable));
	return (variable_f);
}

char	*ft_flags_tiret_c(int nbr, char **variable)
{
	char	*variable_f;
	int		a;

	a = 0;
	if ((int)ft_strlen(*variable) - 1 < nbr)
	{
		if (!(variable_f = malloc(nbr + 2)))
			return (0);
		while ((a == 0 || (((*variable)[a + 1] != '\0')
			&& (*variable)[a] != 'x')))
		{
			variable_f[a] = (*variable)[a];
			a++;
		}
		while (a < nbr)
			variable_f[a++] = ' ';
		variable_f[a] = 'x';
		variable_f[a + 1] = '\0';
		ft_efface((*variable));
		return (variable_f);
	}
	return (*variable);
}
