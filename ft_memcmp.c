/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:14:10 by yshimoda          #+#    #+#             */
/*   Updated: 2022/08/17 15:31:58 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_ptr;
	unsigned char	*s2_ptr;

	s1_ptr = (unsigned char *)s1;
	s2_ptr = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_ptr[i] != s2_ptr[i])
			return (s1_ptr[i] - s2_ptr[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char	s1[] = "aaa";
// 	char	s2[] = "aaaa";
// 	char	s3[] = "aaaaa";
// 	printf("s1, s2, 0 = %d\t%d\n", ft_memcmp(s1, s2, 0), memcmp(s1, s2, 0));
// 	printf("s1, s2, 1 = %d\t%d\n", ft_memcmp(s1, s2, 1), memcmp(s1, s2, 1));
// 	printf("s1, s2, 2 = %d\t%d\n", ft_memcmp(s1, s2, 2), memcmp(s1, s2, 2));
// 	printf("s1, s2, 3 = %d\t%d\n", ft_memcmp(s1, s2, 3), memcmp(s1, s2, 3));
// 	printf("s1, s2, 4 = %d\t%d\n", ft_memcmp(s1, s2, 4), memcmp(s1, s2, 4));
// 	printf("s1, s2, 5 = %d\t%d\n", ft_memcmp(s1, s2, 5), memcmp(s1, s2, 5));
// 	printf("s2, s1, 0 = %d\t%d\n", ft_memcmp(s2, s1, 0), memcmp(s2, s1, 0));
// 	printf("s2, s1, 1 = %d\t%d\n", ft_memcmp(s2, s1, 1), memcmp(s2, s1, 1));
// 	printf("s2, s1, 2 = %d\t%d\n", ft_memcmp(s2, s1, 2), memcmp(s2, s1, 2));
// 	printf("s2, s1, 3 = %d\t%d\n", ft_memcmp(s2, s1, 3), memcmp(s2, s1, 3));
// 	printf("s2, s1, 4 = %d\t%d\n", ft_memcmp(s2, s1, 4), memcmp(s2, s1, 4));
// 	printf("s2, s1, 5 = %d\t%d\n", ft_memcmp(s2, s1, 5), memcmp(s2, s1, 5));
// 	printf("s1, s1, 0 = %d\t%d\n", ft_memcmp(s1, s1, 0), memcmp(s1, s1, 0));
// 	printf("s1, s1, 1 = %d\t%d\n", ft_memcmp(s1, s1, 1), memcmp(s1, s1, 1));
// 	printf("s1, s1, 2 = %d\t%d\n", ft_memcmp(s1, s1, 2), memcmp(s1, s1, 2));
// 	printf("s1, s1, 3 = %d\t%d\n", ft_memcmp(s1, s1, 3), memcmp(s1, s1, 3));
// 	printf("s1, s1, 4 = %d\t%d\n", ft_memcmp(s1, s1, 4), memcmp(s1, s1, 4));
// 	printf("s1, s1, 5 = %d\t%d\n", ft_memcmp(s1, s1, 5), memcmp(s1, s1, 5));
// 	printf("s1, s3, 0 = %d\t%d\n", ft_memcmp(s1, s3, 0), memcmp(s1, s3, 0));
// 	printf("s1, s3, 1 = %d\t%d\n", ft_memcmp(s1, s3, 1), memcmp(s1, s3, 1));
// 	printf("s1, s3, 2 = %d\t%d\n", ft_memcmp(s1, s3, 2), memcmp(s1, s3, 2));
// 	printf("s1, s3, 3 = %d\t%d\n", ft_memcmp(s1, s3, 3), memcmp(s1, s3, 3));
// 	printf("s1, s3, 4 = %d\t%d\n", ft_memcmp(s1, s3, 4), memcmp(s1, s3, 4));
// 	printf("s1, s3, 5 = %d\t%d\n", ft_memcmp(s1, s3, 5), memcmp(s1, s3, 5));
// }
