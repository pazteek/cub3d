/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:39:33 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/08 16:07:12 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <string.h>
# include <math.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mlx.h>
# include "libft.h"

typedef struct		s_bmp
{
	int				size;
	int				width;
	int				height;
	int				Reserve;
	int				offset;
	int				headers;
	int				color;
	int				bit_pixel;
	int				compresion;
	int				size_a;
	int				x;
	int				y;
	int				colors;
	int				color_i;
}					t_bmp;



typedef struct		s_player
{
	double			pos_x;
	double			pos_y;
	double			rot;
}					t_player;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*data;
	int				c_f[2];
	int					bpp;
	int				sizeline;
	int				endian;
}					t_mlx;
typedef struct		s_textur
{
	char			*name;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian;
	int				h;
	int				w;
	void			*img_ptr;
}					t_textur;



typedef struct		s_deb
{
	int				resolution[2];
	int				color_FC[2];
	char			**map;
	t_mlx			*mlx;
	int				sens;
	t_textur		*textur[5];
	float			**objet;
	float			*dist;
}					t_deb;

typedef struct		s_game
{
	t_player		*player;
	t_deb			*deb;
}					t_game;


int     ft_error(int error);
int	ft_compare_c_to_s(char c, char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_atoi(const char *str);
int	ft_compare_c_to_s(char c, char *str);
int	ft_compare_s_to_s(char *str1, char *str2);
void 	ft_move_front(t_player *player,char **map);
void	ft_rot_right(t_player *player);
void	ft_rot_left(t_player *player);
void	ft_move_back(t_player *player, char **map);
void	ft_move_right(t_player *player, char **map);
void	ft_move_left(t_player *player, char **map);
char	**tri(char *c);
int		ft_real(t_deb *deb, char *tab);
int		ft_color_fc(t_deb *deb, char *tab, int fc);
int		ft_textur_wall(t_deb *deb, char *tab, int dirc);
int		ft_textur_objet(t_deb *deb, char *tab);
int		ft_move(int key, t_game *game);
int		rayon_y(float yx[2], float delt[2], float n_t[2], char **map);
int		rayon_x(float yx[2], float delt[2], float n_t[2], char **map);
void	int_strat(t_deb *deb, t_player *player);
int		int_strat2(float yx[2],float rot, char **map);
float	dist(float n, float d);
void	mlx_pixel_put_image(t_mlx *mlx, int x, int  y, int cf);
void	color_fc(t_deb *deb, int i, int v);
void	affiche_mur(int i, float r, t_deb *deb, float *yx);
void	affiche_objet(int i, float r, t_deb *deb, float dist_2);
int		ft_size_map(char *tab);
int		ft_end(t_game *game);
void	ft_copy_map(char *tab, char *map);
char	**ft_malloc_struc_map(char **tab);
void	ft_transition(char **tab, t_deb *deb);
int		ft_map_check_2(t_deb *deb, int y, int x, t_player *player);
t_deb	ft_map_check(t_deb *deb, t_player *player);
int		player_init(t_player *player,int y, int x,char pos);
void	ft_deb(char **tab, t_deb *deb, t_player *player);
void	init_deb_mlx(t_mlx *mlx,int resolution[2]);
void	ft_putnbr_fd(int nb, int fd);
void	init_var(int *a, float n_t[3], float *rot);
int		ft_printf(const char *str,...);
int		ft_map(t_deb *deb, char **tab, t_player *player);
int		ft_strlen_cub(char *str);
int		ft_error(int a);
int	ft_bmp(char *data, int resolution[2]);
void	ft_put_m(int a, int b);
int	colition_y(t_player *player, float dic, char **map);
int	colition_x(t_player *player, float dic, char **map);
void	ft_pas_wall(float *z, int m[2], int *v, t_deb *deb);
void	display_fc(float z, t_deb *deb, int m[2], int v);
void		init_game(t_game *game, char **tab);

#endif
