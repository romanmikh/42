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

int	ft_put_img_back(t_god *god)
{
	mlx_put_image_to_window(god->mlx, god->win, god->img->addr, 0, 0);
	return (0);
}

int	ft_minimize(t_god *god)
{
	mlx_hook(god->win, 15, 1L << 16, ft_put_img_back, god);
	return (0);
}

static void	ft_move(int key, t_god *god)
{
	t_cplx	delta;

	delta = init_cplx(ft_abs(god->max.r - god->min.r),
			ft_abs(god->max.i - god->min.i));
	if (key == K_RIGHT || key == K_D)
	{
		god->min.r -= delta.r * 0.05;
		god->max.r -= delta.r * 0.05;
	}
	if (key == K_LEFT || key == K_A)
	{
		god->min.r += delta.r * 0.05;
		god->max.r += delta.r * 0.05;
	}
	if (key == K_UP || key == K_W)
	{
		god->min.i -= delta.i * 0.05;
		god->max.i -= delta.i * 0.05;
	}
	if (key == K_DOWN || key == K_S)
	{
		god->min.i += delta.i * 0.05;
		god->max.i += delta.i * 0.05;
	}
	display(god);
}

int	ft_keypress(int keycode, t_god *god)
{
	if (keycode == K_ESC)
		free_memory(god);
	else if (keycode == K_UP || keycode == K_DOWN
		|| keycode == K_LEFT || keycode == K_RIGHT
		|| keycode == K_W ||  keycode == K_S
		|| keycode == K_A ||  keycode == K_D)
		ft_move(keycode, god);
	else if (keycode == K_M || keycode == K_N)
		zoom_keys(keycode, god);
	else
		ft_printf("Unkown input, keycode = %d\n", keycode);
	return (0);
}
