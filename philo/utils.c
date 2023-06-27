/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 03:05:56 by kpuwar            #+#    #+#             */
/*   Updated: 2023/06/27 05:26:23 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	arg_format(void)
{
	printf("philo: illegal philo command\n");
	printf("usage:\t./philo <no_of_philo> \
<time_to_die> <time_to_eat> <time_to_sleep> \
[<no_of_times_each_philo_must_eat>]\n");
	printf("eg:\t./philo 2 410 200 200 10\n");
	return (false);
}

int	ft_atoi(t_string str)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\r' \
	|| str[i] == '\t' || str[i] == '\v' || str[i] == '\f')
			i++;
	if (str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
		n = (n * 10) + (str[i++] - '0');
	return (n);
}

bool	check_args(int argc, t_string *argv, t_data *data)
{
	int	i;
	int	arr[5];

	if (argc != 5 && argc != 6)
		return (arg_format());
	i = 0;
	while (i++ < argc)
	{
		arr[i] = ft_atoi(argv[i]);
		if (arr[i])
	}
	data->nb_philo = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		data->nb_eat = ft_atoi(argv[5]);
	return (true);
}
