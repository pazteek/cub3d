/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complement.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 12:58:00 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/21 13:13:41 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_putnbr_fd(int nb, int fd)
{
	long	nbr;

	nbr = nb;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nbr *= -1;
	}
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	nbr = nbr % 10 + 48;
	write(fd, &nbr, 1);
}

int		ft_strlen_cub(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	init_var(int *a, float n_t[5], float *rot)
{
	*a = 0;
	if (*rot >= 2 * M_PI)
		*rot -= 2 * M_PI;
	n_t[2] = fabsf(tanf(*rot));
	if (*rot > 0 && *rot < (M_PI / 2))
	{
		n_t[1] = -1;
		n_t[0] = -1;
	}
	else if (*rot > 0 && *rot < M_PI)
	{
		n_t[1] = -1;
		n_t[0] = 1;
	}
	else if (*rot > 0 && *rot < (3 * M_PI / 2))
	{
		n_t[1] = 1;
		n_t[0] = 1;
	}
	else
	{
		n_t[1] = 1;
		n_t[0] = -1;
	}
}

float	dist(float n, float d)
{
	if ((int)(n) == 1)
	{
		if (0 != (ceilf(d) - d))
			return (ceilf(d) - d);
		return (1);
	}
	if (0 != (d - truncf(d)))
	{
		return (d - truncf(d));
	}
	return (1);
}
