/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 00:43:43 by kpuwar            #+#    #+#             */
/*   Updated: 2023/07/10 01:22:25 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	t_time	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

t_time	current_time(void)
{
	static t_time	start;

	if (start == 0)
	{
		start = get_time();
		return (start);
	}
	return (get_time() - start);
}

void	ft_usleep(t_time sleep_time)
{
	t_time	start;

	start = get_time();
	while ((get_time() - start) < sleep_time)
		usleep(10);
}

void	print(t_philo *philo, t_string str)
{
	pthread_mutex_lock(&philo->data->print);
	if (philo->data->all_alive == true && philo->data->meals_done == false)
		printf("%lli %u %s\n", current_time(), philo->id, str);
	pthread_mutex_unlock(&philo->data->print);
}

void	error_fn(unsigned short errorno)
{
	if (errorno == ARGS_ERR)
	{
		printf("philo: illegal philo command\n");
		printf("usage:\t./philo <no_of_philo> <time_to_die> <time_to_eat> \
<time_to_sleep> [<no_of_times_each_philo_must_eat>]\n");
		printf("eg:\t./philo 2 410 200 200 10\n");
		printf("\nno_of_philo should be between 1 and 200\n");
		printf("<time_to_*> should be in milliseconds and 60+\n");
		printf("<nb_times_each_philo_must_eat> is optional, should be 0+\n");
	}
	else if (errorno == MALLOC_ERR)
		printf("malloc error: failed to allocate memory\n");
	else if (errorno == MUTEX_INIT_ERR)
		printf("pthread_mutex_init error: failed to initialize mutex(es)\n");
	else if (errorno == PTHREAD_CREATE_ERR)
		printf("pthread_create error: failed to create thread(s)\n");
	else if (errorno == PTHREAD_JOIN_ERR)
		printf("pthread_join error: failed to join thread(s)\n");
	else if (errorno == MUTEX_DESTROY_ERR)
		printf("pthread_mutex_destroy error: failed to destroy mutex(es)\n");
}
