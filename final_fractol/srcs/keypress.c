/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:49:20 by rmikhayl          #+#    #+#             */
/*   Updated: 2024/05/13 16:49:22 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_put_img_back(t_god *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->img->addr, 0, 0);
	return (0);
}

int	ft_minimize(t_god *env)
{
	mlx_hook(env->win, 15, 1L << 16, ft_put_img_back, env);
	return (0);
}

static void	ft_move(int key, t_god *env)
{
	t_cplx	delta;

	delta = init_cplx(ft_abs(env->max.r - env->min.r),
			ft_abs(env->max.i - env->min.i));
	if (key == K_RIGHT || key == K_D)
	{
		env->min.r -= delta.r * 0.05;
		env->max.r -= delta.r * 0.05;
	}
	if (key == K_LEFT || key == K_A)
	{
		env->min.r += delta.r * 0.05;
		env->max.r += delta.r * 0.05;
	}
	if (key == K_UP || key == K_W)
	{
		env->min.i -= delta.i * 0.05;
		env->max.i -= delta.i * 0.05;
	}
	if (key == K_DOWN || key == K_S)
	{
		env->min.i += delta.i * 0.05;
		env->max.i += delta.i * 0.05;
	}
	ft_render(env);
}

int	ft_keypress(int keycode, t_god *env)
{
	if (keycode == K_ESC)
		free_memory(env);
	else if (keycode == K_UP || keycode == K_DOWN
		|| keycode == K_LEFT || keycode == K_RIGHT
		|| keycode == K_W ||  keycode == K_S
		|| keycode == K_A ||  keycode == K_D)
		ft_move(keycode, env);
	else if (keycode == K_M || keycode == K_N)
		zoom_keys(keycode, env);
	else
		ft_printf("Unkown input, keycode = %d\n", keycode);
	return (0);
}
