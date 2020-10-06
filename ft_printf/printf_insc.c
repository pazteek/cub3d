/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_insc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 11:57:00 by gbabeau           #+#    #+#             */
/*   Updated: 2020/01/30 18:08:54 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_insc(char *var, char **variable, int f)
{
	int	n;
	int	i;

	i = 0;
	n = ft_strlen(var);
	*variable = calloc(1, n + 1);
	while (i < n)
	{
		(*variable)[i] = var[i];
		i++;
	}
	if (f)
		free(var);
}

void	ft_printf_insc_c(char *var, char **variable)
{
	int	n;
	int	i;

	i = 0;
	n = 3;
	*variable = calloc(1, n);
	while (i < n)
	{
		(*variable)[i] = var[i];
		i++;
	}
	free(var);
}
