/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:14:10 by yshimoda          #+#    #+#             */
/*   Updated: 2022/08/18 17:17:31 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

// int main(void)
// {
// 	char *str = "libft-test-tokyo";
// 	char *cmp = "libft-test-tokyo";
// 	int	len = strlen(str);
// 	/* 1 ~ 17 */
// 	for (int i = 0; i <= len; i++)
// 		printf("%d\t%d\t%d\n", i, ft_strncmp(str, cmp, i), strncmp(str, cmp,
//					i));
// 	/* 18 ~ 51 */
// 	for (int i = 0; i <= len; i++)
// 	{
// 		cmp = strndup(str, i);
// 		printf("%d\t%d\t%d\n", i, ft_strncmp(str, cmp, i), strncmp(str, cmp,
//					i));
// 		printf("%d\t%d\t%d\n", i, ft_strncmp(str, cmp, len), strncmp(str, cmp,
//					len));
// 		free(cmp);
// 	}
// 	char *cmp2 = calloc(10, 1);
// 	strlcpy(cmp2, "libft", 10);
// 	cmp2[5] = CHAR_MIN;
// 	printf("%d\t%d\n", ft_strncmp(str, cmp2, len), strncmp(str, cmp2, len));
// 	cmp2[5] = -42;
// 	printf("%d\t%d\n", ft_strncmp(str, cmp2, len), strncmp(str, cmp2, len));
// 	cmp2[5] = 0;
// 	printf("%d\t%d\n", ft_strncmp(str, cmp2, len), strncmp(str, cmp2, len));
// 	cmp2[5] = 42;
// 	printf("%d\t%d\n", ft_strncmp(str, cmp2, len), strncmp(str, cmp2, len));
// 	cmp2[5] = CHAR_MAX;
// 	printf("%d\t%d\n", ft_strncmp(str, cmp2, len), strncmp(str, cmp2, len));
// 	printf("%d\t%d\n", ft_strncmp("hello", NULL, 0), strncmp("hello", NULL, 0));
// 	printf("%d\t%d\n", ft_strncmp(NULL, "hello", 0), strncmp(NULL, "hello", 0));
// 	printf("%d\t%d\n", ft_strncmp(NULL, NULL, 0), strncmp(NULL, NULL, 0));
// 	return (0);
// }