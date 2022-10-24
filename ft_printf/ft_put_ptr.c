/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:46:49 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/11 20:56:19 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_output(uintptr_t num, ssize_t *num_len)
{
	char	c;

	if (num >= 16)
	{
		ft_output(num / 16, num_len);
		ft_output(num % 16, num_len);
	}
	else
	{
		if (num % 16 < 10)
		{
			c = (char)num + '0';
			*num_len += write(1, &c, 1);
		}
		else
		{
			c = (char)num + 'a' - 10;
			*num_len += write(1, &c, 1);
		}
	}
}

ssize_t	ft_put_ptr(uintptr_t num)
{
	ssize_t	num_len;

	num_len = write(1, "0x", 2);
	if (!num)
		num_len += write(1, "0", 1);
	else
		ft_output(num, &num_len);
	return (num_len);
}
