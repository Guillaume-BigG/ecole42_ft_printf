/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:54:24 by guillaumebe       #+#    #+#             */
/*   Updated: 2023/11/13 14:09:04 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_strdup_word(char **split, char const *s, char c)
{
	int	size;
	int	word;

	word = 0;
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		size = 0;
		while (s[size] && !(s[size] == c))
			size++;
		if (s[size] || size)
		{
			split[word] = malloc(sizeof(char) * (size + 1));
			if (split[word] == NULL)
				return (NULL);
			ft_strlcpy(split[word], s, size + 1);
			word++;
		}
		s = s + size;
	}
	return (split);
}

static int	ft_count_word(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == c))
			i++;
		if (s[i])
			word++;
		while (s[i] && !(s[i] == c))
			i++;
	}
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		word;

	split = NULL;
	if (!s)
		return (NULL);
	word = ft_count_word(s, c);
	split = malloc(sizeof(char *) * (word + 1));
	if (split == NULL)
		return (NULL);
	split[word] = 0;
	split = ft_strdup_word(split, s, c);
	return (split);
}
