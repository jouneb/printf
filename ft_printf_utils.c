/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:26:35 by jbouyer           #+#    #+#             */
/*   Updated: 2022/01/03 15:08:35 by jbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
size_t	ft_puthexap(unsigned long int nb)
{
	unsigned int nbr;
	char	*base;
	size_t	t;

	t = 0;
	base = "0123456789abcdef";
	nbr = nb;
//	write(1, "0x", 2);
	if (nb <= 15)
	{	
		write(1, "0x", 2);
		t = t + ft_putchar(base[nb]);
	}
	if(nb > 15)
	{
		ft_puthexap(nb / 16);
		t = t + ft_putchar(base[nb % 16]);
	}
	return (t);
}
size_t	ft_puthexamaj(unsigned int nb)
{
	unsigned int nbr;
	char	*base;
	size_t	t;

	t = 0;
	base = "0123456789ABCDEF";
	nbr = nb;
	if (nb <= 15)
		t = t + ft_putchar(base[nb]);
	if(nb > 15)
	{
		ft_putnbrhexa(nb / 16);
		t = t + ft_putchar(base[nb % 16]);
	}
	return (t);
}

size_t	ft_putunsignednbr(unsigned int nb)
{
	size_t		i;
	size_t		t;
	long int	nbr;

	i = 0;
	t = 0;
	nbr = nb;
	if (nbr > 0 && nbr <= 9)
		t = t + ft_putchar(nb + '0');
	if (nb > 9)
	{
		ft_putunsignednbr(nb / 10);
		t = t + ft_putchar(nb % 10 + '0');
	}
	return (t);
}
