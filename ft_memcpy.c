/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:14:10 by yshimoda          #+#    #+#             */
/*   Updated: 2022/08/18 17:18:46 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t			i;
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;

	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst_ptr[i] = src_ptr[i];
		i++;
	}
	return (dst_ptr);
}

// C99 introduces the RESTRICT modifier to explicitly
// indicate that it refers to a different region.

// int	main(void)
// {
// 	char src[] = "0123456789";
// 	char src_2[] = "0123456789";
// 	char dst1[100];
// 	char dst2[100];
// 	printf("%s %s\n", ft_memcpy(dst1, src, 100), memcpy(dst1, src, 100));
// 	printf("%s %s\n", ft_memcpy(src_2 + 3, src_2, 5), memcpy(src_2 + 3, src_2,
//				5));
// 	printf("%s %s\n", ft_memcpy(dst1, src, 100), memcpy(dst1, src, 100));
// 	printf("%s %s\n", ft_memcpy(src_2 + 3, src_2, 5), memcpy(src_2 + 3, src_2,
//				5));
// }
