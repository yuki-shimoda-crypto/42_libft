/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:14:10 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/13 14:34:04 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static void	ft_swap(char *x, char *y)
// {
// 	char	tmp;

// 	tmp = *x;
// 	*x = *y;
// 	*y = tmp;
// }

// static void	ft_reverse(char *str, size_t begin, size_t end)
// {
// 	while (begin < end)
// 		ft_swap(&str[begin++], &str[end--]);
// }

// static	void	ft_process(size_t *i, char *ptr, const int *n)
// {
// 	if (*n > 0)
// 		*i -= 1;
// 	if (*n == 0)
// 		*ptr = '0';
// 	if (*n < 0)
// 		*ptr = '-';
// }

// char	*ft_itoa(int n)
// {
// 	char	*ptr;
// 	int		tmp_n;
// 	size_t	i;

// 	if (n == -2147483648)
// 		return (ft_strdup("-2147483648"));
// 	ptr = (char *)malloc(sizeof(char) * 12);
// 	if (ptr == NULL)
// 		return (NULL);
// 	tmp_n = n;
// 	if (n < 0)
// 		tmp_n *= -1;
// 	i = 0;
// 	while (tmp_n)
// 	{
// 		ptr[i++] = (tmp_n % 10) + '0';
// 		tmp_n /= 10;
// 	}
// 	ft_process(&i, &ptr[i], &n);
// 	ft_reverse(ptr, 0, i);
// 	ptr[i + 1] = '\0';
// 	return (ptr);
// }

static ssize_t	ft_pow(ssize_t x, ssize_t y)
{
	while (y)
	{
		x *= x;
		y--;
	}
	return (x);
}

static int	num_len(int n)
{
	int	i;
	
	i = 0;
	if (!n)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ret;
	long	num;
	int		n_len;

	num = n;
	n_len = num_len(n);
	ret = malloc(sizeof(int) * (n_len + 1));
	if (!ret)
		return (NULL);
	if (n < 0)
	{
		*ret++ = '-';
		n_len--;
	}
	while (n_len)
	{
		*ret++ = n % (10, n_len) + '0';
		n_len--;
	}
	return (ret);

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

#include <stdio.h>
int main(void)
{
	printf("%zu\n", ft_itoa(0));
	printf("%zu\n", num_len(100));
	printf("%zu\n", num_len(-100));
	printf("%zu\n", num_len(INT_MAX));
	printf("%zu\n", num_len(INT_MIN));
	return (0);
}