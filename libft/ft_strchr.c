/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkmb <alkmb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 22:17:18 by akambou           #+#    #+#             */
/*   Updated: 2023/09/20 03:17:59 by alkmb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	c = (char)c;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return (NULL);
}
/*
int	main(void)
{
	char	*str;
	char	*result;
	int		c;

	str = "Muy buenas tardes esta noche.";
	c = 't';
	result = ft_strchr(str, c);
	printf("The first ocurrance on the string starts in: %s\n", result);
}
*/
