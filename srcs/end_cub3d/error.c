/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 16:00:39 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/22 13:40:13 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_error_3(int error, t_game game)
{
	if (20 == error)
		write(1, "Error\nwrong end of file\n", 31);
	if (21 == error)
		write(1, "Error\nduple ceiling arguments given\n", 43);
	if (22 == error)
		write(1, "Error\nduple ceiling arguments given\n", 43);
	if (23 == error)
		write(1, "Error\nduple ceiling arguments given\n", 43);
	if (24 == error)
		write(1, "Error\nduple ceiling arguments given\n", 43);
	if (25 == error)
		write(1, "Error\nduple ceiling arguments given\n", 43);
	if (26 == error)
		write(1, "Error\nduple ceiling arguments given\n", 43);
	if (27 == error)
		write(1, "Error\nduple ceiling arguments given\n", 43);
	ft_end(0, &game);
}

void		ft_error_2(int error, t_game game)
{
	if (10 == error)
		write(1, "Error\nfile not found\n", 21);
	if (11 == error)
		write(1, "Error\nbad name of file extention\n", 33);
	if (12 == error)
		write(1, "Error\nwrong arguments nombers in comand line\n", 45);
	if (13 == error)
		write(1, "Error\nduple textur arguments given\n", 35);
	if (15 == error)
		write(1, "Error\nnot enough memory available\n", 34);
	if (16 == error)
		write(1, "Error\ninvalid map\n", 18);
	if (17 == error)
		write(1, "Error\nwrong arguments nombers in file\n", 38);
	if (18 == error)
		write(1, "Error\nwrong arguments name in comand line\n", 42);
	if (20 < error)
		ft_error_3(error, game);
	ft_end(0, &game);
}

int			ft_error(int error, t_game game)
{
	if (0 == error)
		write(1, "Error\nbad character in map\n", 27);
	if (1 == error)
		write(1, "Error\nbad nombers player in map\n", 32);
	if (2 == error)
		write(1, "Error\nmap not closed\n", 21);
	if (3 == error)
		write(1, "Error\ntextur not found\n", 23);
	if (4 == error)
		write(1, "Error\nwall textur messing\n", 26);
	if (5 == error)
		write(1, "Error\nwrong resolution\n", 23);
	if (6 == error)
		write(1, "Error\nresolution value messing\n", 32);
	if (7 == error)
		write(1, "Error\nwrong value of floor or ceiling\n", 39);
	if (8 == error)
		write(1, "Error\nnot textur wall\n", 22);
	if (9 == error)
		write(1, "Error\n file false order\n", 24);
	if (10 <= error)
		ft_error_2(error, game);
	ft_end(0, &game);
	return (-500);
}
