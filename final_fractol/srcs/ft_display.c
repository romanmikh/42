/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:48:39 by rmikhayl          #+#    #+#             */
/*   Updated: 2024/05/13 16:48:41 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_display(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->img->addr, 0, 0);
	return (TRUE);
}
