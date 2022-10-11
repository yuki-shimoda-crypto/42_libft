/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:14:10 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/10 03:23:33by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	char	*ptr;

	len_s = ft_strlen(s);
	if (len_s < len)
		len = len_s;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len && i + start < len_s)
	{
		ptr[i] = s[i + start];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// int	main(void)
// {
// 	char *s = "libft-test-tokyo";
// 	printf("%s\n%s\n\n", ft_substr(s, 0, 100), s);
// 	printf("%s\n%s\n\n", ft_substr(s, 5, 100), s + 5);
// 	printf("%s\n%s\n\n", ft_substr(s, 10, 100), s + 10);
// 	printf("%s\n%s\n\n", ft_substr(s, 15, 100), s + 15);
// 	printf("%s\n%s\n\n", ft_substr(s, 20, 100), "");
// 	printf("%s\n%s\n\n", ft_substr(s, 0, 5), "libft");
// 	printf("%s\n%s\n\n", ft_substr(s, 5, 5), "-test");
// 	printf("%s\n%s\n\n", ft_substr(s, 10, 5), "-toky");
// 	printf("%s\n%s\n\n", ft_substr(s, 15, 5), "o");
// 	printf("%s\n%s\n\n", ft_substr(s, 20, 5), "");
// 	printf("%s\n%s\n\n", ft_substr(s, 0, 0), "");
// 	printf("%s\n%s\n\n", ft_substr(s, 5, 0), "");
// 	printf("%s\n%s\n\n", ft_substr(s, 10, 0), "");
// 	printf("%s\n%s\n\n", ft_substr(s, 15, 0), "");
// 	printf("%s\n%s\n\n", ft_substr(s, 20, 0), "");
// 	return (0);
// }
