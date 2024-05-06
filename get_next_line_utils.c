/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocrobin <ocrobin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:07:31 by ocrobin           #+#    #+#             */
/*   Updated: 2024/04/25 16:01:59 by ocrobin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen_eol(const char	*str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*elo;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen_eol(s1) + ft_strlen_eol(s2);
	elo = (char *)malloc(sizeof(char) * (len + 1));
	if (!elo)
		return (NULL);
	while (s1[i] != '\0')
	{
		elo[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0' && s2[j] != '\n')
		elo[i++] = s2[j++];
	elo[i] = '\0';
	return (elo);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*tab;
	size_t			i;

	i = nmemb * size;
	if (i == 0)
		return (malloc(0));
	if ((nmemb == 0) || (size > 4294967295 / nmemb))
		return (NULL);
	tab = malloc(i);
	if (!tab)
		return (NULL);
	while (i--)
		tab[i] = 0;
	return (tab);
}
