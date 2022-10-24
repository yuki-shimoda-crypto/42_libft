/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:42:08 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/24 15:26:32 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static ssize_t	ft_putnbr_base(ssize_t nbr, char *base)
{
	ssize_t	base_len;
	ssize_t	nbr_len;
	ssize_t	power_index;

	base_len = ft_strlen(base);
	nbr_len = 0;
	power_index = 1;
	if (nbr < 0)
	{
		nbr_len += write(1, "-", 1);
		nbr *= -1;
	}
	while (nbr >= base_len * power_index)
		power_index *= base_len;
	while (power_index)
	{
		nbr_len += write(1, &base[nbr / power_index % base_len], 1);
		nbr %= power_index;
		power_index /= base_len;
	}
	return (nbr_len);
}

static void	ft_proc_per(const char **format, ssize_t *printed, va_list *ap)
{
	(*format)++;
	if (**format == 'c')
		*printed += ft_put_char((char)va_arg(*ap, int));
	else if (**format == 's')
		*printed += ft_put_str(va_arg(*ap, char *));
	else if (**format == 'p')
		*printed += ft_put_ptr(va_arg(*ap, uintptr_t));
	else if (**format == 'd' || **format == 'i')
		*printed += ft_putnbr_base((ssize_t)va_arg(*ap, int), DEC);
	else if (**format == 'u')
		*printed += ft_putnbr_base((ssize_t)va_arg(*ap, unsigned int), DEC);
	else if (**format == 'x')
		*printed += ft_putnbr_base((ssize_t)va_arg(*ap, unsigned int),
				HEX_LOWER);
	else if (**format == 'X')
		*printed += ft_putnbr_base((ssize_t)va_arg(*ap, unsigned int),
				HEX_UPPER);
	else if (**format == '%')
		*printed += write(1, "%", 1);
	(*format)++;
}

static void	ft_print_str(const char **format, ssize_t *printed)
{
	const char	*start;

	start = *format;
	while (**format != '%' && **format)
		(*format)++;
	*printed += write(1, start, *format - start);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	ssize_t	printed;

	printed = 0;
	va_start(ap, format);
	while (*format && printed < INT_MAX)
	{
		if (*format != '%')
			ft_print_str(&format, &printed);
		else
			ft_proc_per(&format, &printed, &ap);
	}
	va_end(ap);
	if (printed >= INT_MAX)
		return (-1);
	return (printed);
}
