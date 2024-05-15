/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:49:32 by rmikhayl          #+#    #+#             */
/*   Updated: 2024/05/13 16:49:40 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	free_memory(t_god *god)
{
	mlx_destroy_image(god->mlx, god->img->addr);
	mlx_destroy_window(god->mlx, god->win);
	mlx_destroy_display(god->mlx);
	free(god->img);
	free(god->mlx);
	exit (0);
	return (1);
}

t_cplx	init_cplx(double real, double imaginary)
{
	t_cplx	c;

	c.r = real;
	c.i = imaginary;
	return (c);
}

void	init_god(t_god *god)
{
	god->img = malloc(sizeof(t_img));
	if (!god->img)
		exit(1);
	god->mlx = mlx_init();
	god->img->addr = mlx_new_image(god->mlx, god->size_x, god->size_y);
	god->img->buffer = mlx_get_data_addr(god->img->addr, &god->img->bpp,
			&god->img->line_size, &god->img->endian);
	god->win = mlx_new_window(god->mlx, god->size_x, god->size_y, "fract-ol");
	mlx_hook(god->win, 2, 1L << 0, ft_keypress, god);
	mlx_hook(god->win, 4, 1L << 2, zoom_mouse, god);
	mlx_hook(god->win, 33, 1L << 5, free_memory, god);
}

void	ft_default(t_god *god)
{
	god->size_x = SIZE_X;
	god->size_y = SIZE_Y;
	god->ite = MAX_ITERATION;
	god->min = init_cplx(MIN_R, MIN_I);
	god->max = init_cplx(MAX_R,
			MIN_I + (MAX_R - MIN_R) * god->size_x / god->size_y);
	god->k = init_cplx(-0.4, 0.6);
}

int	main(int ac, char **av)
{
	t_god		god;

	if (ac == 1)
		return (0);
	if (handle_args(&god, ac, av) == FALSE)
		return (2);
	init_god(&god);
	display(&god);
	mlx_loop(god.mlx);
	return (0);
}
