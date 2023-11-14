/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkmb <alkmb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 04:32:24 by akambou           #+#    #+#             */
/*   Updated: 2023/11/14 09:13:15 by akambou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	word_count(char const *s, char c)
{
	size_t	wrd;

	wrd = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			wrd++;
		while (*s && *s != c)
			s++;
	}
	return (wrd);
}

static size_t	wrd_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char	*wrd_str(const char *s, size_t start, size_t wrd_len)
{
	char	*wrd_str;

	wrd_str = malloc(sizeof(char) * (wrd_len + 1));
	if (!wrd_str)
		return (NULL);
	while (start < wrd_len)
	{
		wrd_str[start] = s[start];
		start++;
	}
	wrd_str[start] = '\0';
	return (wrd_str);
}

static char	**wrd_arr(char const *s, size_t n_wds, char c, char **w_arr)
{
	size_t	i;
	char	*str;

	i = 0;
	while (i < n_wds)
	{
		while (*s == c && *s)
			s++;
		str = (char *)s;
		while (*s != c && *s)
			s++;
		w_arr[i] = wrd_str(str, 0, wrd_len(str, c));
		if (!w_arr[i])
		{
			while (i > 0)
				free(w_arr[--i]);
			free(w_arr);
			return (NULL);
		}
		i++;
	}
	w_arr[i] = NULL;
	return (w_arr);
}

char	**ft_split(char const *s, char c)
{
	char	**w_arr;
	size_t	n_wrd;

	w_arr = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!w_arr)
		return (NULL);
	n_wrd = word_count(s, c);
	w_arr = wrd_arr(s, n_wrd, c, w_arr);
	return (w_arr);
}
/*
int	main(void)
{
	char const	*str;
	char		delimiter;
	char		**result;
	int			i;

	i = 0;
	delimiter = ' ';
	str = "Me estoy follando a tu madre saludos y feliz cumpleaños";
	result = ft_split(str, delimiter);
	if (result)
	{
		while (result[i] != NULL)
		{
			i++;
			printf("Palabra %d: %s\n", i + 1, result[i]);
			free(result[i]);
		}
		free(result);
	}
	else
	{
		printf("La división de la cadena falló por problemas de memoria.\n");
	}
	return (0);
}
*/
