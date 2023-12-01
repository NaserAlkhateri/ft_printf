/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naser <Naser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 07:23:51 by Naser          #+#    #+#             */
/*   Updated: 2023/12/01 09:27:57 by Naser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_int(char *s)
{
	int		len;

	len = 0;
	if (s)
	{
		while (*s)
		{
			len += ft_putchar_int(*s);
			s++;
		}
	}
	else
	{
		len = ft_putstr_int("(null)");
	}
	return (len);
}
