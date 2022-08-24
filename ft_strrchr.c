/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:14:10 by yshimoda          #+#    #+#             */
/*   Updated: 2022/08/20 15:53:54 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len_s;

	len_s = ft_strlen(s) + 1;
	while (0 < len_s)
	{
		if (s[len_s - 1] == (char)c)
			return ((char *)(s + len_s - 1));
		len_s--;
	}
	return (NULL);
}
// Plus one to search for '\0'.
// size_t has no negative value, so it cannot be compared with a;

// int	main(void)
// {
// 	char *s = "libft-test-tokyo";
// 	printf("%s\t%s\n", ft_strrchr(s, 'l'), strrchr(s, 'l'));
// 	printf("%s\t%s\n", ft_strrchr(s, 'i'), strrchr(s, 'i'));
// 	printf("%s\t%s\n", ft_strrchr(s, 'b'), strrchr(s, 'b'));
// 	printf("%s\t%s\n", ft_strrchr(s, 'f'), strrchr(s, 'f'));
// 	printf("%s\t%s\n", ft_strrchr(s, 't'), strrchr(s, 't'));
// 	printf("%s\t%s\n", ft_strrchr(s, '-'), strrchr(s, '-'));
// 	printf("%s\t%s\n", ft_strrchr(s, 't'), strrchr(s, 't'));
// 	printf("%s\t%s\n", ft_strrchr(s, 'e'), strrchr(s, 'e'));
// 	printf("%s\t%s\n", ft_strrchr(s, 's'), strrchr(s, 's'));
// 	printf("%s\t%s\n", ft_strrchr(s, 't'), strrchr(s, 't'));
// 	printf("%s\t%s\n", ft_strrchr(s, '-'), strrchr(s, '-'));
// 	printf("%s\t%s\n", ft_strrchr(s, 't'), strrchr(s, 't'));
// 	printf("%s\t%s\n", ft_strrchr(s, 'o'), strrchr(s, 'o'));
// 	printf("%s\t%s\n", ft_strrchr(s, 'k'), strrchr(s, 'k'));
// 	printf("%s\t%s\n", ft_strrchr(s, 'y'), strrchr(s, 'y'));
// 	printf("%s\t%s\n", ft_strrchr(s, 'o'), strrchr(s, 'o'));
// 	printf("%s\t%s\n", ft_strrchr(s, '\0'), strrchr(s, '\0'));
// 	printf("%s\t%s\n", ft_strrchr(s, 'l' + 256), strrchr(s, 'l' + 256));
// 	printf("%s\t%s\n", ft_strrchr(s, 'i' + 256), strrchr(s, 'i' + 256));
// 	printf("%s\t%s\n", ft_strrchr(s, 'l' - 256), strrchr(s, 'l' - 256));
// 	printf("%s\t%s\n", ft_strrchr(s, 'i' - 256), strrchr(s, 'i' - 256));
// 	printf("%s\t%s\n", ft_strrchr(s, 'z'), strrchr(s, 'z'));
// 	printf("%s\t%s\n", ft_strrchr(s, '~'), strrchr(s, '~'));
// 	return (0);
// }
