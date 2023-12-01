/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naser <Naser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 08:03:52 by Naser          #+#    #+#             */
/*   Updated: 2023/12/01 08:56:06 by Naser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	i_len(size_t nb)
{
	int	len;

	len = 0;
	while (nb > 0)
	{
		nb = nb / 16;
		len++;
	}
	return (len);
}

static size_t	divide_by(size_t power)
{
	size_t		result;

	result = 1;
	while (power > 1)
	{
		result *= 16;
		power--;
	}
	return (result);
}

static void	populate(size_t nb, char *c_num, char *base)
{
	size_t		len;
	size_t		digit;
	size_t		i;
	size_t		base_len;

	base_len = 16;
	i = 0;
	digit = 0;
	len = i_len(nb);
	while (len > 0)
	{
		digit = (nb / divide_by(len));
		nb -= (digit * divide_by(len));
		c_num[i] = base[digit];
		i++;
		len--;
	}
	c_num[i] = '\0';
}

int	ft_putptr(size_t n, char *base)
{
	char				*ret;
	int					len;

	len = 0;
	if (n == 0 || !n)
	{
		return (ft_putstr_int("0x0"));
	}
	ret = (char *)malloc((i_len(n) + 1) * sizeof(char));
	if (!ret)
		return (0);
	populate(n, ret, base);
	len = ft_putstr_int("0x");
	len += ft_putstr_int(ret);
	free(ret);
	return (len);
}
