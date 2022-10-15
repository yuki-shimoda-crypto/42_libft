/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:45:04 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/14 19:33:23y yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **ret)
{
	size_t	i;

	i = 0;
	while (ret[i])
	{
		free(ret[i]);
		ret[i] = NULL;
		i++;
	}
	return (NULL);
}

static char	*ft_strndup(char *s, size_t len)
{
	char	*tmp;
	char	*save;
	size_t	i;

	if (!s)
		return (NULL);
	tmp = malloc(len + 1);
	if (!tmp)
		return (NULL);
	save = tmp;
	i = 0;
	while (i < len && *s)
	{
		*tmp++ = *s++;
		i++;
	}
	*tmp = '\0';
	return (save);
}

static char	**make_ret(char *s, char c, char **ret)
{
	char	*head;
	char	*tail;
	int		i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			head = s;
			while (*s != c && *s)
				s++;
			tail = s;
			ret[i] = ft_strndup(head, tail - head);
			if (!ret[i])
				return (ft_free(ret));
			i++;
		}
		else
			s++;
	}
	ret[i] = NULL;
	return (ret);
}

static size_t	word_count(char *s, char c)
{
	size_t	words;

	words = 0; 
	while (*s) {
		if (*s != c)
		{
			words++;
			while (*s != c)
				s++;
		}
		else
			s++;
	}
	return (words);
}

char	**split(char *s, char c)
{
	char	**ret;

	if (!s)
		return (NULL);
	ret = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!ret)
		return (NULL);
	ret = make_ret(s, c, ret);
	if (!*ret)
		free(ret);
	return (ret);
}
