/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:14:10 by yshimoda          #+#    #+#             */
/*   Updated: 2022/08/18 17:18:31 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;

	dst_tmp = (unsigned char *)dst;
	src_tmp = (unsigned char *)src;
	i = 0;
	if (src > dst)
	{
		while (i < len)
		{
			dst_tmp[i] = src_tmp[i];
			i++;
		}
	}
	else
	{
		while (0 < len)
		{
			dst_tmp[len - 1] = src_tmp[len - 1];
			len--;
		}
	}
	return (dst);
}
// size_t has no negative value, so it cannot be compared with a;

// int	main(void)
// {
// 	char *src = malloc(100);
// 	int j = 0;
// 	for (int i = 33; i < 126; i++)
// 		src[j++] = i;
// 	char *dst1 = malloc(100);
// 	char *dst2 = malloc(100);
// 	printf("%s\n%s\n ", ft_memmove(dst1, src, 0), memmove(dst2, src, 0));
// 	printf("%s\n%s\n", ft_memmove(dst1, src, 10), memmove(dst2, src, 10));
// 	printf("%s\n%s\n", ft_memmove(dst1, src, 100), memmove(dst2, src, 100));
// 	printf("%s\n%s\n", ft_memmove(dst1 + 42, dst1, 50), memmove(dst2 + 42, dst2,
//				50));
// 	printf("%s\n%s\n", ft_memmove(dst1, dst1 + 21, 50), memmove(dst2, dst2 + 21,
//				50));
// 	return (0);
// }
