/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 12:48:19 by gbabeau           #+#    #+#             */
/*   Updated: 2020/01/21 14:27:01 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		verification(char *base)
{
	int	a;
	int	compt;

	a = 0;
	compt = 0;
	while (base[a] != '\0')
	{
		while (base[compt] != '\0')
		{
			if (base[compt] == base[a] && compt != a)
				return (0);
			compt++;
		}
		compt = 0;
		if ((base[a] < 32 || base[a] > 126
			|| base[a] == '-' || base[a] == '+') && base[a] != '\0')
			return (0);
		a++;
	}
	if (a > 1)
		return (a);
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	nb;
	long int	bs;

	bs = 0;
	bs = verification(base);
	nb = (long int)nbr;
	if (nbr < 0 && bs != 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	if (bs != 0)
	{
		if (nb / bs != 0)
			ft_putnbr_base(nb / bs, base);
		write(1, &base[nb % bs], 1);
	}
}
