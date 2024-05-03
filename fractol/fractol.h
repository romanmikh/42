/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:45:19 by rmikhayl          #+#    #+#             */
/*   Updated: 2024/05/03 11:45:21 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx/mlx.h"

# if defined(__linux__) || defined(__unix__)
# else
#  error "Only Linux & Unix OS supported."
# endif

# define SIZE_X 1000
# define SIZE_Y 1000
# define MAX_ITERATION	250
# define REAL			-0.7
# define IMAGINARY		0.27015
# define MIN_R			-2.0
# define MIN_I			-2.0
# define MAX_R			2.0
# define MAX_I			2.0

# define K_ESC			65307
# define K_LEFT			65361
# define K_UP			65362
# define K_RIGHT		65363
# define K_DOWN			65364
# define K_W			119
# define K_A			97
# define K_S			115
# define K_D			100
# define K_Z			122
# define K_Q			113
# define K_M			109
# define K_N			110

# define M_SCROLL_UP	5
# define M_SCROLL_DOWN	4

typedef struct s_cplx
{
  double  r;
  double  i;
} t_cplx

typedef struct s_img
{
  void *addr;
  char *buffer;
  int bpp;
  int line_size;
  int endian;
} t_img;

typedef struct s_env
{
  void *mlx;
  void *win;
  int size_x;
  int size_y;
  int type;
  int ite;
  t_cplx min;
  t_cplx max;
  t_cplx factor;
  t_cplx c;
  t_cplx k;
  t_img *img;
} t_env;

typedef struct s_colour
{
  double  r;
  double  g;
  double  b;
  int     shadow;
} t_colour;

int ft_mandelbrot(t_env *env);

#endif
