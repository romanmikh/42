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

void	ft_default(t_env *env)
{
	env->size_x = SIZE_X;
	env->size_y = SIZE_Y;
	env->ite = MAX_ITERATION;
	env->min = ft_init_complex(MIN_R, MIN_I);
	env->max = ft_init_complex(MAX_R,
			MIN_I + (MAX_R - MIN_R) * env->size_x / env->size_y);
	env->k = ft_init_complex(-0.4, 0.6);
}

int	main(int ac, char **av)
{
	t_env		env;

	if (ac == 1)
		return (0);
	if (ft_arg(&env, ac, av) == FALSE)
		return (2);
	ft_init_env(&env);
	ft_render(&env);
	mlx_loop(env.mlx);
	return (0);
}
