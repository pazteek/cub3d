/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_tiret.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 12:13:40 by gbabeau           #+#    #+#             */
/*   Updated: 2020/02/04 15:04:26 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_flags_tiret(int nbr, char **variable)
{
	char	*variable_f;
	int		a;

	if (nbr < 0)
		nbr *= -1;
	a = -1;
	if ((int)ft_strlen(*variable) < nbr)
	{
		if (!(variable_f = malloc(nbr + 1)))
			return (0);
		while ((*variable)[++a] != '\0')
			variable_f[a] = (*variable)[a];
		while (a < nbr)
			variable_f[a++] = ' ';
		variable_f[a] = '\0';
		ft_efface((*variable));
		return (variable_f);
	}
	return (*variable);
}

char	*ft_flags_tiret_0(char **variable)
{
	char *variable_f;

	if (!(variable_f = malloc(2)))
		return (0);
	ft_efface((*variable));
	variable_f[0] = ' ';
	variable_f[1] = '\0';
	return (variable_f);
}
