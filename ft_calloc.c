/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:14:10 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/24 10:16:20 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <errno.h>

bool	check_overflow(size_t count, size_t size)
{
	return (count != 0 && (SIZE_MAX / count) < size);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total_size;

	if (check_overflow(count, size))
	{
		errno = EOVERFLOW;
		return (NULL);
	}
	total_size = count * size;
	ptr = malloc(total_size);
	if (!ptr)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_memset(ptr, 0, total_size);
	return (ptr);
}
