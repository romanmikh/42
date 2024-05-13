/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:49:54 by rmikhayl          #+#    #+#             */
/*   Updated: 2024/05/13 16:49:57 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	ft_interpolate(double min, double max, double inter)
{
	return (min + ((max - min) * inter));
}

void	zoom_keys(int keypress, t_god *env)
{
	double	zoom;

	if (keypress == K_M)
		zoom = 0.70;
	else
		zoom = 1.30;
	env->min = init_cplx(env->min.r * zoom, env->min.i * zoom);
	env->max = init_cplx(env->max.r * zoom, env->max.i * zoom);
	ft_render(env);
}

int	zoom_mouse(int button, int x, int y, t_god *env)
{
	t_cplx	mouse;
	double		zoom;
	double		inter;

	if (button == M_SCROLL_UP || button == M_SCROLL_DOWN)
	{
		mouse.r = (double)x / (env->size_x / (env->max.r - env->min.r))
			+ env->min.r;
		mouse.i = (double)y / (env->size_y / (env->max.i - env->min.i))
			* -1 + env->max.i;
		if (button == M_SCROLL_UP)
			zoom = 0.70;
		else
			zoom = 1.30;
		inter = 1.0 / zoom;
		env->min.r = ft_interpolate(mouse.r, env->min.r, inter);
		env->min.i = ft_interpolate(mouse.i, env->min.i, inter);
		env->max.r = ft_interpolate(mouse.r, env->max.r, inter);
		env->max.i = ft_interpolate(mouse.i, env->max.i, inter);
		ft_render(env);
	}
	else
		ft_printf("Unkown mouse input, keycode = %d\n", button);
	return (0);
}
