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

void	set_pixel(t_img *img, int color, int i)
{
	img->buffer[i] = color >> 16 & 0xFF;
	img->buffer[i + 1] = color >> 8 & 0xFF;
	img->buffer[i + 2] = color & 0xFF;
	img->buffer[i + 3] = 0;
}

static void	choose_fractal(t_god *god, int i)
{
	if (god->type == T_JULIA)
		set_pixel(god->img, ft_julia(god), i);
	else if (god->type == T_MANDEL)
		set_pixel(god->img, ft_mandelbrot(god), i);
	else if (god->type == T_MB)
		set_pixel(god->img, ft_mandelbar(god), i);
	else if (god->type == T_BS)
		set_pixel(god->img, ft_burning_ship(god), i);
}

int	calculate(t_god *god)
{
	int	x;
	int	y;
	int	i;

	mlx_string_put(god->mlx, god->win, 100, 100, 0xCCCCCC, "Processing");
	i = 0;
	y = 0;
	while (y < god->size_y)
	{
		god->c.i = god->max.i - y * god->factor.i;
		x = 0;
		while (x < god->size_x)
		{
			god->c.r = god->min.r + x * god->factor.r;
			choose_fractal(god, i);
			i += 4;
			x++;
		}
		y++;
		ft_printf("\rLoading: [%d%%]", (y * 100) / god->size_y);
	}
	ft_printf("\t\033[1;32mOK\033[0m\n");
	return (TRUE);
}

int	display(t_god *god)
{
	god->factor = init_cplx(
			(god->max.r - god->min.r) / (god->size_x),
			(god->max.i - god->min.i) / (god->size_y));
	calculate(god);
	mlx_put_image_to_window(god->mlx, god->win, god->img->addr, 0, 0);
	return (TRUE);
}
