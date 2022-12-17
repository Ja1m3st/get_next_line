/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimesanchez <jaimesanchez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:26:33 by jaisanch          #+#    #+#             */
/*   Updated: 2022/12/14 09:31:32 by jaimesanche      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char *ft_gema(char *save)
{
	int i;
	int j;
	char *str;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save)
	{
		free(save);
		return(NULL);
	}
	i = i + (save[i] == '\n');
	str = (char *)malloc(sizeof(char)* (ft_strlen(save) - i + 1));
	if (!str)
	{
		return(NULL);
	}
	while (save[i])
	{
		str[j] = save[i];
		j++;
		i++;
	}
	str[i] = '\0';
	free(save);
	return (str);
}

char	*ft_read(char *str)
{
	int     i;
	char    *save;

	i = 0;
	if (!str)
		return (NULL);	
	while (str[i] && str[i] != '\n')
		i++;
	save = (char *)malloc(sizeof(char) * (i + 1));
	if (!save)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		save[i] = str[i];
		i++;
	}
	if (save[i] && save[i] == '\n')
	{
		save[i] = str[i];
		i++;
	}
	save[i] = '\0';
	return (save);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	static char	*save;
	int			bytes;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer= (char *)malloc(sizeof(char)*(1 + BUFFER_SIZE ));
	if (!buffer)
		return (NULL);
	while (!(ft_strchr(save, '\n')) && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (fd == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes]= '\0';
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	buffer = ft_read(save);
	save = ft_gema(save);
	return (buffer);
}

int	main()
{
	int		fd;

	fd = open("test2.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));

	close(fd);
	return (0);
}


