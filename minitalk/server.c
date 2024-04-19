/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:17:52 by rmikhayl          #+#    #+#             */
/*   Updated: 2024/04/19 17:11:32 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	handle_signal(int signal)
{
	static unsigned char	current_char;
  unsigned char temp_char;

  temp_char = current_char;
	current_char |= (signal == SIGUSR1);
	if (ft_count_bits(temp_char) == 7)
	{
		if (current_char == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", current_char);
		current_char = 0;
	}
	else
		current_char <<= 1;
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}
