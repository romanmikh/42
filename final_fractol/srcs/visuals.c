/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visuals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:49:05 by rmikhayl          #+#    #+#             */
/*   Updated: 2024/05/15 13:29:52 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_pixel_fix(t_img *img, int color, int i)
{
	img->buffer[i] = color >> 16 & 0xFF;
	img->buffer[i + 1] = color >> 8 & 0xFF;
	img->buffer[i + 2] = color & 0xFF;
	img->buffer[i + 3] = 0;
}

static void	ft_launch(t_god *env, int i)
{	
	if (env->type == T_JULIA)
		ft_pixel_fix(env->img, ft_julia(env), i);
	else if (env->type == T_MANDEL)
		ft_pixel_fix(env->img, ft_mandelbrot(env), i);
	else if (env->type == T_MB)
		ft_pixel_fix(env->img, ft_mandelbar(env), i);
	else if (env->type == T_BS)
		ft_pixel_fix(env->img, ft_burning_ship(env), i);
}

int	ft_process(t_god *env)
{
	int	x;
	int	y;
	int	i;

	mlx_string_put(env->mlx, env->win, 100, 100, 0xCCCCCC, "Processing");
	i = 0;
	y = 0;
	while (y < env->size_y)
	{
		env->c.i = env->max.i - y * env->factor.i;
		x = 0;
		while (x < env->size_x)
		{
			env->c.r = env->min.r + x * env->factor.r;
			ft_launch(env, i);
			i += 4;
			x++;
		}
		y++;
		ft_printf("\rLoading: [%d%%]", (y * 100) / env->size_y);
	}
	ft_printf("\t\033[1;32mOK\033[0m\n");
	return (TRUE);
}

int	display(t_god *env)
{
	env->factor = init_cplx(
			(env->max.r - env->min.r) / (env->size_x - 1),
			(env->max.i - env->min.i) / (env->size_y - 1));
	ft_process(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img->addr, 0, 0);
	return (TRUE);
}
