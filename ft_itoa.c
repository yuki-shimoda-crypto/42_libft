/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:14:10 by yshimoda          #+#    #+#             */
/*   Updated: 2022/08/21 19:06:15 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(char *x, char *y)
{
	char	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void	ft_reverse(char *str, size_t begin, size_t end)
{
	while (begin < end)
		ft_swap(&str[begin++], &str[end--]);
}

static	void	ft_process(size_t *i, char *ptr, const int *n)
{
	if (*n > 0)
		*i -= 1;
	if (*n == 0)
		*ptr = '0';
	if (*n < 0)
		*ptr = '-';
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		tmp_n;
	size_t	i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	ptr = (char *)malloc(sizeof(char) * 12);
	if (ptr == NULL)
		return (NULL);
	tmp_n = n;
	if (n < 0)
		tmp_n *= -1;
	i = 0;
	while (tmp_n)
	{
		ptr[i++] = (tmp_n % 10) + '0';
		tmp_n /= 10;
	}
	ft_process(&i, &ptr[i], &n);
	ft_reverse(ptr, 0, i);
	ptr[i + 1] = '\0';
	return (ptr);
}

// int	main(void)
// {
// 	printf("%s,\t%d\n", ft_itoa(0), 0);
// 	printf("%s,\t%d\n", ft_itoa(-0), -0);
// 	printf("%s,\t%d\n", ft_itoa(+0), +0);
// 	printf("%s,\t%d\n", ft_itoa(1), 1);
// 	printf("%s,\t%d\n", ft_itoa(-1), -1);
// 	printf("%s,\t%d\n", ft_itoa(+1), +1);
// 	printf("%s,\t%d\n", ft_itoa(7), 7);
// 	printf("%s,\t%d\n", ft_itoa(-7), -7);
// 	printf("%s,\t%d\n", ft_itoa(+7), +7);
// 	printf("%s,\t%d\n", ft_itoa(42), 42);
// 	printf("%s,\t%d\n", ft_itoa(-42), -42);
// 	printf("%s,\t%d\n", ft_itoa(+42), +42);
// 	printf("%s,\t%d\n", ft_itoa(2147483647), 2147483647);
// 	printf("%s,\t%d\n", ft_itoa(-2147483648), -2147483648);
// 	printf("%s,\t%d\n", ft_itoa(2147483646), 2147483646);
// 	printf("%s,\t%d\n", ft_itoa(-2147483647), -2147483647);
// 	return (0);
// }
