/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfchouch <lfchouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 22:44:35 by lfchouch          #+#    #+#             */
/*   Updated: 2021/09/15 22:16:39 by lfchouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_next_line.h"

int	ft_strlen(char *str, int n)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	if (n == 0)
	{
		while (str[i] != '\0')
			i++;
		return (i);
	}
	else
	{
		while (str[i] != 0 && str[i] != '\n')
			i++;
		if (str[i] == '\n')
			return (i + 1);
		return (i);
	}
}

int	ft_strchr(char *s, int c)
{
	int		i;
	char	*str;

	i = -1;
	str = s;
	if (s == NULL)
		return (1);
	while (str[++i] != (char)c)
	{
		if (str[i] == '\0')
			return (1);
	}
	return (0);
}

char	*ft_strdup(char *str)
{
	int		i;

	str = malloc(sizeof(*str) * 1);
	if (!str)
		return (NULL);
	i = 0;
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*final_str;
	int		i;
	int		j;

	if (s1 == NULL && s2 == NULL)
		return (ft_strdup(""));
	final_str = malloc((ft_strlen(s1, 0) + ft_strlen(s2, 0) + 1));
	if (final_str == NULL)
		return (NULL);
	i = -1;
	while (++i < ft_strlen(s1, 0))
		final_str[i] = s1[i];
	j = -1;
	while (++j < ft_strlen(s2, 0))
		final_str[i + j] = s2[j];
	final_str[i + j] = '\0';
	return (final_str);
}

char	*ft_update_strjoin(char *s1, char *s2, ssize_t i)
{
	char	*final_str;
	int		j;
	int		k;

	if (s1 == NULL && s2 == NULL)
		return (ft_strdup(""));
	final_str = malloc((ft_strlen(s1, 0) + i + 1) * sizeof(char));
	if (final_str == NULL)
		return (NULL);
	j = -1;
	while (++j < ft_strlen(s1, 0))
		final_str[j] = s1[j];
	k = -1;
	while (++k < i)
		final_str[j + k] = s2[k];
	final_str[j + k] = '\0';
	return (final_str);
}
