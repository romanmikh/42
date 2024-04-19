/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:42:10 by rocky             #+#    #+#             */
/*   Updated: 2024/04/19 14:30:00 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	send_signal(int process_id, unsigned char character)
{
	int				i;
	unsigned char	temp_char;

	i = 8;
	temp_char = character;
	while (i-- > 0)
	{
		temp_char = character >> i;
		if (temp_char % 2 == 0)
			kill(process_id, SIGUSR2);
		else
			kill(process_id, SIGUSR1);
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
		ft_printf("Please provide two arguments: process_id & the \
				string to send.");
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
