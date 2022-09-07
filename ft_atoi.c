/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:14:10 by yshimoda          #+#    #+#             */
/*   Updated: 2022/09/07 12:11:00 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_over_long(long long *num, int *minus, const char *str)
{
	if (*num > LONG_MAX / 10 && *minus == 1)
		return (1);
	if (*num == LONG_MAX / 10 && *str - '0' >= LONG_MAX % 10 && *minus == 1)
		return (1);
	if (*num > LONG_MIN / 10 * -1 && *minus == -1)
		return (1);
	if (*num == LONG_MIN / 10 * -1 && *str - '0' >= LONG_MIN % 10
		* -1 && *minus == -1)
		return (1);
	return (0);
}

static int	ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			minus;
	long long	total;
	size_t		i;

	minus = 1;
	total = 0;
	i = 0;
	while (str[i] != '\0' && ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		if (ft_over_long(&total, &minus, &str[i]) && minus == 1)
			return ((int)(LONG_MAX));
		if (ft_over_long(&total, &minus, &str[i]) && minus == -1)
			return ((int)(LONG_MIN));
		total = total * 10 + str[i] - '0';
		i++;
	}
	total *= minus;
	return ((int)total);
}

// int	main(void)
// {
// 	printf("%d %d\n", ft_atoi(""), atoi(""));
// 	printf("%d %d\n", ft_atoi("-"), atoi("-"));
// 	printf("%d %d\n", ft_atoi("+"), atoi("+"));
// 	printf("%d %d\n", ft_atoi("0"), atoi("0"));
// 	printf("%d %d\n", ft_atoi("-0"), atoi("-0"));
// 	printf("%d %d\n", ft_atoi("+0"), atoi("+0"));
// 	printf("%d %d\n", ft_atoi("1"), atoi("1"));
// 	printf("%d %d\n", ft_atoi("-1"), atoi("-1"));
// 	printf("%d %d\n", ft_atoi("+1"), atoi("+1"));
// 	printf("%d %d\n", ft_atoi("7"), atoi("7"));
// 	printf("%d %d\n", ft_atoi("-7"), atoi("-7"));
// 	printf("%d %d\n", ft_atoi("+7"), atoi("+7"));
// 	printf("%d %d\n", ft_atoi("42"), atoi("42"));
// 	printf("%d %d\n", ft_atoi("-42"), atoi("-42"));
// 	printf("%d %d\n", ft_atoi("a"), atoi("a"));
// 	printf("%d %d\n", ft_atoi("!"), atoi("!"));
// 	printf("%d %d\n", ft_atoi("2147483647"), atoi("2147483647"));
// 	printf("%d %d\n", ft_atoi("-2147483648"), atoi("-2147483648"));
// 	printf("%d %d\n", ft_atoi("4294967295"), atoi("4294967295"));
// 	/*20*/printf("%d %d\n", ft_atoi("9223372036854775807"),
// 			atoi("9223372036854775807"));
// 	printf("%d %d\n", ft_atoi("-9223372036854775808"),
// 			atoi("-9223372036854775808"));
// 	printf("%d %d\n", ft_atoi("18446744073709551615"),
// 			atoi("18446744073709551615"));
// 	printf("%d %d\n", ft_atoi("18446744073709551615"),
// 			atoi("18446744073709551615"));

// 	printf("%d %d\n", ft_atoi("2147483648"), atoi("2147483648"));
// 	printf("%d %d\n", ft_atoi("-2147483649"), atoi("-2147483649"));
// 	printf("%d %d\n", ft_atoi("4294967296"), atoi("4294967296"));
// /*27*/printf("%d %d\n",ft_atoi("9223372036854775808"),
// 		 atoi("9223372036854775808"));
// /*28*/printf("%d %d\n", ft_atoi("-9223372036854775809"),
// 		atoi("-9223372036854775809"));
// /*29*/printf("%d %d\n", ft_atoi("18446744073709551616"),
// 		atoi("18446744073709551616"));
// /*30*/printf("%d %d\n", ft_atoi("18446744073709551616"),
// 		atoi("18446744073709551616"));
// 	printf("%d %d\n", ft_atoi("2147483646"), atoi("2147483646"));
// 	printf("%d %d\n", ft_atoi("-2147483647"), atoi("-2147483647"));
// 	printf("%d %d\n", ft_atoi("4294967294"), atoi("4294967294"));
// 	printf("%d %d\n", ft_atoi("9223372036854775806"),
// 			atoi("9223372036854775806"));
// 	printf("%d %d\n", ft_atoi("-9223372036854775807"),
// 			atoi("-9223372036854775807"));
// /*36*/printf("%d %d\n", ft_atoi("18446744073709551614"),
// 		atoi("18446744073709551614"));
// /*37*/printf("%d %d\n", ft_atoi("18446744073709551614"),
// 		atoi("18446744073709551614"));
// 	printf("%d %d\n", ft_atoi("000000000000000000008"),
// 			atoi("000000000000000000008"));
// 	printf("%d %d\n", ft_atoi("-000000000000000000008"),
// 			atoi("-000000000000000000008"));
// 	printf("%d %d\n", ft_atoi("+000000000000000000008"),
// 			atoi("+000000000000000000008"));

// 	printf("%ld\n", LONG_MAX);		
// 	printf("%lld\n", LLONG_MAX);		
// 	printf("%d\n", atoi("9223372036854775807"));
// 	printf("%d\n", atoi("9223372036854775808"));
// 	printf("%d\n", atoi("9223372036854775809"));
// 	printf("%d\n", atoi("9223372036854775810"));
// 	return (0);
// }
