/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:56:58 by sgerace           #+#    #+#             */
/*   Updated: 2022/11/25 18:31:25 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_t	t;

	if (argc != 5 && argc != 6)
		return (1);
	if (ft_input_checker(argc, argv))
		return (1);
	if (ft_constructor(&t, argc, argv))
		return (1);
	if (t.philo_n == 1)
	{
		if (ft_lonely_philo(&t.phs[0]))
			return (1);
		return (0);
	}
	if (ft_start_routine(&t))
		return (1);
	if (ft_free_stuff(&t))
		return (1);
	return (0);
}
