/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:15:49 by gbabeau           #+#    #+#             */
/*   Updated: 2020/02/01 13:15:20 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	**ft_printf_initialisation(int n, const char *str)
{
	int		i;
	char	**variable;

	i = 0;
	n = 0;
	while (str[i] != '\0' && str[i + 1] != '\0')
	{
		if ('%' == str[i] && ft_compare_c_to_s(str[ft_str_flags(i + 1, str)],
			"csidupxX%"))
			n++;
		i++;
	}
	if (!(variable = (char**)malloc(sizeof(char*) * (n + 1))))
		return (NULL);
	i = 0;
	variable[n] = NULL;
	return (variable);
}

static int	ft_affichae_compt(char c, int compt)
{
	ft_putchar_fd(c, 1);
	return (compt + 1);
}

static int	ft_affichae_variable(char *variable, char str, int compt)
{
	int	nbr;

	nbr = 0;
	if (!ft_compare_c_to_s(str, "c%"))
	{
		while (variable[nbr] != '\0')
			compt = ft_affichae_compt(variable[nbr++], compt);
		ft_efface(variable);
	}
	else
	{
		while (variable[nbr] != 'x' || variable[nbr + 1] != '\0')
			compt = ft_affichae_compt(variable[nbr++], compt);
		ft_efface_c(variable);
	}
	return (compt);
}

static int	final(const char *str, char **variable)
{
	int	n;
	int	i;
	int	compt;

	compt = 0;
	n = 0;
	i = 0;
	while (str[i] != '\0' && str[i + 1] != '\0')
		if ('%' == str[i] && ft_compare_c_to_s(str[ft_str_flags(i + 1, str)],
			"csidupxX%"))
		{
			compt = ft_affichae_variable(variable[n],
				str[ft_str_flags(i + 1, str)], compt);
			n++;
			i = ft_str_flags(i + 1, str);
			if (ft_compare_c_to_s(str[i], "csidupxX%"))
				i++;
		}
		else
			compt = ft_affichae_compt((char)str[i++], compt);
	if (str[i] != '\0')
		compt = ft_affichae_compt((char)str[i], compt);
	free(variable);
	variable = 0;
	return (compt);
}

int			ft_printf(const char *str, ...)
{
	char	**variable;
	int		n;
	va_list	ap;
	int		i;

	n = 0;
	i = 0;
	variable = 0;
	va_start(ap, str);
	variable = ft_printf_initialisation(n, str);
	n = 0;
	while (str[i] != '\0' && str[i + 1] != '\0')
	{
		if ('%' == str[i] && ft_compare_c_to_s(str[ft_str_flags(i + 1, str)],
			"csidupxX%"))
		{
			if (0 == ft_conversion_printf(&str[i + 1], &ap, &variable[n]))
				return (error(variable));
			n++;
			if (str[ft_str_flags(i + 1, str)] == '%')
				i++;
		}
		i++;
	}
	return (final(str, variable));
}
