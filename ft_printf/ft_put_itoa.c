/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Naser <Naser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 07:25:20 by Naser          #+#    #+#             */
/*   Updated: 2023/12/01 07:48:29 by Naser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	i_len(long long nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
		return (11);
	else if (nb < 0)
	{
		len++;
		nb *= -1;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static int	divide_by(unsigned int power)
{
	unsigned int		result;

	result = 1;
	while (power > 1)
	{
		result *= 10;
		power--;
	}
	return (result);
}

static void	populate(unsigned int nb, char *c_num)
{
	unsigned int		len;
	unsigned int		digit;
	unsigned int		i;

	i = 0;
	digit = 0;
	len = i_len(nb);
	while (len > 0)
	{
		digit = (nb / divide_by(len));
		nb -= (digit * divide_by(len));
		c_num[i] = digit + 48;
		i++;
		len--;
	}
	c_num[i] = '\0';
}

int	ft_put_itoa(int n)
{
	char	*ret;
	int		len;

	len = 0;
	if (n == 0)
	{
		return (ft_putchar_int('0'));
	}
	ret = (char *)malloc((i_len(n) + 1) * sizeof(char));
	if (!ret)
		return (0);
	if (n < 0)
	{
		ret[0] = '-';
		populate(-1 * n, ret + 1);
	}
	else
		populate(n, ret);
	len = ft_putstr_int(ret);
	free(ret);
	return (len);
}
