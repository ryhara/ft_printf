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

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>
# include <stdarg.h>

int	ft_printf(const char *, ...);

size_t	ft_putnbr_fd_count(int n, int fd, size_t count);
size_t	ft_putchar_fd_count(char c, int fd, size_t count);
size_t	ft_putstr_fd_count(char *s, int fd, size_t count);
size_t	ft_putui_fd_count(unsigned int num, int fd, size_t count);
size_t	ft_putnbr_base_fd_count(unsigned int n, char *base, int fd, size_t count);
size_t	ft_strlen(const char *s);

#endif