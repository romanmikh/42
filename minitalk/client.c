/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:42:10 by rocky             #+#    #+#             */
/*   Updated: 2024/04/23 15:22:16 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

// * Loop from MSB to LSB
// * Check ith bit of character with bitwise bitmask &, if 1 (true), SIGUSR1
// * Sleep to avoid signal overlap   

void	send_signal(int process_id, unsigned char character)
{
	int	i;

	i = 8;
	while (--i >= 0)
	{
		if ((character & (1 << i)) != 0)
			kill(process_id, SIGUSR1);
		else
			kill(process_id, SIGUSR2);
		usleep(1000);
	}
}

int	main(int argc, char *argv[])
{
	int			i;
	int			process_id;
	const char	*str;

	if (argc != 3)
	{
		ft_printf("Please provide two arguments: process_id & string.");
		return (1);
	}
	process_id = ft_atoi(argv[1]);
	str = argv[2];
	i = 0;
	while (str[i] != '\0')
		send_signal(process_id, str[i++]);
	send_signal(process_id, '\0');
	return (0);
}
