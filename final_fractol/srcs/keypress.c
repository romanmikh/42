/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:01:29 by adelille          #+#    #+#             */
/*   Updated: 2021/10/22 16:14:18 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_put_img_back(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->img->addr, 0, 0);
	return (0);
}

int	ft_minimize(t_env *env)
{
	mlx_hook(env->win, 15, 1L << 16, ft_put_img_back, env);
	return (0);
}

static void	ft_move(int key, t_env *env)
{
	t_complex	delta;

	delta = ft_init_complex(ft_abs(env->max.r - env->min.r),
			ft_abs(env->max.i - env->min.i));
	if (key == K_RIGHT || key == K_D)
	{
		env->min.r -= delta.r * 0.05;
		env->max.r -= delta.r * 0.05;
	}
	if (key == K_LEFT || key == K_A || key == K_Q)
	{
		env->min.r += delta.r * 0.05;
		env->max.r += delta.r * 0.05;
	}
	if (key == K_UP || key == K_W || key == K_Z)
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

int	ft_keypress(int keycode, t_env *env)
{
	if (keycode == K_ESC)
		ft_free_exit(env);
	else if (keycode == K_UP || keycode == K_DOWN
		|| keycode == K_LEFT || keycode == K_RIGHT
		|| keycode == K_W || keycode == K_Z || keycode == K_S
		|| keycode == K_A || keycode == K_Q || keycode == K_D)
		ft_move(keycode, env);
	else if (keycode == K_M || keycode == K_N)
		ft_zoom_mn(keycode, env);
	else
		printf("Unkown input, keycode = %d\n", keycode);
	return (0);
}
