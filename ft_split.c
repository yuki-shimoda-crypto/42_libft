/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:04:56 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/15 15:30:43 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*strndup(const char *s, size_t n)
{
	char	*ret;
	char	*save;
	size_t	i;

	if (!s)
		return (NULL);
	ret = malloc(sizeof(char) * (n + 1));
	if (!ret)
		return (NULL);
	save = ret;
	i = 0;
	while (*s && i < n)
	{
		*ret++ = *s++;
		i++;
	}
	*ret = 0;
	return (save);
}

static void	make_ret(const char *s, char c, char **ret)
{
	const char	*head;
	const char	*tail;
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			head = s;
			while (*s && *s != c)
				s++;
			tail = s;
			ret[i] = strndup(head, tail - head);
			ret[i + 1] = NULL;
			i++;
		}
		else
			s++;
	}
}

static size_t	get_word_count(const char *s, char c)
{
	size_t	word_count;

	word_count = 0;
	while (*s)
	{
		if (*s != c)
		{
			word_count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (word_count);
}

char **ft_split(const char *s, char c)
{
	char	**ret;
	size_t	num;

	num = get_word_count(s, c);
	ret = malloc(sizeof(char *) * (num + 1));
	if (!ret)
		return (NULL);
	make_ret(s, c, ret);
	return (ret);
}

// int main(int argc, char const *argv[])
// {
// 	/* code */
// 	return 0;
// }
