/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_c_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 12:05:25 by gbabeau           #+#    #+#             */
/*   Updated: 2020/02/04 15:05:16 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_et(char *flags, int *stars, char comp)
{
	int	i;
	int	a;

	a = -1;
	i = 0;
	while (flags[i] != '%')
		if (flags[i--] == '*')
			a++;
	if (a == -1)
		return (-1);
	if (stars[a] >= 0)
		return (stars[a]);
	else if (comp != '.')
		return (stars[a] * -1);
	else
		return (-1);
}

int			ft_j(char *flags, char comp, int *stars, int nbr)
{
	int	i;

	i = 0;
	while (flags[i] != '%')
		i--;
	if (nbr < 0 && comp != '.')
		return (1);
	while (flags[i] != '\0')
		if (flags[i++] == comp
			&& (comp != '0' || ft_compare_c_to_s(flags[i - 2], "%*")))
			if ((ft_compare_c_to_s(flags[i], "0123456789*")))
			{
				if (flags[i] == '*' && ft_et(&flags[i], stars, comp) >= 0)
					if ((comp == '.' && (nbr > ft_et(&flags[i], stars, comp)
						&& ft_et(&flags[i], stars, comp) != -1))
						|| (comp != '.'
						&& nbr <= ft_et(&flags[i], stars, comp)))
						return (0);
				if ((flags[i] != '*'))
					if (ft_atoi(&flags[i]) >= 0)
						if ((comp == '.' && nbr > ft_atoi(&flags[i]))
						|| (comp != '.' && nbr <= ft_atoi(&flags[i])))
							return (0);
			}
	return (1);
}

char		*ft_p(char **variable)
{
	int		i;
	char	*variable_f;

	i = ft_strlen(*variable);
	if (!(variable_f = malloc(i + 3)))
		return (0);
	variable_f[0] = '0';
	variable_f[1] = 'x';
	i = -1;
	while ((*variable)[++i] != '\0')
		variable_f[2 + i] = (*variable)[i];
	variable_f[i + 2] = '\0';
	ft_efface((*variable));
	return (variable_f);
}

void		ft_efface(char *l)
{
	int	i;

	i = 0;
	if (l != 0)
	{
		while (l[i] != '\0')
			l[i++] = '\0';
		free(l);
		l = 0;
	}
}

void		ft_efface_c(char *l)
{
	int	i;

	i = 0;
	if (l != 0)
	{
		while (l[i] != 'x' || l[i + 1] != '\0')
			l[i++] = '\0';
		l[i] = '\0';
		free(l);
		l = 0;
	}
}
