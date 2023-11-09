/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkmb <alkmb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 22:17:28 by akambou           #+#    #+#             */
/*   Updated: 2023/09/20 14:13:00 by alkmb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strdup(const char *str)
{
	char	*new;
	int		size;

	size = 0;
	while (str[size])
		size++;
	new = malloc((size + 1) * sizeof(char));
	if (!new)
		return (NULL);
	size = 0;
	while (str[size])
	{
		new[size] = str[size];
		size++;
	}
	new[size] = '\0';
	return (new);
}
/*
int	main(void)
{
	char	*str;
	char	*result;

	str = "Hello big chungus.";
	result = ft_strdup(str);
	printf ("This is the string after begin duplicated: %s", result);
}
*/
