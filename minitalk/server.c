/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rocky <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:42:15 by rocky             #+#    #+#             */
/*   Updated: 2024/04/16 19:42:17 by rocky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft/libft.h"

void handle_signal(int signal)
{
  static unsigned char current_char;
  static int bit_index;

  current_char |= (signal == SIGUSR1);
  bit_index++;
  if (bit_index == 8){
    if (current_char == '\0')
      ft_printf("\n");
    else
      ft_printf("%c", current_char);
    bit_index = 0;
    current_char = 0;
  }
  else 
    current_char <<= 1;
}

int main()
{
  ft_printf("%d\n", getpid());
  signal(SIGUSR1, handle_signal);
  signal(SIGUSR2, handle_signal);
  // listen for & receive string
  while (1)
    pause();
  return (0);
}
