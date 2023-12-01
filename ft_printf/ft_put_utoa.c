/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_utoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naser <Naser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 07:22:19 by Naser          #+#    #+#             */
/*   Updated: 2023/12/01 08:55:51 by Naser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	i_len(unsigned nb, size_t base_len)
{
	int	len;

	len = 0;
	while (nb > 0)
	{
		nb = nb / base_len;
		len++;
	}
	return (len);
}

static unsigned int	divide_by(unsigned int power, size_t base_len)
{
	unsigned int		result;

	result = 1;
	while (power > 1)
	{
		result *= base_len;
		power--;
	}
	return (result);
}

static void	populate(unsigned int nb, char *c_num, char *base)
{
	unsigned int		len;
	unsigned int		digit;
	unsigned int		i;
	size_t				base_len;

	base_len = ft_strlen(base);
	i = 0;
	digit = 0;
	len = i_len(nb, base_len);
	while (len > 0)
	{
		digit = (nb / divide_by(len, base_len));
		nb -= (digit * divide_by(len, base_len));
		c_num[i] = base[digit];
		i++;
		len--;
	}
	c_num[i] = '\0';
}

int	ft_put_utoa(unsigned int n, char *base)
{
	char			*ret;
	int				i;
	size_t			base_len;

	base_len = ft_strlen(base);
	i = 0;
	if (n == 0)
	{
		return (ft_putchar_int('0'));
	}
	ret = (char *)malloc((i_len(n, base_len) + 1) * sizeof(char));
	if (!ret)
		return (0);
	populate(n, ret, base);
	i = ft_putstr_int(ret);
	free(ret);
	return (i);
}
