/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:19:02 by adelille          #+#    #+#             */
/*   Updated: 2021/10/22 16:14:44 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_pixel(t_img *img, int color, int index)
{
	img->buffer[index] = color & 0xFF;
	img->buffer[index + 1] = color >> 8 & 0xFF;
	img->buffer[index + 2] = color >> 16 & 0xFF;
	img->buffer[index + 3] = 0;
}

void	ft_pixel_fix(t_img *img, int color, int index)
{
	img->buffer[index] = color >> 16 & 0xFF;
	img->buffer[index + 1] = color >> 8 & 0xFF;
	img->buffer[index + 2] = color & 0xFF;
	img->buffer[index + 3] = 0;
}

static void	ft_launch(t_env *env, int index)
{	
	if (env->type == T_JULIA)
		ft_pixel_fix(env->img, ft_julia(env), index);
	else if (env->type == T_MANDEL)
		ft_pixel_fix(env->img, ft_mandelbrot(env), index);
	else if (env->type == T_MA_SET)
		ft_pixel_fix(env->img, ft_ma_set(env), index);
	else if (env->type == T_MB)
		ft_pixel_fix(env->img, ft_mandelbar(env), index);
	else if (env->type == T_BS)
		ft_pixel_fix(env->img, ft_burning_ship(env), index);
	else if (env->type == T_JS)
		ft_pixel_fix(env->img, ft_julia_s(env), index);
}

int	ft_process(t_env *env)
{
	int	x;
	int	y;
	int	index;

	mlx_string_put(env->mlx, env->win, 100, 100, 0xCCCCCC, "Rendering");
	index = 0;
	y = 0;
	while (y < env->size_y)
	{
		env->c.i = env->max.i - y * env->factor.i;
		x = 0;
		while (x < env->size_x)
		{
			env->c.r = env->min.r + x * env->factor.r;
			ft_launch(env, index);
			index += 4;
			x++;
		}
		y++;
		printf("\rRender: [%d%%]", (y * 100) / env->size_y);
	}
	printf("\t\033[1;32mDone\033[0m\n");
	return (TRUE);
}

int	ft_render(t_env *env)
{
	env->factor = ft_init_complex(
			(env->max.r - env->min.r) / (env->size_x - 1),
			(env->max.i - env->min.i) / (env->size_y - 1));
	ft_process(env);
	ft_display(env);
	return (TRUE);
}
