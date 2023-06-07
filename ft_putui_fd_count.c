/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putui_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:41:40 by ryhara            #+#    #+#             */
/*   Updated: 2023/06/07 12:41:40 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putui_fd_count(unsigned int n, int fd, size_t count)
{
	if (n >= 10)
		count = ft_putui_fd_count(n / 10, fd, count);
	count = ft_putchar_fd_count((n % 10 + '0'), fd, count);
	return (count);
}
