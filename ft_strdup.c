/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:14:10 by yshimoda          #+#    #+#             */
/*   Updated: 2022/09/15 07:40:06 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	char	*save;

	if (!s1)
		return (NULL);
	ptr = (char *)malloc(ft_strlen(s1) + 1);
	if (!ptr)
		return (NULL);
	save = ptr;
	while (*s1)
		*ptr++ = *s1++;
	*ptr = 0;
	return (save);
}

// int	main(void)
// {
// 	char *string = "this is a copy";
// 	char *newstr;
//    	/* Make newstr point to a duplicate of string*/
//    	if ((newstr = ft_strdup(string)) != NULL)
// 	{
// 		printf("The new string is: %s\n", newstr);
// 		printf("%p\n%p\n", string, newstr);
// 	}
// 	// printf("%s\t%s\n", ft_strdup(NULL), strdup(NULL));	
// 	printf("%s\n", strdup((char *)""));	
// 	printf("%s\n", ft_strdup((char *)""));	
// 	printf("%p\n", strdup((char *)""));	
// 	printf("%p\n", ft_strdup((char *)""));	
//    	return (0);
// }
