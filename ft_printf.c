/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:42:18 by ryhara            #+#    #+#             */
/*   Updated: 2023/06/06 12:42:18 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	size_t	check_specifier(char *str, va_list args, size_t count)
{
	char	*base;

	if (*str == 'd' || *str == 'i')
		count = ft_putnbr_count(va_arg(args, int), count);
	else if (*str == 'c')
		count = ft_putchar_count(va_arg(args, int), count);
	else if (*str == 's')
		count = ft_putstr_count(va_arg(args, char *), count);
	else if (*str == 'u')
		count = ft_putui_count(va_arg(args, unsigned int), count);
	else if (*str == 'x')
		count = ft_putnbr_base(va_arg(args, int), "0123456789abcdef", count);
	else if (*str == 'X')
		count = ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF", count);
	else if (*str == 'p')
	{
		count = ft_putstr_count("0x", count);
		base = "0123456789abcdef";
		count = ft_putnbr_base(va_arg(args, unsigned long long), base, count);
	}
	else if (*str == '%')
		count = ft_putchar_count('%', count);
	else
		return (-1);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	size_t	count;
	char	*str;

	count = 0;
	str = (char *)s;
	if (s == NULL)
		return (-1);
	va_start(args, s);
	while (*str)
	{
		if (*str == '%')
		{
			count = check_specifier(++str, args, count);
			if (count == -1)
				return (-1);
			str++;
		}
		else
			count = ft_putchar_count(*str++, count);
	}
	va_end(args);
	return ((int)count);
}

// #include <stdio.h>
// int main(void)
// {
// 	int count1 = 0;
// 	int count2 = 0;
// 	int d = 42;
// 	int d1 = 42;
// 	int d2 = 42;
// 	char c = 'f';
// 	char *s="42TOKYO";
// 	unsigned int ui = UINT_MAX;
// 	count1 = printf("st:%i %s %% %u %x %p\n",d, s, ui, d1, s);
// 	printf("count1 : %d\n", count1);

// 	count2 = ft_printf("ft:%i %s %% %u %x %p\n", d, s, ui, d1, s);
// 	ft_printf("count2 : %d\n", count2);
// }