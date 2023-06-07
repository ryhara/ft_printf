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


static size_t check_specifier(char *str, va_list args, size_t count)
{
	str++;
	if (*str == 'd')
		count = ft_putnbr_fd_count(va_arg(args, int), 1, count);
	else if (*str == 'i')
		count = ft_putnbr_fd_count(va_arg(args, int), 1, count);
	else if (*str == 'c')
		count = ft_putchar_fd_count(va_arg(args, int), 1, count);
	else if (*str == 's')
		count = ft_putstr_fd_count(va_arg(args, char*), 1, count);
	else if (*str == 'u')
		count = ft_putui_fd_count(va_arg(args, unsigned int), 1, count);
	else if (*str == 'x')
		count = ft_putnbr_base_fd_count(va_arg(args, int), "0123456789abcdef", 1, count);
	else if (*str == 'X')
		count = ft_putnbr_base_fd_count(va_arg(args, int), "0123456789ABCDEF", 1, count);
	else if (*str == 'p')
	{
		count = ft_putstr_fd_count("0x", 1, count);
		count = ft_putnbr_base_fd_count(va_arg(args, unsigned long long), "0123456789abcdef", 1, count);
	}
	else if (*str == '%')
		count = ft_putchar_fd_count('%', 1, count);
	str++;
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
			count = check_specifier(str, args, count);
			str += 2;
		}
		else
		{
			count = ft_putchar_fd_count(*str, 1, count);
			str++;
		}
	}
	va_end(args);
	return ((int)count);
}

#include <stdio.h>
int main(void)
{
	int count1 = 0;
	int count2 = 0;
	int d = 42;
	int d1 = 42;
	int d2 = 42;
	char c = 'f';
	char *s="42TOKYO";
	unsigned int ui = UINT_MAX;

	count1 = printf("st: %d %i %c %s %% %u %x %X %p 42tokyo\n", d, d, c, s, ui, d1, d2, s);
	printf("count1 : %d\n", count1);
	count2 = ft_printf("ft: %d %i %c %s %% %u %x %X %p 42tokyo\n", d, d,  c, s, ui, d1, d2, s);
	ft_printf("count2 : %d\n", count2);

}