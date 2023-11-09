/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkmb <alkmb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 22:18:36 by akambou           #+#    #+#             */
/*   Updated: 2023/09/20 03:37:33 by alkmb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((i < n - 1) && str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}
/*
int	main(void)
{
	char	*s1;
	char	*s2;
	int		result;

	s1 = "La puta de dsojkfhaskljfhkasdjhf";
	s2 = "La puta de tu madre";
	result = ft_strncmp(s1, s2, 11);
	if (result == 0)
		printf ("The strings are equal at this point.");
	else
		printf ("The string are different in the character: %d", result);
}
*/
