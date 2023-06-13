/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:45:50 by ryhara            #+#    #+#             */
/*   Updated: 2023/06/06 12:45:50 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);

size_t	ft_putnbr_count(int n, size_t count);
size_t	ft_putchar_count(char c, size_t count);
size_t	ft_putstr_count(char *s, size_t count);
size_t	ft_putui_count(unsigned int num, size_t count);
size_t	ft_putnbr_base(unsigned long n, char *base, size_t count);
size_t	ft_putaddress(unsigned long n, char *base, size_t count);
size_t	ft_strlen(const char *s);

#endif