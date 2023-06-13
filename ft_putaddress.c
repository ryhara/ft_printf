/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:44:38 by ryhara            #+#    #+#             */
/*   Updated: 2023/06/13 17:44:38 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putaddress(unsigned long n, char *base, size_t count)
{
	count = ft_putstr_count("0x", count);
	count = ft_putnbr_base(n, base, count);
	return (count);
}
