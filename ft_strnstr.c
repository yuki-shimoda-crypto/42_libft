/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:14:10 by yshimoda          #+#    #+#             */
/*   Updated: 2022/08/20 16:01:28 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle[0] == '\0')
		return ((char *)(haystack));
	i = 0;
	while (i < len && haystack[i])
	{
		j = 0;
		while (haystack[i + j] && needle[j] && i + j < len && haystack[i
				+ j] == needle[j])
			j++;
		if (!needle[j])
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char *str = "libft-test-tokyo";
// 	int	len = strlen(str);
// 	for (int i = 0; i < len; i++)
// 	{
// 		printf("1\t%s\t%s\n", ft_strnstr(str, "", i), strnstr(str, "", i));
// 		printf("2\t%s\t%s\n", ft_strnstr(str, "libft-test-tokyo", i),
//				strnstr(str, "libft-test-tokyo", i));
// 		printf("3\t%s\t%s\n", ft_strnstr(str, "libft", i), strnstr(str, "libft",
//					i));
// 		printf("4\t%s\t%s\n", ft_strnstr(str, "test", i), strnstr(str, "test",
//					i));
// 		printf("5\t%s\t%s\n", ft_strnstr(str, "tokyo", i), strnstr(str, "tokyo",
//					i));
// 		printf("6\t%s\t%s\n", ft_strnstr(str, "libft~", i), strnstr(str,
//					"libft~", i));
// 		printf("7\t%s\t%s\n\n", ft_strnstr(str, "z", i), strnstr(str, "z", i));
// 	}
//     printf("%s\t%s\n", ft_strnstr("", "hello", 5), strnstr("", "hello", 5));
//     printf("%s\t%s\n", ft_strnstr("", "", 0), strnstr("", "", 0));
//     printf("%s\t%s\n", ft_strnstr(NULL, "1", 0), strnstr(NULL, "1", 0));
//     // Segmentation Fault
//     // printf("%s\t%s\n", ft_strnstr(NULL, "fake", 3), strnstr(NULL, "fake",
//			3));
//     // printf("%s\t%s\n", ft_strnstr(NULL, "1", 1), ft_strnstr(NULL, "1",
//			1));
// }
