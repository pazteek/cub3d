/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlll.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:16:47 by gbabeau           #+#    #+#             */
/*   Updated: 2020/02/01 13:14:57 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_str_flags(int i, const char *str)
{
	while (ft_compare_c_to_s(str[i], "-0.*") || ft_atoi(&str[i]))
		i++;
	return (i);
}

char	*ft_ctoa(char c)
{
	char	*str;

	if (!(str = malloc(3)))
		return (0);
	str[0] = c;
	str[1] = 'x';
	str[2] = '\0';
	return (str);
}

char	*ft_str(char *str)
{
	if (str == NULL)
		return ("(null)");
	return (str);
}
