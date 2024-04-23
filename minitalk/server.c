/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:17:52 by rmikhayl          #+#    #+#             */
/*   Updated: 2024/04/23 16:18:37 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

// Reconstruct characters from incoming bits. SIGUSR1 ->  binary 1, SIGUSR2 -> 0
// bit_count & current_char both stored in static 'data' via 8bit shift
// int 'data' 32-bit by default, we utilise MS8B for bit_count, LS8B for curr_ch
// 00000000 00000000 bbbbbbbb cccccccc <- format of 'data' after repackaging
// Prints characters upon reconstructing a full byte
// Resets and continues for next character after each byte

void	handle_signal(int signal)
{
	static int		data = 0;
	int				bit_count;
	unsigned char	current_char;

	bit_count = data >> 8;
	current_char = (unsigned char)data;
	current_char <<= 1;
	if (signal == SIGUSR1)
		current_char |= 1;
	bit_count++;
	if (bit_count == 8)
	{
		if (current_char == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", current_char);
		current_char = 0;
		bit_count = 0;
	}
	data = (bit_count << 8) | current_char;
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
