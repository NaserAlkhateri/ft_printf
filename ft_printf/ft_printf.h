/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naser <Naser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:02:48 by Naser          #+#    #+#             */
/*   Updated: 2023/12/01 09:06:04 by Naser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_putptr(size_t n, char *base);
int		ft_put_itoa(int n);
int		ft_put_utoa(unsigned int n, char *base);
int		ft_putchar_int(char c);
int		ft_putptr(size_t n, char *base);
int		ft_putstr_int(char *s);
size_t	ft_strlen(const char *s);

#endif