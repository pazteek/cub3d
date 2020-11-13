/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:39:33 by gbabeau           #+#    #+#             */
/*   Updated: 2020/10/21 18:12:19 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <string.h>
# include <math.h>
# include <stdarg.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mlx.h>
# include "mlx_int.h"
# include "libft.h"

# define FOV 1
# define FOV_W 0.78539816339
# define STEP 0.04
# define LEFT_ROT 65361
# define RIGHT_ROT 65363
# define KEY_A 113
# define KEY_S 115
# define KEY_D 100
# define KEY_W 122
# define KEY_ESC 65307

typedef struct	s_bmp
{
	int			size;
	int			width;
	int			height;
	int			reserve;
	int			offset;
	int			headers;
	int			color;
	int			bit_pixel;
	int			compresion;
	int			size_a;
	int			x;
	int			y;
	int			colors;
	int			color_i;
}				t_bmp;

typedef struct	s_player
{
	double		pos_x;
	double		pos_y;
	double		rot;
}				t_player;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*data;
	int			c_f[2];
	int			bpp;
	int			sizeline;
	int			endian;
}				t_mlx;
typedef struct	s_textur
{
	char		*name;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
	int			h;
	int			w;
	void		*img_ptr;
}				t_textur;

typedef struct	s_deb
{
	int			resolution[2];
	float		fov_h;
	int			color_fc[2];
	char		**map;
	t_mlx		*mlx;
	int			sens;
	t_textur	*textur[5];
	float		**objet;
	float		*dist;
	int			wall;
	char		mov[6];
}				t_deb;

typedef struct	s_game
{
	t_player	*player;
	t_deb		*deb;
}				t_game;

int				ft_focus(t_game *game);
int				ft_error(int a, t_game game);
int				ft_compare_c_to_s(char c, char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_compare_c_to_s(char c, char *str);
int				ft_compare_s_to_s(char *str1, char *str2);
void			ft_move_front(t_game *game);
void			ft_rot_right(t_player *player);
void			ft_rot_left(t_player *player);
void			ft_move_back(t_game *game);
void			ft_move_right(t_game *game);
void			ft_move_left(t_game *game);
char			**tri(char *c);
int				ft_real(t_deb *deb, char *tab, t_game game);
int				ft_color_fc(t_deb *deb, char *tab, int fc, t_game game);
int				ft_textur_wall(t_deb *deb, char *tab, int dirc, t_game game);
int				ft_textur_objet(t_deb *deb, char *tab, t_game game);
int				ft_move(t_game *game);
int				rayon_y(float yx[2], float delt[2], float n_t[2], char **map);
int				rayon_x(float yx[2], float delt[2], float n_t[2], char **map);
void			int_strat(t_deb *deb, t_player *player);
int				int_strat2(float yx[2], float rot, char **map);
float			dist(float n, float d);
void			mlx_pixel_put_image(t_mlx *mlx, int x, int y, int cf);
void			color_fc(t_deb *deb, int i, int v);
void			affiche_mur(int i, float r, t_deb *deb, float *yx);
void			affiche_objet(int i, float r, t_deb *deb, float dist_2);
int				ft_size_map(char *tab);
int				ft_end(int suc, t_game *game);
void			ft_copy_map(char *tab, char *map);
char			**ft_malloc_struc_map(char **tab);
void			ft_transition(char **tab, t_deb *deb);
int				ft_map_check_2(t_game game, int y, int x);
t_deb			ft_map_check(t_deb *deb, t_game game);
int				player_init(t_player *player, int y, int x, char pos);
void			ft_deb(char **tab, t_game *game);
int				init_deb_mlx(t_mlx *mlx, int resolution[2], t_deb *deb);
void			ft_putnbr_fd(int nb, int fd);
void			init_var(int *a, float n_t[3], float *rot);
int				ft_printf(const char *str, ...);
int				ft_map(t_deb *deb, char **tab, t_game game);
int				ft_strlen_cub(char *str);
int				ft_bmp(char *data, int resolution[2], t_game game);
void			ft_put_m(int a, int b);
int				colition_y(t_player *player, float dic, char **map);
int				colition_x(t_player *player, float dic, char **map);
void			ft_pas_wall(float *z, int m[2], int *v, t_deb *deb);
void			display_fc(float z, t_deb *deb, int m[2], int v);
void			init_game(t_game *game, char **tab);
void			ft_move_2(void (*f)(t_player*, char**), t_game *game);
void			ft_move_3(void (*f)(t_player*), t_game *game);
void			init_affiche_objet(t_deb *deb, t_player *player, float rot);
int				ft_move_p(int key, t_game *game);
int				ft_move_r(int key, t_game *game);
int				orde_sprite(t_deb *deb, t_player *player);
void			display_wall(int i, float rot, t_deb *deb, t_player *player);
int				display_wall_init(float *dist, int i, t_player *play, t_deb *d);
int				orde_sprite(t_deb *deb, t_player *player);
float			display_2(t_deb *deb, t_player *player, int i);
void			init_affiche_objet(t_deb *deb, t_player *player, float rot);
void			ft_free_tab(void **tab);
void			ft_check_bmp(char *argc, t_game game);
#endif
