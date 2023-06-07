/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 08:12:21 by ryhara            #+#    #+#             */
/*   Updated: 2023/05/19 08:12:21 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putstr_fd_count(char *s, int fd, size_t count)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
		count++;
	}
	return (count);
}
