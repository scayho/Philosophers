/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shinigami.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 07:19:29 by abelahce          #+#    #+#             */
/*   Updated: 2022/08/07 04:27:38 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo)
{
	printing("thinking about existens", philo, 1);
}

void	chinigami(t_data *midgard)
{
	int			i;
	long long	now;

	while (1)
	{
		i = 0;
		while (i < midgard->nb_philo)
		{
			if (midgard->samy == midgard->nb_philo)
			{
				pthread_mutex_lock(&midgard->ccall);
				return ;
			}
			now = wakt();
			if (now - midgard->philo[i].snak > midgard->tdie
				&& midgard->philo[i].snak != -1)
			{
				printing("DEATH", &midgard->philo[i], 0);
				midgard->death = 1;
				return ;
			}
			i++;
		}
	}
}
