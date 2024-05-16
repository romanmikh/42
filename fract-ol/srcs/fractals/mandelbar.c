/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:58:05 by rmikhayl          #+#    #+#             */
/*   Updated: 2024/05/15 13:58:07 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mandelbar(t_god *god)
{
	t_cplx		c;
	double		tmp;
	int			i;

	c.r = god->c.r;
	c.i = god->c.i;
	i = 0;
	while (c.r * c.r + c.i * c.i < 4 && i < god->ite)
	{
		tmp = c.r * c.r - c.i * c.i + god->c.r;
		c.i = -2.0 * c.r * c.i + god->c.i;
		c.r = tmp;
		i++;
	}
	return (discont_to_black(
			255 - 255 * ((god->ite - i) * (god->ite - i) * (god->ite - i))
			% (god->ite * god->ite * god->ite)));
}
