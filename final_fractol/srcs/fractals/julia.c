/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:58:20 by rmikhayl          #+#    #+#             */
/*   Updated: 2024/05/15 13:58:22 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_julia(t_god *god)
{
	t_cplx		z;
	int			i;

	z.r = god->c.r;
	z.i = god->c.i;
	i = 0;
	while (z.r * z.r + z.i * z.i < 4 && i < god->ite)
	{
		z = init_cplx(z.r * z.r - z.i * z.i + god->julia_c.r,
				2 * z.r * z.i + god->julia_c.i);
		i++;
	}
	return (discont_to_black(
			((god->ite - i) * (god->ite - i) * (god->ite - i))
			% (god->ite * god->ite * god->ite)));
}
