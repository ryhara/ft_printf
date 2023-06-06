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

int	ft_printf(const char *s, ...)
{
	va_list	args;
	size_t	s_len;

	va_start(args, s);
	if (s == NULL)
		return (-1);
	//処理
	va_end(args);
	return ((int)s_len);
}