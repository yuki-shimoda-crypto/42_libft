/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:14:10 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/13 00:03:30 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (!len || d == s)
		return (d);
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
	}
	else
	{
		while (len--)
			*d++ = *s++;
	}
	return (dst);
}

// int main(void)
// {
// 	printf("%s\n", ft_memmove());
// 	return (0);/////
// }
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
