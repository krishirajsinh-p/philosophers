/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 01:05:22 by kpuwar            #+#    #+#             */
/*   Updated: 2023/06/30 05:33:40 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, t_string argv[])
{
	t_args	args;

	if (check_args(argc, argv, &args) == false)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
//replace wildcard with filenames in makefile
