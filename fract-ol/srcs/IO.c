/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IO.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:49:20 by rmikhayl          #+#    #+#             */
/*   Updated: 2024/05/13 16:49:22 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	interp_extrap(double min, double max, double inter)
{
	return (min + ((max - min) * inter));
}

int	zoom_mouse(int button, int x, int y, t_god *god)
{
	t_cplx		mouse;
	double		zoom;
	double		inter;

	if (button == M_SCROLL_UP || button == M_SCROLL_DOWN)
	{
		mouse.r = (double)x / (god->size_x / (god->max.r - god->min.r))
			+ god->min.r;
		mouse.i = (double)y / (god->size_y / (god->max.i - god->min.i))
			* -1 + god->max.i;
		if (button == M_SCROLL_UP)
			zoom = 0.75;
		else
			zoom = 1.25;
		inter = 1.0 / zoom;
		god->min.r = interp_extrap(mouse.r, god->min.r, inter);
		god->min.i = interp_extrap(mouse.i, god->min.i, inter);
		god->max.r = interp_extrap(mouse.r, god->max.r, inter);
		god->max.i = interp_extrap(mouse.i, god->max.i, inter);
		display(god);
	}
	else
		ft_printf("Erroneous mouse input: %d\n", button);
	return (0);
}

void	zoom_keys(int keypress, t_god *god)
{
	double	zoom;

	if (keypress == K_M)
		zoom = 0.75;
	else
		zoom = 1.25;
	god->min = init_cplx(god->min.r * zoom, god->min.i * zoom);
	god->max = init_cplx(god->max.r * zoom, god->max.i * zoom);
	display(god);
}

static void	key_move(int key, t_god *god)
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

int	key_press(int keycode, t_god *god)
{
	if (keycode == K_ESC)
		free_memory(god);
	else if (keycode == K_UP || keycode == K_DOWN
		|| keycode == K_LEFT || keycode == K_RIGHT
		|| keycode == K_W || keycode == K_S
		|| keycode == K_A || keycode == K_D)
		key_move(keycode, god);
	else if (keycode == K_M || keycode == K_N)
		zoom_keys(keycode, god);
	else
		ft_printf("Erroneous keyboard input: %d\n", keycode);
	return (0);
}
