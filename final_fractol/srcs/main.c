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

int	free_memory(t_god *env)
{
	mlx_destroy_image(env->mlx, env->img->addr);
	mlx_destroy_window(env->mlx, env->win);
	mlx_destroy_display(env->mlx);
	free(env->img);
	free(env->mlx);
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

void	init_god(t_god *env)
{
	env->img = malloc(sizeof(t_img));
	if (!env->img)
		exit(1);
	env->mlx = mlx_init();
	env->img->addr = mlx_new_image(env->mlx, env->size_x, env->size_y);
	env->img->buffer = mlx_get_data_addr(env->img->addr, &env->img->bpp,
			&env->img->line_size, &env->img->endian);
	env->win = mlx_new_window(env->mlx, env->size_x, env->size_y, "fract-ol");
	mlx_hook(env->win, 2, 1L << 0, ft_keypress, env);
	mlx_hook(env->win, 4, 1L << 2, zoom_mouse, env);
	mlx_hook(env->win, 15, 1L << 16, ft_minimize, env);
	mlx_hook(env->win, 33, 1L << 5, free_memory, env);
}

void	ft_default(t_god *env)
{
	env->size_x = SIZE_X;
	env->size_y = SIZE_Y;
	env->ite = MAX_ITERATION;
	env->min = init_cplx(MIN_R, MIN_I);
	env->max = init_cplx(MAX_R,
			MIN_I + (MAX_R - MIN_R) * env->size_x / env->size_y);
	env->k = init_cplx(-0.4, 0.6);
}

int	main(int ac, char **av)
{
	t_god		env;

	if (ac == 1)
		return (0);
	if (handle_args(&env, ac, av) == FALSE)
		return (2);
	init_god(&env);
	display(&env);
	mlx_loop(env.mlx);
	return (0);
}
