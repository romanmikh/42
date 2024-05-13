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

int	ft_julia(t_god *env)
{
	t_cplx	z;
	int			i;

	z.r = env->c.r;
	z.i = env->c.i;
	i = 0;
	while (z.r * z.r + z.i * z.i < 4 && i < env->ite)
	{
		z = init_cplx(z.r * z.r - z.i * z.i + env->k.r,
				2 * z.r * z.i + env->k.i);
		i++;
	}
	return (ft_red_to_black(colour_bitwise_encode(
				255 - 255 * ((env->ite - i) * (env->ite - i))
				% (env->ite * env->ite), 0, 0)));
}
