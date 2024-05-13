/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:37:46 by adelille          #+#    #+#             */
/*   Updated: 2021/10/26 15:42:01 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_julia(t_env *env)
{
	t_complex	z;
	int			i;

	z.r = env->c.r;
	z.i = env->c.i;
	i = 0;
	while (z.r * z.r + z.i * z.i < 4 && i < env->ite)
	{
		z = ft_init_complex(z.r * z.r - z.i * z.i + env->k.r,
				2 * z.r * z.i + env->k.i);
		i++;
	}
	return (ft_red_to_black(ft_ints_to_int(
				255 - 255 * ((env->ite - i) * (env->ite - i))
				% (env->ite * env->ite), 0, 0)));
}
