/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_final_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 13:13:47 by gbabeau           #+#    #+#             */
/*   Updated: 2020/01/30 18:19:21 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_final_pos_c(int size_f, char **variable)
{
	char	*variable_f;
	int		b;
	int		i;

	i = 0;
	b = 0;
	while ((*variable)[b] != 'x' || (*variable)[b + 1] != '\0')
		b++;
	if (size_f > b)
	{
		if (!(variable_f = malloc(size_f + 2)))
			return (0);
		variable_f[size_f + 1] = '\0';
		variable_f[size_f] = 'x';
		while (b-- >= 0)
			variable_f[--size_f] = (*variable)[b];
		while (size_f >= 0)
			variable_f[size_f--] = ' ';
		ft_efface_c((*variable));
		return (variable_f);
	}
	else
		return (*variable);
}

static char	*ft_final_neg_c(int size_f, char **variable)
{
	char	*variable_f;
	int		b;
	int		i;

	i = -1;
	b = 0;
	while ((*variable)[b] != 'x' || (*variable)[b + 1] != '\0')
		b++;
	size_f *= -1;
	if (size_f > b)
	{
		if (!(variable_f = malloc(size_f + 2)))
			return (0);
		variable_f[size_f + 1] = '\0';
		variable_f[size_f] = 'x';
		while (++i < b)
			variable_f[i] = (*variable)[i];
		while (size_f > i)
			variable_f[i++] = ' ';
		ft_efface_c((*variable));
		return (variable_f);
	}
	else
		return (*variable);
}

static char	*ft_final_pos(int size_f, char **variable)
{
	char	*variable_f;
	int		b;
	int		i;

	i = 0;
	b = ft_strlen(*variable);
	if (size_f > b)
	{
		if (!(variable_f = malloc(size_f + 1)))
			return (0);
		variable_f[size_f] = '\0';
		while (b-- >= 0)
			variable_f[--size_f] = (*variable)[b];
		while (size_f >= 0)
			variable_f[size_f--] = ' ';
		ft_efface((*variable));
		return (variable_f);
	}
	else
		return (*variable);
}

static char	*ft_final_neg(int size_f, char **variable)
{
	char	*variable_f;
	int		b;
	int		i;

	i = 0;
	b = ft_strlen(*variable);
	size_f *= -1;
	if (size_f > b)
	{
		if (!(variable_f = malloc(size_f + 1)))
			return (0);
		variable_f[size_f] = '\0';
		while (i != b)
		{
			variable_f[i] = (*variable)[i];
			i++;
		}
		while (size_f > i)
			variable_f[i++] = ' ';
		ft_efface((*variable));
		return (variable_f);
	}
	else
		return (*variable);
}

char		*ft_final(int size_f, char **variable, char str)
{
	char	*variable_f;
	int		b;
	int		i;

	i = 0;
	b = ft_strlen(*variable);
	if (!ft_compare_c_to_s(str, "c%"))
	{
		if (size_f > 0)
			return (variable_f = ft_final_pos(size_f, &(*variable)));
		else
			return (variable_f = ft_final_neg(size_f, &(*variable)));
	}
	if (size_f > 0)
		return (variable_f = ft_final_pos_c(size_f, &(*variable)));
	else
		return (variable_f = ft_final_neg_c(size_f, &(*variable)));
}
