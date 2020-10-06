/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:29:08 by gbabeau           #+#    #+#             */
/*   Updated: 2020/02/01 13:15:32 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_flags_deb(char *flags)
{
	if (ft_atoi(flags) >= 0)
		return (ft_atoi(flags));
	return (0);
}

static int	ft_if_flags(char *flags)
{
	if (ft_compare_c_to_s(flags[0], "-*.0"))
		if (ft_compare_c_to_s(flags[1], "*0123456789") || (flags[0] == '.'
			&& ft_compare_c_to_s(flags[1], "iduxXspc")))
			return (1);
	return (0);
}

static char	*ft_flags_nbrs(char *flags, char **variable, int *stars, char *str)
{
	int	stars_n;
	int	i;

	stars_n = 0;
	if (flags[1] == '*')
		stars_n = 1;
	i = 0;
	while (flags[++i] != '\0')
		if (ft_if_flags(&flags[i]))
		{
			if (flags[1 + i] == '*')
				if (ft_compare_c_to_s(flags[i], str))
					if (!(*variable = ft_flags(&flags[i], &(*variable),
							stars[stars_n], stars)))
						return (0);
			if (flags[1 + i] == '*')
				stars_n++;
			else if (ft_compare_c_to_s(flags[i], str))
				if (!(*variable = (ft_flags(&flags[i], &(*variable),
					ft_flags_deb(&flags[1 + i]), stars))))
					return (0);
			while (ft_compare_c_to_s(flags[i + 1], "0123456789"))
				i++;
		}
	return (*variable);
}

char		*ft_flags_modif_final(char *flags, char **variable, int *stars,
		char str)
{
	int	stars_n;
	int	i;

	stars_n = 0;
	i = 0;
	if (ft_compare_c_to_s(str, "iduxXspc%"))
	{
		if (!(*variable = ft_flags_nbrs(flags, &(*variable), stars, ".")))
			return (0);
		if (!(*variable = ft_flags_nbrs(flags, &(*variable), stars, "-0*")))
			return (0);
	}
	if (str == 'p')
		if (!((*variable) = ft_p(&(*variable))))
			return (0);
	if (flags[1] == '*')
		return (*variable = (ft_final(stars[0], &(*variable), str)));
	if (ft_compare_c_to_s(flags[1], "-123456789"))
		return (*variable = (ft_final(ft_atoi(&flags[1]), &(*variable), str)));
	return (ft_final(ft_flags_deb(flags), &(*variable), str));
}
