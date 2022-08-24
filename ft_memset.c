/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:14:10 by yshimoda          #+#    #+#             */
/*   Updated: 2022/08/17 15:45:05 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	tmp;

	ptr = (unsigned char *)b;
	tmp = (unsigned char)c;
	i = 0;
	while (i < len)
		ptr[i++] = tmp;
	return (b);
}

// int	main(void)
// {
// 	char str[] = "0123456789";
// 	ft_memset(str+2, '*', 5);
// 	printf("%s\n", str);
// 	return (0);
// }
