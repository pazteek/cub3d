/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:39:33 by gbabeau           #+#    #+#             */
/*   Updated: 2020/02/04 16:14:13 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <stdarg.h>

int					ft_str_flags(int i, const char *str);
int					ft_compare_c_to_s(char c, char *str);
char				*ft_ctoa(char c);
int					ft_conversion_printf(const char *c, va_list *f,
						char **variable);
char				*ft_flags_modif_final(char *flags, char **variable,
						int *stars, char str);
char				*ft_flags_int(char *flags, char **variable, int nbr,
						int *stars);
char				*ft_flags_string(char *flags, char **variable, int nbr);
char				*ft_flags_c(char *flags, char **variable, int nbr);
int					ft_printf(const char *str, ...);
char				*ft_flags_0(int nbr, char **variable, char str);
char				*ft_final(int size_f, char **variable, char str);
char				*ft_str(char *str);
char				*ft_flags_point(int nbr, char **variable);
void				ft_printf_insc_c(char *var, char **variable);
void				ft_printf_insc(char *var, char **variable, int f);
char				*ft_p(char **variable);
char				*ft_flags_tiret(int nbr, char **variable);
char				*ft_flags_tiret_c(int nbr, char **variable);
char				*ft_flags_point_0(int nbr, char **variable);
char				*ft_flags_0_c(int nbr, char **variable);
char				*ft_flags_0_point(int nbr, char **variable);
int					ft_j(char *flags, char comp, int *stars, int nbr);
void				ft_efface(char *l);
int					error(char **variable);
void				ft_efface_c(char *l);
char				*ft_flags(char *flags,
						char **variable, int nbr, int *stars);
int					ft_compare_s_to_s(char *str1, char *str2);
char				*ft_flags_tiret_0(char **variable);

#endif
