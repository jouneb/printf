/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:26:35 by jbouyer           #+#    #+#             */
/*   Updated: 2022/01/04 16:28:04 by jbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

size_t	ft_puthexap(unsigned long int nb)
{
	unsigned int nbr;
	char	*base;
	static size_t	t;

	t = 0;
	base = "0123456789abcdef";
	nbr = nb;
	t = 2;
	if (nb <= 15)
	{	
		write(1, "0x", 2);
		ft_putchar(base[nb]);
	}
	t++;
	if (nb > 15)
	{
		ft_puthexap(nb / 16);
		ft_putchar(base[nb % 16]);
		t++;
	}
	return (t);
}
size_t	ft_puthexamaj(unsigned int nb)
{
	long int nbr;
	char	*base;
	static size_t	t;

	t = 0;
	base = "0123456789ABCDEF";
	nbr = nb;
	if (nb <= 15)
		 ft_putchar(base[nb]);
	t++;
	if(nb > 15)
	{
		ft_puthexamaj(nb / 16);
		ft_putchar(base[nb % 16]);
		t++;
	}
	return (t);
}

size_t	ft_putunsignednbr(unsigned int nb)
{
	size_t					i;
	long unsigned int		nbr;

	i = 0;
	nbr = nb;
	if ( nbr <= 9)
		ft_putchar(nb + '0');
	if (nb > 9)
	{
		ft_putunsignednbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	return (ft_ucount(nb));
}

int	ft_count(int nb)
{
	int	i;
	long int nbr;

	i = 0;
	nbr = nb;
	if (nbr < 0)
	{
		i++;
		nbr = nbr * -1;
	}
	while( nbr > 9)
	{
		nbr = nbr / 10;
		i++;
	
	}
	i++;
	return (i);
}

int	ft_ucount(unsigned int nb)
{
	unsigned long int nbr;
	int	i;

	i = 0;
	nbr = nb;
	while( nbr > 9)
	{
		nbr = nbr / 10;
		i++;	
	}
	i++;
	return (i);
}
