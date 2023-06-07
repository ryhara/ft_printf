/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd_count.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:21:16 by ryhara            #+#    #+#             */
/*   Updated: 2023/06/07 13:21:16 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
size_t	ft_putnbr_base_fd_count(unsigned int n, char *base, int fd, size_t count)
{
	int	len;

	len = (int)ft_strlen(base);
	if (n >= len)
	{
		count = ft_putnbr_base_fd_count((n / len), base, fd, count);
		n %= len;
	}
	if (n < len)
	{
		count = ft_putchar_fd_count(base[n], fd, count);
	}
	return (count);
}
