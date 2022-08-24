/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:14:10 by yshimoda          #+#    #+#             */
/*   Updated: 2022/08/21 19:00:52 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
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
