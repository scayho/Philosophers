/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 05:46:42 by abelahce          #+#    #+#             */
/*   Updated: 2022/08/07 01:17:00 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleeping(t_philo *philo)
{
	printing("sleeping", philo, 1);
	dormir(philo->asgard->tsleep);
}

void	eating(t_philo	*philo)
{
	while (philo->total != philo->maxeated
		&& wakt () - philo->snak < philo->asgard->tdie)
	{
		pthread_mutex_lock(philo->shopsticks);
		printing("taking left shopstick", philo, 1);
		pthread_mutex_lock(philo->rshopsticks);
		printing("taking right shopstick", philo, 1);
		printing("eating", philo, 1);
		philo->snak = wakt();
		dormir(philo->teat);
		philo->total++;
		pthread_mutex_unlock(philo->shopsticks);
		pthread_mutex_unlock(philo->rshopsticks);
		if (philo->total == philo->maxeated)
		{
			philo->asgard->samy++;
			break ;
		}
		sleeping(philo);
		thinking(philo);
	}	
}

void	*philothing(void	*ptr)
{
	t_philo	*philo;

	philo = ptr;
	eating(philo);
	return (NULL);
}
