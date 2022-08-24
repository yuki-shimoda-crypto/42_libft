/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:14:10 by yshimoda          #+#    #+#             */
/*   Updated: 2022/08/21 19:03:20 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// char	ft_plusone(unsigned int i, char c)
// {
// 	return (1 + c);
// }

// char	ft_plusi(unsigned int i, char c)
// {
// 	return (i + c);
// }

// int	main(void)
// {
// 	printf("%s\n", ft_strmapi("abcdefg", ft_plusone));
// 	printf("%s\n", ft_strmapi("abcdefg", ft_plusi));
// 	printf("%s\n", ft_strmapi("abcdefg", NULL));
// 	printf("%s\n", ft_strmapi("", ft_plusi));
// 	return (0);
// }
