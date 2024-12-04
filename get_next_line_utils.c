/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:25:19 by kclaudan          #+#    #+#             */
/*   Updated: 2024/12/04 12:32:45 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)(s));
		s++;
	}
	if ((unsigned char)c == *s)
		return ((char *)(s));
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*cp;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	cp = malloc(sizeof(char) * len + 1);
	if (cp == NULL)
		return (NULL);
	while (i < len)
	{
		cp[i] = s[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	tab = malloc(sizeof(char) * (len + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start])
		tab[i++] = s[start++];
	tab[len] = '\0';
	return (tab);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *tab;
	int i;
	int k;

	tab = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (tab == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		tab[i] = s1[i];
	k = -1;
	while (s2[++k])
		tab[i++] = s2[k];
	tab[i] = '\0';
	return (tab);
}