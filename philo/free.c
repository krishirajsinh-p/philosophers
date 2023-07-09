/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:52:35 by kpuwar            #+#    #+#             */
/*   Updated: 2023/07/09 15:17:42 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	join_threads(t_data *data)
{
	t_philo			*philo;
	unsigned int	i;

	philo = data->philo;
	i = 0;
	while (i < data->nb_philo)
		if (pthread_join(philo[i++].thread, NULL))
			return (error_fn(PTHREAD_JOIN_ERR), false);
	return (true);
}

bool	free_data(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->nb_philo)
		if (pthread_mutex_destroy(&data->forks[i++]))
			return (error_fn(MUTEX_DESTROY_ERR), false);
	free(data->philo);
	free(data->forks);
	return (true);
}
