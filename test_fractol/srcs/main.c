/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:48:21 by adelille          #+#    #+#             */
/*   Updated: 2021/10/26 21:46:31 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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
		return (ft_no_param());
	if (ft_arg(&env, ac, av) == FALSE)
		return (2);
	ft_init_env(&env);
	ft_render(&env);
	mlx_loop(env.mlx);
	return (0);
}
