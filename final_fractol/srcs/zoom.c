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

void	zoom_keys(int keypress, t_god *god)
{
	double	zoom;

	if (keypress == K_M)
		zoom = 0.70;
	else
		zoom = 1.30;
	god->min = init_cplx(god->min.r * zoom, god->min.i * zoom);
	god->max = init_cplx(god->max.r * zoom, god->max.i * zoom);
	display(god);
}

int	zoom_mouse(int button, int x, int y, t_god *god)
{
	t_cplx	mouse;
	double		zoom;
	double		inter;

	if (button == M_SCROLL_UP || button == M_SCROLL_DOWN)
	{
		mouse.r = (double)x / (god->size_x / (god->max.r - god->min.r))
			+ god->min.r;
		mouse.i = (double)y / (god->size_y / (god->max.i - god->min.i))
			* -1 + god->max.i;
		if (button == M_SCROLL_UP)
			zoom = 0.70;
		else
			zoom = 1.30;
		inter = 1.0 / zoom;
		god->min.r = ft_interpolate(mouse.r, god->min.r, inter);
		god->min.i = ft_interpolate(mouse.i, god->min.i, inter);
		god->max.r = ft_interpolate(mouse.r, god->max.r, inter);
		god->max.i = ft_interpolate(mouse.i, god->max.i, inter);
		display(god);
	}
	else
		ft_printf("Unkown mouse input, keycode = %d\n", button);
	return (0);
}
