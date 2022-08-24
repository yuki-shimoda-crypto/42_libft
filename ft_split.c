/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:14:10 by yshimoda          #+#    #+#             */
/*   Updated: 2022/08/20 15:43:51 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(char **ptr, size_t num_ele)
{
	size_t	i;

	i = 0;
	while (i < num_ele)
		free(ptr[i++]);
	free(ptr);
}

char	*ft_write_element(const char *s, size_t begin, size_t end,
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

size_t	ft_count_elements(const char *s, char c)
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

// int	main(void)
// {
// 	char	**ptr1, **ptr2, **ptr3;

// 	ptr1 = ft_split("hello,world,42,tokyo", ',');
// 	for (int i = 0; i < 5; i++)
// 		printf("%s\n", ptr1[i]);
// 	printf("\n");
// 	ptr2 = ft_split("AAbbBBbbCC", 'b');
// 	for (int i = 0; i < 4; i++)
// 		printf("%s\n", ptr2[i]);
// 	printf("\n");
// 	ptr3 = ft_split(",,,hello,,,world,,,42,,,tokyo,,,,", ',');
// 	for (int i = 0; i < 4; i++)
// 		printf("%s\n", ptr3[i]);

// 	return (0);
// }
