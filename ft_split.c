/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:14:10 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/15 16:25:09 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **ptr, size_t num_ele)
{
	size_t	i;

	i = 0;
	while (i < num_ele)
		free(ptr[i++]);
	free(ptr);
}

static char	*ft_write_element(const char *s, size_t begin, size_t end,
		int *malloc_error)
{
	size_t	i;
	char	*element;

	element = (char *)malloc(sizeof(char) * (end - begin + 1));
	if (element == NULL)
	{
		*malloc_error = 1;
		return (NULL);
	}
	i = 0;
	while (begin < end)
		element[i++] = s[begin++];
	element[i] = '\0';
	return (element);
}

static	int	ft_process(char **ptr, char const *s, char c, size_t *j)
{
	size_t	i;
	int		begin;
	int		malloc_error;

	malloc_error = 0;
	begin = -1;
	i = 0;
	while (i < ft_strlen(s) + 1)
	{
		if (s[i] != c && begin < 0)
			begin = i;
		else if ((s[i] == c || i == ft_strlen(s)) && 0 <= begin)
		{
			ptr[*j] = ft_write_element(s, begin, i, &malloc_error);
			if (malloc_error)
				return (1);
			begin = -1;
			*j += 1;
		}
		i++;
	}
	ptr[*j] = 0;
	return (0);
}

static size_t	ft_count_elements(const char *s, char c)
{
	size_t	i;
	size_t	num_element;
	int		separator;

	num_element = 0;
	separator = 1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && separator)
		{
			separator = 0;
			num_element++;
		}
		else if (s[i] == c)
			separator = 1;
		i++;
	}
	return (num_element + 1);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	j;

	if (!s)
		return (NULL);
	ptr = (char **)malloc(sizeof(char *) * ft_count_elements(s, c));
	if (ptr == NULL)
		return (NULL);
	j = 0;
	if (ft_process(ptr, s, c, &j))
	{
		ft_free(ptr, j);
		return (NULL);
	}
	return (ptr);
}
// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   split.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/10/14 18:45:04 by yshimoda          #+#    #+#             */
// /*   Updated: 2022/10/14 19:33:23y yshimoda         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "libft.h"

// static char	**ft_free(char **ret)
// {
// 	size_t	i;

// 	i = 0;
// 	while (ret[i])
// 	{
// 		free(ret[i]);
// 		ret[i] = NULL;
// 		i++;
// 	}
// 	return (NULL);
// }

// static char	*ft_strndup(char *s, size_t len)
// {
// 	char	*tmp;
// 	char	*save;
// 	size_t	i;

// 	if (!s)
// 		return (NULL);
// 	tmp = malloc(len + 1);
// 	if (!tmp)
// 		return (NULL);
// 	save = tmp;
// 	i = 0;
// 	while (i < len && *s)
// 	{
// 		*tmp++ = *s++;
// 		i++;
// 	}
// 	*tmp = '\0';
// 	return (save);
// }

// static char	**make_ret(char *s, char c, char **ret)
// {
// 	char	*head;
// 	char	*tail;
// 	int		i;

// 	i = 0;
// 	while (*s)
// 	{
// 		if (*s != c)
// 		{
// 			head = s;
// 			while (*s != c && *s)
// 				s++;
// 			tail = s;
// 			ret[i] = ft_strndup(head, tail - head);
// 			if (!ret[i])
// 				return (ft_free(ret));
// 			i++;
// 		}
// 		else
// 			s++;
// 	}
// 	ret[i] = NULL;
// 	return (ret);
// }

// static size_t	word_count(char *s, char c)
// {
// 	size_t	words;

// 	words = 0; 
// 	while (*s) {
// 		if (*s != c)
// 		{
// 			words++;
// 			while (*s != c)
// 				s++;
// 		}
// 		else
// 			s++;
// 	}
// 	return (words);
// }

// char	**split(char *s, char c)
// {
// 	char	**ret;

// 	if (!s)
// 		return (NULL);
// 	ret = malloc(sizeof(char *) * (word_count(s, c) + 1));
// 	if (!ret)
// 		return (NULL);
// 	ret = make_ret(s, c, ret);
// 	if (!*ret)
// 		free(ret);
// 	return (ret);
// }
