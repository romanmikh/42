/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:48:14 by rmikhayl          #+#    #+#             */
/*   Updated: 2024/05/13 16:48:19 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_complex_arg(t_env *env, int ac, char **av)
{
	env->k.r = REAL;
	env->k.i = IMAGINARY;
	if (ac > 2 && ft_is_num(av[2]) == FALSE)
		return (0);
	if (ac > 2)
	{
		env->ite = ft_atol(av[2]);
		if (env->ite <= 0)
			env->ite = 1;
	}
	if (ac >= 5
		&& (ft_is_double(av[3]) == FALSE || ft_is_double(av[4]) == FALSE))
		return (0);
	if (ac >= 5)
	{
		env->k.r = ft_atof(av[3]);
		env->k.i = ft_atof(av[4]);
	}
	return (TRUE);
}

static int	ft_arg_fractal(t_env *env, char **av)
{
	env->type = 0;
	if (ft_strcmp(av[1], "J") == 0 || ft_strcmp(av[1], "Julia") == 0)
		env->type = T_JULIA;
	else if (ft_strcmp(av[1], "M") == 0 || ft_strcmp(av[1], "Mandelbrot") == 0)
		env->type = T_MANDEL;
	else if (ft_strcmp(av[1], "MA") == 0 || ft_strcmp(av[1], "MA_set") == 0)
		env->type = T_MA_SET;
	else if (ft_strcmp(av[1], "MB") == 0 || ft_strcmp(av[1], "Mandelbar") == 0)
		env->type = T_MB;
	else if (ft_strcmp(av[1], "BS") == 0
		|| ft_strcmp(av[1], "Burning_Ship") == 0)
		env->type = T_BS;
	else if (ft_strcmp(av[1], "JS") == 0 || ft_strcmp(av[1], "Julia_S") == 0)
		env->type = T_JS;
	else
		return (FALSE);
	return (TRUE);
}

int	ft_arg(t_env *env, int ac, char **av)
{
	if (ft_arg_fractal(env, av) == FALSE)
		return (0);
	ft_default(env);
	if (ft_complex_arg(env, ac, av) == FALSE)
		return (FALSE);
	return (TRUE);
}
