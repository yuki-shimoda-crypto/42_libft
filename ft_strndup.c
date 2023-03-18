/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:00:17 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/24 10:01:18 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <errno.h>

char	*ft_strndup(char const *s, size_t len)
{
	char	*new_str;

	if (!s)
	{
		errno = EINVAL;
		return (NULL);
	}
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	new_str = malloc(len + 1);
	if (!new_str)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_memcpy(new_str, s, len);
	new_str[len] = '\0';
	return (new_str);
}
