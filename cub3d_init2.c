/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 16:00:39 by gbabeau           #+#    #+#             */
/*   Updated: 2020/09/30 12:30:36 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "time.h"

int			ft_error(int error)
{
	if (0 == error)
		write(1, "Error\nnot player in map\n", 24);
	if (1 == error)
		write(1, "Error\nmore player in map\n", 25);
	if (2 == error)
		write(1, "Error\nmap is not close\n", 23);
	if (3 == error)
		write(1, "Error\nfalse textur wall\n", 24);
	if (4 == error)
		write(1, "Error\nnot textur wall\n", 22);
	if (5 == error)
		write(1, "Error\n false resolution\n", 24);
	if (6 == error)
		write(1, "Error\n not resolution\n", 22);
	if (7 == error)
		write(1, "Error\nfalse color fold or ceiling\n", 34);
	if (8 == error)
		write(1, "Error\nnot textur wall\n", 22);
	if (9 == error)
		write(1, "Error\n file false order\n", 22);
	exit(EXIT_FAILURE);
	return (-500);
}
