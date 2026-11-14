/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebajja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 19:24:51 by ebajja            #+#    #+#             */
/*   Updated: 2026/10/25 15:55:11 by ebajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_print_char(char c);
int	ft_print_add(void *pi);
int	ft_print_uphex(unsigned int num);
int	ft_print_lowhex(unsigned int num);
int	ft_print_num(int num);
int	ft_print_str(const char *str);
int	ft_print_uint(unsigned int num);
int	ft_printf(const char *s, ...);
int	ft_check_args(va_list *args, char c);

#endif
