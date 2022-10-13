/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:04:56 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/13 22:52:18 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	error_free(char **ret)
{
	while (*ret)
		free(*ret++);
	return (1);
}

char	*strndup(const char *s, size_t n)
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

int	make_ret(const char *s, char c, char **ret)
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
			if (!ret[i])
				return (error_free(ret));
			ret[i + 1] = NULL;
			i++;
		}
		else
			s++;
	}
	return (0);
}

size_t	get_word_count(const char *s, char c)
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
	if (make_ret(s, c, ret))
		free(ret);
	return (ret);
}

int main(int argc, char const *argv[])
{
	char	**str;
	size_t	i;

	i = 0;
	str = ft_split("a11111a22222aaa3333a44aa5", 'a');
	while (1)
	{
		if (!str[i])
			break ;
		printf("%s\n", str[i]);
		i++;
	}
	return (0);
}
