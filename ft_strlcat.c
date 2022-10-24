/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:14:10 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/24 10:48:22 by yshimoda         ###   ########.fr       */
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
