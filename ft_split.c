/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-alam <kel-alam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:01:27 by kel-alam          #+#    #+#             */
/*   Updated: 2021/11/15 08:48:38 by kel-alam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	len;
	size_t	index;
	size_t	in;

	len = 0;
	index = 0;
	in = 1;
	while (s[index])
	{
		if (s[index] != c)
		{
			if (in)
				len++;
			in = 0;
		}
		else
			in = 1;
		index++;
	}
	return (len);
}

void	free_words(char **p)
{
	char	**ptr;
	int		i;

	ptr = p;
	i = 0;
	while (ptr[i] != NULL)
		free(ptr[i++]);
	free(ptr);
}

static char	*ft_allocate_word(const char *s, char c, char **ptr)
{
	size_t	index;
	char	*word;

	index = 0;
	while (s[index] && s[index] != c)
		index++;
	word = malloc(index + 1);
	if (!word)
	{
		free_words(ptr);
		return (NULL);
	}
	ft_strlcpy(word, s, index + 1);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		index;
	int		jndex;
	char	**words;

	words = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!words)
		return (NULL);
	index = 0;
	jndex = 0;
	while (s[index])
	{
		if (s[index] != c)
		{
			words[jndex++] = ft_allocate_word(s + index, c, words);
			if (!words[jndex - 1])
				return (NULL);
			while (s[index] != c && s[index])
				index++;
		}
		if (s[index] != '\0')
			index++;
	}
	words[jndex] = NULL;
	return (words);
}
