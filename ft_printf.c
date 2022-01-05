/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 08:03:05 by jbouyer           #+#    #+#             */
/*   Updated: 2022/01/05 11:50:06 by jbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

size_t	ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

size_t	ft_putnbrhexa(unsigned int nb)
{
	long int			nbr;
	char				*base;
	static size_t		t;

	t = 0;
	base = "0123456789abcdef";
	nbr = nb;
	if (nb <= 15)
		ft_putchar(base[nb]);
	t++;
	if (nb > 15)
	{
		ft_putnbrhexa(nb / 16);
		ft_putchar(base[nb % 16]);
		t++;
	}
	return (t);
}

size_t	ft_putnbr(int nb)
{
	size_t		i;
	long int	nbr;

	i = 0;
	nbr = nb;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = nbr * -1;
	}
	if (nbr >= 0 && nbr <= 9)
		ft_putchar(nbr + '0');
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putchar(nbr % 10 + '0');
	}
	return (ft_count(nb));
}

size_t	ft_printarg(char c, va_list args)
{
	size_t	t;

	t = 0;
	if (c == 'c')
		t = ft_putchar(va_arg(args, int));
	else if (c == 's')
		t = ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		t = ft_puthexap(va_arg(args, unsigned long int));
	else if (c == 'd')
		t = ft_putnbr(va_arg(args, long int));
	else if (c == 'i')
		t = ft_putnbr(va_arg(args, long int));
	else if (c == 'u')
		t = ft_putunsignednbr(va_arg(args, unsigned int));
	else if (c == 'x')
		t = ft_putnbrhexa(va_arg(args, unsigned int));
	else if (c == 'X')
		t = ft_puthexamaj(va_arg(args, unsigned int));
	return (t);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	size_t	t;

	va_start(args, str);
	i = 0;
	t = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c' || str[i] == 's' || str[i] == 'p' || str[i] == 'd'
				|| str[i] == 'u' || str[i] == 'i' || str[i] == 'x'
				|| str[i] == 'X')
				t = t + ft_printarg(str[i], args);
			else
				t = t + write(1, &str[i], 1);
		}
		else
			t = t + write (1, &str[i], 1);
		i++;
	}
	va_end (args);
	return (t);
}

/*int main ()
{
	int p[] = {1232};
	//printf("%d\n",printf("%s\n", "jesuiscorrect"));
//	printf("%d\n",ft_printf("%s\n", "jesuiscorrect"));
  // printf("%c\n", '0');
   //printf("%d\n",printf("%c", '-256'));
  // printf("%c", '-256');
//   ft_printf("%c\n", '0');
   //printf("%d\n",ft_printf("%c", '-256'));
  //ft_printf("%c", '-256');
//	ft_printf("c = %c\n",'a');
//	printf("c = %c\n",'a');
//	ft_printf(" %d\n", 1789);
	printf(" %x\n", -2);
	printf("%d\n",printf(" %x\n", -2));
	ft_printf(" %x\n ", -2);
	printf("%d\n",ft_printf(" %x ", -2));
//	printf(" %d\n", -14);
//	printf("%d\n",printf(" %d\n", -14));
//	ft_printf(" %d\n ", -14);
//	printf("%d\n",ft_printf(" %d ", -14));
//	ft_printf(" %i\n", );
//	ft_printf(" %i\n", );
//	printf(" %i\n", 1984);
//	ft_printf("%%\n");
//	printf("%%\n");
}*/
