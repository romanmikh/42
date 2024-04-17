/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:42:10 by rocky             #+#    #+#             */
/*   Updated: 2024/04/16 19:42:11 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft/libft.h"

void send_signal(int PID, unsigned char character)
{
  // convert character into 8 bits, send to server
  // SIGUSR1 represents a 1 bit, SIGUSR2 to represent a 0 bit.
  int i;
  unsigned char temp_char;

  i = 8;
  temp_char = character;
  while (i > 0)
  {
    i--;
    temp_char = character >> i;
    if (temp_char % 2 == 0)
      kill(PID, SIGUSR2);
    else 
      kill(PID, SIGUSR1);
    usleep(69);
  }
  
}

int main(int argc, char *argv[])
{
  int i;
  pid_t PID;
  char *str;


  if (argc != 3)
  {
    ft_printf("Please provide two arguments: PID & the string to send.");
    return (1);
  }
  PID = ft_atoi(argv[1]);
  str = argv[2];
  i = 0;
  while (str[i] != '\0')
    send_signal(PID, str[i]);
  send_signal(PID, '\0');
  return (0);
}
