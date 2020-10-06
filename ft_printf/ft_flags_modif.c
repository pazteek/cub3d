/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_modif.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:37:53 by gbabeau           #+#    #+#             */
/*   Updated: 2020/02/01 19:18:16 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_flags_int_point(char *flags, char **variable, int nbr,
		int *stars)
{
	char	str;

	str = flags[ft_strlen(flags) - 1];
	if (nbr < 0)
		return (ft_flags_0(1, &(*variable), str));
	else if ((*variable)[0] == '-')
		nbr++;
	if (ft_j(flags, '0', stars, nbr))
	{
		if (ft_j(flags, '-', stars, nbr))
			return (ft_flags_0(nbr, &(*variable), str));
		return (ft_flags_0(nbr, &(*variable), str));
	}
	return (ft_flags_point_0(nbr, &(*variable)));
}

char		*ft_flags_int(char *flags, char **variable, int nbr, int *stars)
{
	char	str;

	str = flags[ft_strlen(flags) - 1];
	if (flags[0] == '-' && !ft_compare_c_to_s(flags[-1], "."))
	{
		if (str == 'p' && nbr >= 2)
			nbr -= 2;
		return (ft_flags_tiret(nbr, &(*variable)));
	}
	if (flags[0] == '0' && !ft_compare_c_to_s('-', flags))
	{
		if (ft_j(flags, '.', stars, nbr))
		{
			if (nbr > 0)
				return (ft_flags_0(nbr, &(*variable), (str)));
			return (ft_flags_tiret(nbr, &(*variable)));
		}
		return (ft_flags_0_point(nbr, &(*variable)));
	}
	return (ft_flags_int_point(flags, &(*variable), nbr, stars));
}

char		*ft_flags_c(char *flags, char **variable, int nbr)
{
	char	str;

	str = flags[ft_strlen(flags) - 1];
	if (nbr < 0)
		nbr *= -1;
	if (flags[0] == '-')
		return (ft_flags_tiret_c(nbr, &(*variable)));
	if (flags[0] == '0' && !ft_compare_c_to_s('-', flags))
	{
		if (nbr == 0)
			nbr++;
		return (ft_flags_0_c(nbr, &(*variable)));
	}
	return (*variable);
}

char		*ft_flags_string(char *flags, char **variable, int nbr)
{
	char	str;

	str = flags[ft_strlen(flags) - 1];
	if (flags[0] == '0')
		return (ft_flags_0(nbr, &(*variable), str));
	if (flags[0] == '-')
		return (ft_flags_tiret(nbr, &(*variable)));
	if (flags[0] == '.')
	{
		return (ft_flags_point(nbr, &(*variable)));
	}
	return (*variable);
}

char		*ft_flags(char *flags, char **variable, int nbr, int *stars)
{
	if (ft_compare_c_to_s(flags[ft_strlen(flags) - 1], "iduxXp"))
		return (ft_flags_int(flags, &(*variable), nbr, stars));
	if (ft_compare_c_to_s(flags[ft_strlen(flags) - 1], "sp"))
		return (ft_flags_string(flags, &(*variable), nbr));
	if (ft_compare_c_to_s(flags[ft_strlen(flags) - 1], "c%"))
		return (ft_flags_c(flags, &(*variable), nbr));
	return (*variable);
}
