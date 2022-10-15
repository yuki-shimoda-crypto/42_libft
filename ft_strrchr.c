/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:14:10 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/15 16:19:15 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*str;
	
	if (!s)
		return (NULL);
	str = s + ft_strlen(s);
	while (1)
	{
		if (*str == (char)c)
			return ((char *)str);
		if (str == s)
			return (NULL);
		str--;
	}
	return (NULL);
}

// char	*ft_strrchr(const char *s, int c)
// {
// 	size_t	len_s;

// 	len_s = ft_strlen(s) + 1;
// 	while (0 < len_s)
// 	{
// 		if (s[len_s - 1] == (char)c)
// 			return ((char *)(s + len_s - 1));
// 		len_s--;
// 	}
// 	return (NULL);
// }
