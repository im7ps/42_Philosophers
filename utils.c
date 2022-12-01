/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:19:10 by sgerace           #+#    #+#             */
/*   Updated: 2022/11/25 19:22:55 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(useconds_t time)
{
	u_int64_t	start;

	start = ft_get_time();
	while ((ft_get_time() - start) < time)
		usleep(time / 10);
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(char *)s1 - *(char *)s2);
}

void	ft_write(char *str, t_philo *philo)
{
	uint64_t	time;

	pthread_mutex_lock(&philo->t->printf);
	time = ft_get_time() - philo->t->time_zero;
	if (ft_strcmp(DEAD, str) && philo->t->dead_status == 0)
	{
		ft_printf("%l %d %s\n", time, philo->index, str);
	}
	if (!(ft_strcmp(DEAD, str)))
	{
		ft_printf("%l %d %s\n", time, philo->index, str);
	}
	pthread_mutex_unlock(&philo->t->printf);
}

long int	ft_get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (-1);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	ft_input_checker(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] <= '9' && argv[i][j] >= '0'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
