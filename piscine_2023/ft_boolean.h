/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:57:08 by rmikhayl          #+#    #+#             */
/*   Updated: 2023/10/25 21:15:57 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN
# include <unistd.h>
# define FT_BOOLEAN
# define SUCCESS 0
# define FALSE 0
# define TRUE 1
# define EVEN(var) (var % 2 == 0)
# define ODD_MSG "I have an odd number of arguments."
# define EVEN_MSG "I have an even number of arguments."
typedef int	t_bool;
#endif
