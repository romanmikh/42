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

# if defined(__linux__)
#  include "key_map.h"
# else
#  error "Only Unix OS supported."
# endif

# define T_JULIA	1
# define T_MANDEL	2
# define T_MB		3
# define T_BS		4

# define SIZE_X			1000
# define SIZE_Y			1000
# define MAX_ITERATION		255
# define REAL			-0.7
# define IMAGINARY		0.27015
# define MIN_R			-2.0
# define MIN_I			-2.0
# define MAX_R			2.0
# define MAX_I			2.0

typedef struct s_cplx
{
	double		r;
	double		i;
}				t_cplx;

typedef struct s_img
{
	void		*addr;
	char		*buffer;
	int			bpp;
	int			line_size;
	int			endian;
}				t_img;

typedef struct s_god
{
	void		*mlx;
	void		*win;
	int			size_x;
	int			size_y;
	int			type;
	long		ite;
	t_cplx		min;
	t_cplx		max;
	t_cplx		factor;
	t_cplx		c;
	t_cplx		julia_c;
	t_img		*img;
}				t_god;

typedef struct s_color
{
	double		r;
	double		g;
	double		b;
}				t_color;

t_cplx	init_cplx(double real, double imaginary);

void	zoom_keys(int keypress, t_god *god);
void	init_defaults(t_god *god);
void	init_god(t_god *god);

int		display(t_god *god);
int		ft_julia(t_god *god);
int		free_memory(t_god *god);
int		ft_mandelbar(t_god *god);
int		ft_mandelbrot(t_god *god);
int		ft_burning_ship(t_god *god);
int		discont_to_black(int color);
int		key_press(int keycode, t_god *god);
int		handle_args(t_god *god, int ac, char **av);
int		julia_args(t_god *god, int ac, char **av);
int		zoom_mouse(int keypress, int x, int y, t_god *god);

#endif
