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

char	*ft_strndup(char const *s, size_t len)
{
	char	*tmp;
	char	*save;
	size_t	i;

	if (!s)
		return (NULL);
	tmp = malloc(len + 1);
	if (!tmp)
		return (NULL);
	save = tmp;
	i = 0;
	while (i < len && *s)
	{
		*tmp++ = *s++;
		i++;
	}
	*tmp = '\0';
	return (save);
}
