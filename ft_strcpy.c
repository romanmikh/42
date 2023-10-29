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

char	*ft_strcpy(char *dest, char *src)
{
	int	index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	return (dest);
}
/*
int	main()
{
	char s1[] = "Flaviano";
	char s2[] = "Octavio";

	

	printf("s1: %s s2: %s\n", s1, s2);
	ft_strcpy(s1, s2);
	printf("s1: %s. s2: %s", s1, s2);
	return (0);
}*/
