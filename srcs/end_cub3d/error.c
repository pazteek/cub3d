/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 16:00:39 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/21 16:57:27 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_error_2(int error, t_game game)
{
	if (10 == error)
		write(1, "Error\nnot existe files\n", 23);
	if (11 == error)
		write(1, "Error\nbad name files\n", 21);
	if (12 == error)
		write(1, "Error\nnot good nombers arguments\n", 34);
	if (13 == error)
		write(1, "Error\nduple textur\n", 25);
	if (15 == error)
		write(1, "Error\nno place\n", 16);
	if (16 == error)
		write(1, "Error\nmap invalid\n", 18);
	if (17 == error)
		write(1, "Error\nnot good nombers arguments to files\n", 43);
	if (18 == error)
		write(1, "Error\nnot good name arguments\n", 31);
	ft_end(0, &game);
}

int			ft_error(int error, t_game game)
{
	if (0 == error)
		write(1, "Error\nbad character in map\n", 27);
	if (1 == error)
		write(1, "Error\nbad nbrs player in map\n", 29);
	if (2 == error)
		write(1, "Error\nmap is not close\n", 23);
	if (3 == error)
		write(1, "Error\nnot existe textur\n", 24);
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
	if (10 <= error)
		ft_error_2(error, game);
	ft_end(0, &game);
	return (-500);
}
