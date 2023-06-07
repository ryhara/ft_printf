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

size_t	ft_putnbr_base(unsigned int n, char *base, size_t count)
{
	unsigned int	len;

	len = (int)ft_strlen(base);
	if (n >= len)
	{
		count = ft_putnbr_base((n / len), base, count);
		n %= len;
	}
	if (n < len)
	{
		count = ft_putchar_count(base[n], count);
	}
	return (count);
}
