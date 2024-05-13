/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:08:38 by rmikhayl          #+#    #+#             */
/*   Updated: 2024/05/13 19:08:42 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"

# if defined(__linux__) || defined(__unix__)
#  include "keypress_linux.h"
# else
#  error "Only Unix OS supported."
# endif

# define T_JULIA	1
# define T_MANDEL	2
# define T_MB		3
# define T_BS		4

# define SIZE_X			1000
# define SIZE_Y			1000
# define MAX_ITERATION		250
# define REAL			-0.7
# define IMAGINARY		0.27015
# define MIN_R			-2.0
# define MIN_I			-2.0
# define MAX_R			2.0
# define MAX_I			2.0

typedef struct s_complex
{
	double		r;
	double		i;
}				t_complex;

typedef struct s_img
{
	void		*addr;
	char		*buffer;
	int			bpp;
	int			line_size;
	int			endian;
}				t_img;

typedef struct s_env
{
	void		*mlx;
	void		*win;
	int			size_x;
	int			size_y;
	int			type;
	long		ite;
	t_complex	min;
	t_complex	max;
	t_complex	factor;
	t_complex	c;
	t_complex	k;
	t_img		*img;
}				t_env;

typedef struct s_color
{
	double		r;
	double		g;
	double		b;
	int			shadow;
}				t_color;

int			ft_arg(t_env *env, int ac, char **av);
void		ft_default(t_env *env);
int			ft_has_help(int ac, char **av);
int			ft_no_param(void);
int			ft_option(void);

int			ft_render(t_env *env);
int			ft_display(t_env *env);

int			ft_put_img_back(t_env *env);
int			ft_minimize(t_env *env);
int			ft_keypress(int keycode, t_env *env);
int			ft_zoom(int keypress, int x, int y, t_env *env);
void		ft_zoom_mn(int keypress, t_env *env);

int			ft_julia(t_env *env);
int			ft_mandelbrot(t_env *env);
int			ft_mandelbar(t_env *env);
int			ft_burning_ship(t_env *env);

int			ft_ints_to_int(int r, int g, int b);
int			ft_adjust_int(int color);
int			ft_red_to_black(int color);

int			free_memory(t_env *env);
int			ft_is_double(const char *n);
int			ft_is_num(const char *n);
t_complex	ft_init_complex(double real, double imaginary);
void		ft_init_env(t_env *env);

#endif
