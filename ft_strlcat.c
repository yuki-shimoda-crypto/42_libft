/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:14:10 by yshimoda          #+#    #+#             */
/*   Updated: 2022/08/20 15:40:26 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;

	if (!dst && src && dstsize == 0)
		return (ft_strlen(src));
	dst_len = ft_strlen(dst);
	i = 0;
	while (i + dst_len + 1 < dstsize && src[i] != '\0')
	{
		dst[i + dst_len] = src[i];
		i++;
	}
	if (dst_len < dstsize)
		dst[i + dst_len] = '\0';
	if (dst_len > dstsize)
		dst_len = dstsize;
	return (dst_len + ft_strlen(src));
}

// int	main(void)
// {
// 	char *dst1 = calloc(100, sizeof(char));
// 	char *dst2 = calloc(100, sizeof(char));
// 	printf("01\n%zu\t%zu\n\n", ft_strlcat(dst1, "", 100), strlcat(dst2, "",
//				100));
// 	printf("02\n%s\t%s\n\n", dst1, dst2);
// 	printf("03\n%zu\t%zu\n\n", ft_strlcat(dst1, "hello", 100), strlcat(dst2,
//				"hello", 100));
// 	printf("04\n%s\t%s\n\n", dst1, dst2);
// 	printf("05\n%zu\t%zu\n\n", ft_strlcat(dst1, "world", 100), strlcat(dst2,
//				"world", 100));
// 	printf("06\n%s\t%s\n\n", dst1, dst2);
// 	char *src1 = calloc(100, sizeof(char));
// 	char *src2 = calloc(100, sizeof(char));
// 	for (int i = 0; i < 99; i++)
// 	{
// 		src1[i] = i + 1;
// 		src2[i] = i + 1;
// 	}
// 	printf("07\n%zu\t%zu\n\n", ft_strlcat(dst1, src1, 0), strlcat(dst2, src2,
//				0));
// 	printf("08\n%s\t%s\n\n", dst1, dst2);
// 	printf("09\n%zu\t%zu\n\n", ft_strlcat(dst1, src1, 10), strlcat(dst2, src2,
//				10));
// 	printf("10\n%s\t%s\n\n", dst1, dst2);
// 	printf("11\n%zu\t%zu\n\n", ft_strlcat(dst1, src1, 50), strlcat(dst2, src2,
//				50));
// 	// printf("%lu\n", ft_strlcat(NULL, src1, 1)); // segfa
// 	// printf("%lu\n", ft_strlcat(NULL, NULL, 0)); //segfa
// 	// printf("%lu\n", ft_strlcat(NULL, NULL, 1)); //segfa
// }