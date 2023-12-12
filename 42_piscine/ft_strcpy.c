/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmikhayl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:04:28 by rmikhayl          #+#    #+#             */
/*   Updated: 2023/10/17 19:50:39 by rmikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// char	*ft_strcpy(char *dest, char *src)
// {
// 	int	index;

// 	index = 0;
// 	while (src[index] != '\0')
// 	{
// 		dest[index] = src[index];
// 		index++;
// 	}
// 	return (dest);
// }
char	*ft_strcpy(char *dest, const char *src)
{
	int	index;

	index = 0;
	while (src[index] != '\0' && index < 14)  // Ensure we don't go beyond the destination buffer
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';  // Add null terminator to the destination string
	return (dest);
}
