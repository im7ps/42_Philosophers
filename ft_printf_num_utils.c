/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:05:00 by sgerace           #+#    #+#             */
/*   Updated: 2022/11/25 19:22:22 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_print_int(long long int number)
{
	long long int	i;

	i = 0;
	if (number == -2147483648)
	{
		i += ft_putchar('-');
		i += ft_putchar('2');
		number = 147483648;
	}
	if (number < 0)
	{
		i += ft_putchar('-');
		number *= -1;
	}
	if (number >= 10)
	{
		i += ft_print_int(number / 10);
		i += ft_print_int(number % 10);
	}
	else
	{
		i += ft_putchar(48 + number);
	}
	return (i);
}

int	ft_print_ul_int(unsigned long long int number)
{
	long long int	i;

	i = 0;
	if (number >= 10)
	{
		i += ft_print_int(number / 10);
		i += ft_print_int(number % 10);
	}
	else
	{
		i += ft_putchar(48 + number);
	}
	return (i);
}
