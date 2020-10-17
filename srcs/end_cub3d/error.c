/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 16:00:39 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/17 17:26:11 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "time.h"

void		ft_error_2(int error, t_game game)
{
	if (10 == error)
		write(1, "Error\nnot existe files\n", 23);
	if (11 == error)
		write(1, "Error\nbad name files\n", 21);
	if (12 == error)
		write(1, "Error\nnot good nombers arguments\n", 34);
	if (13 == error)
		write(1, "Error\nduple textur wall\n", 24);
	if (14 == error)
		write(1, "Error\nduple textur sprite\n", 26);
	if (15 == error)
		write(1, "Error\n false resolution\n", 24);
	if (16 == error)
		write(1, "Error\n not resolution\n", 22);
	if (17 == error)
		write(1, "Error\nfalse color fold or ceiling\n", 34);
	if (18 == error)
		write(1, "Error\nnot textur wall\n", 22);
	if (19 == error)
		write(1, "Error\n file false identifiant\n", 30);
	ft_end(&game);
	exit(EXIT_FAILURE);
}

int			ft_error(int error, t_game game)
{
	if (0 == error)
		write(1, "Error\nnot player in map\n", 24);
	if (1 == error)
		write(1, "Error\nmore player in map\n", 25);
	if (2 == error)
		write(1, "Error\nmap is not close\n", 23);
	if (3 == error)
		write(1, "Error\nduple textur wall\n", 25);
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
	if(10 <= error)
		ft_error_2(error, game);
	ft_end(&game);
	exit(EXIT_FAILURE);
	return (-500);
}
