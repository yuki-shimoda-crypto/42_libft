/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:14:10 by yshimoda          #+#    #+#             */
/*   Updated: 2022/08/18 17:18:54 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (SIZE_MAX / count < size)
		return (NULL);
	ptr = (void *)malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

// int	main(void)
// {
// 	printf("%p %p\n", ft_calloc(1, 2), calloc(1, 2));
// 	printf("%p %p\n", ft_calloc(SIZE_MAX, 2), calloc(SIZE_MAX, 2));
// 	printf("%p %p\n", ft_calloc(SIZE_MAX, SIZE_MAX), calloc(SIZE_MAX,
//				SIZE_MAX));
// 	printf("%p %p\n", ft_calloc(0, 0), calloc(0, 0));
// 	printf("%p %p\n", ft_calloc(1, 0), calloc(1, 0));
// 	printf("%p %p\n", ft_calloc(0, 0), calloc(0, 0));
// 	return (0);
// }
