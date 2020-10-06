/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_print.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:31:43 by gbabeau           #+#    #+#             */
/*   Updated: 2020/02/25 15:46:57 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_init_flags(const char *str, char **flags)
{
	int	i;
	int	a;

	i = ft_str_flags(0, str);
	a = 0;
	*flags = ft_calloc(i + 2, 1);
	(*flags)[0] = '%';
	while (++a < i + 2)
		(*flags)[a] = str[a - 1];
	(*flags)[a] = '\0';
	return (i);
}

static int	*ft_start(char *flags, va_list *ap)
{
	int	*stars;
	int	i;
	int	a;

	a = 0;
	i = -1;
	while (flags[++i] != '\0')
		if (flags[i] == '*')
			a++;
	if (!(stars = (int*)malloc(sizeof(int) * a)))
		return (0);
	i = -1;
	a = 0;
	while (flags[++i] != '\0')
		if (flags[i] == '*')
			stars[a++] = va_arg(*ap, int);
	return (stars);
}

static void	ft_variable_ap(char type, va_list *ap, char **variable)
{
	if ('c' == type)
	{
		ft_printf_insc_c(ft_ctoa(va_arg(*ap, int)), &(*variable));
	}
	if ('s' == type)
		ft_printf_insc(ft_str(va_arg(*ap, char*)), &(*variable), 0);
	if ('i' == type || 'd' == type)
		ft_printf_insc(ft_itoa(va_arg(*ap, int)), &(*variable), 1);
	if ('u' == type)
		ft_printf_insc(ft_uitoa(va_arg(*ap, unsigned int)), &(*variable), 1);
	if ('p' == type)
	{
		ft_printf_insc(ft_convert_base_p(ft_ultoa(va_arg(*ap,
		unsigned long int)), "0123456789", "0123456789abcdef"), &(*variable),
			1);
	}
	if ('x' == type)
		ft_printf_insc(ft_convert_base(ft_uitoa(va_arg(*ap, unsigned int)),
		"0123456789", "0123456789abcdef"), &(*variable), 1);
	if ('X' == type)
		ft_printf_insc(ft_convert_base(ft_uitoa(va_arg(*ap, unsigned int)),
			"0123456789", "0123456789ABCDEF"), &(*variable), 1);
	if ('%' == type)
		ft_printf_insc_c(ft_ctoa('%'), &(*variable));
}

int			ft_conversion_printf(const char *str, va_list *ap, char **variable)
{
	int		i;
	char	*flags;
	int		*stars;

	stars = 0;
	flags = 0;
	i = ft_init_flags(str, &flags);
	if (ft_compare_c_to_s('*', flags))
		stars = ft_start(flags, &(*ap));
	ft_variable_ap(str[i], &(*ap), &(*variable));
	*variable = ft_flags_modif_final(flags, &(*variable), stars, str[i]);
	ft_efface(flags);
	if (stars != 0)
	{
		free(stars);
		stars = 0;
	}
	if (!(*variable))
		return (0);
	return (1);
}
