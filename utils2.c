/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:22:06 by sgerace           #+#    #+#             */
/*   Updated: 2022/11/25 19:25:50 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int		res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + (str[i++] - '0');
	return (res * sign);
}

int	ft_free_stuff(t_t *t)
{
	int	i;

	i = -1;
	while (++i < t->philo_n)
	{
		pthread_mutex_destroy(&t->phs[i].lock);
		pthread_mutex_destroy(&t->forks[i]);
	}
	pthread_mutex_destroy(&t->printf);
	pthread_mutex_destroy(&t->lock);
	pthread_mutex_destroy(&t->dead);
	free(t->p_t);
	free(t->forks);
	free(t->phs);
	return (0);
}

int	ft_lonely_philo(t_philo *philo)
{
	printf("0 1 has taken a fork\n");
	ft_usleep(philo->time_to_die);
	ft_printf("%l 1 is dead\n", philo->time_to_die);
	return (0);
}
