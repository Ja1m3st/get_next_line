/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimesanchez <jaimesanchez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:26:36 by jaisanch          #+#    #+#             */
/*   Updated: 2022/12/13 14:09:19 by jaimesanche      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return(0);
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	if (c == 0)
	{
		i = ft_strlen((char *)s);
		return (&s[i]);
	}
	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*all;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char)* 1);
		s1[0] ='\0';
	}
	if (!s1 || !s2)
	{
		return (NULL);
	}
	all = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!all)
		return (NULL);
	i = 0;
	j = 0;

	while(s1[i] != '\0')
	{
		all[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		all[i] = s2[j];
		i++;
		j++;
	}
	all[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return(all);
}
