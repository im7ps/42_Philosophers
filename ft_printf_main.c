/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:13:42 by sgerace           #+#    #+#             */
/*   Updated: 2022/11/25 19:23:12 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_putchar(const char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *string)
{
	int	i;

	i = 0;
	if (!string)
		string = "(null)";
	while (string[i] != '\0')
	{
		write(1, &string[i], 1);
		i++;
	}
	return (i);
}

int	printf_switch(va_list list, const char *string)
{
	int	i;

	i = 0;
	if (string[i] == 's')
		i += ft_putstr(va_arg(list, char *));
	else if (string[i] == 'd' || string[i] == 'i')
		i += ft_print_int(va_arg(list, int));
	else if (string[i] == 'l')
		i += ft_print_ul_int(va_arg(list, unsigned long long int));
	return (i);
}

int	ft_printf(const	char *string, ...)
{
	va_list	list;
	int		i;
	int		len;

	va_start(list, string);
	i = 0;
	len = 0;
	while (string[i] != '\0' && string[i])
	{
		if (string[i] == '%')
		{
			i++;
			len += printf_switch(list, &string[i]);
		}
		else
			len += ft_putchar(string[i]);
		i++;
	}
	va_end(list);
	return (len);
}
