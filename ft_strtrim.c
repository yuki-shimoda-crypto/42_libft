/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:14:10 by yshimoda          #+#    #+#             */
/*   Updated: 2022/08/24 12:43:00 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_trimmed(char const *c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == *c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	begin;
	size_t	end;
	size_t	i;
	char	*ptr;

	begin = 0;
	while (s1[begin] && ft_find_trimmed(&s1[begin], set))
		begin++;
	end = ft_strlen(s1);
	while (begin < end && ft_find_trimmed(&s1[end - 1], set))
		end--;
	ptr = (char *)malloc(sizeof(char) * (end - begin));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (0 < end - begin)
		ptr[i++] = s1[begin++];
	ptr[i] = '\0';
	return (ptr);
}

// int	main(void)
// {
// 	printf("%s\t%s\n\n", ft_strtrim("hello world", "world"), "hello ");
// 	printf("%s\t%s\n\n", ft_strtrim("hello world", "hello"), " world");
// 	printf("%s\t%s\n\n", ft_strtrim("hello world", ""), "hello world");
// 	printf("%s\t%s\n\n", ft_strtrim("", ""), "");
// 	printf("%s\t%s\n\n", ft_strtrim("    hello world     ", " "),
// 			"hello world");
// 	printf("%s\n%s\n\n",
// 			ft_strtrim(" \n\t\r    hello \n\t\r world     \r\t\n\t \r\n",
// 				" \n\t\r"), "hello \n\t\r world");
// 	printf("%s\t%s\n\n", ft_strtrim("hello world",
// 				"abcdefghijklmnopqrstuvwxyz"), " ");
// 	return (0);
// }
