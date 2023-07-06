/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paser.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 03:05:56 by kpuwar            #+#    #+#             */
/*   Updated: 2023/06/30 05:33:16 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	arg_error_msg(void)
{
	printf("philo: illegal philo command\n");
	printf("usage:\t./philo <no_of_philo> <time_to_die> <time_to_eat> \
<time_to_sleep> [<no_of_times_each_philo_must_eat>]\n");
	printf("eg:\t./philo 2 410 200 200 10\n");
	printf("\nno_of_philo should be between 1 and 200\n");
	printf("<time_to_*> should be in milliseconds and 60+\n");
	printf("<no_of_times_each_philo_must_eat> is optional but should be 0+\n");
	return (false);
}

static int	ft_atoi(t_string str)
{
	int				num;
	unsigned int	i;

	num = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\r' \
	|| str[i] == '\t' || str[i] == '\v' || str[i] == '\f')
			i++;
	if (str[i] == '+')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
		num = (num * 10) + (str[i++] - '0');
	return (num);
}

bool	check_args(int argc, t_string *argv, t_args *args)
{
	if (argc != 5 && argc != 6)
		return (arg_error_msg());
	args->nb_philo = ft_atoi(argv[1]);
	if (args->nb_philo < 1 || args->nb_philo > 100)
		return (arg_error_msg());
	args->die_time = ft_atoi(argv[2]);
	if (args->die_time < 60)
		return (arg_error_msg());
	args->eat_time = ft_atoi(argv[3]);
	if (args->eat_time < 60)
		return (arg_error_msg());
	args->sleep_time = ft_atoi(argv[4]);
	if (args->sleep_time < 60)
		return (arg_error_msg());
	if (argv[5])
	{
		args->nb_eat = ft_atoi(argv[5]);
		if (args->nb_eat < 1)
			return (arg_error_msg());
	}
	else
		args->nb_eat = -1;
	return (true);
}
