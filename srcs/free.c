/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:55:14 by vloth             #+#    #+#             */
/*   Updated: 2022/12/11 16:41:05 by vloth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*pop_front_dlist(t_data *l)
{
	t_cmd	*tmp;

	if (l->nbcmd == 1)
	{
		tmp = l->begin;
		//free(tmp->cmd);
		l->begin = NULL;
		l->end = NULL;
	}
	else if (l->nbcmd > 1)
	{

		tmp = l->begin;
		//free(tmp->cmd);
		l->begin = l->begin->next;
		l->begin->back = NULL;
		l->nbcmd--;
	}
	return (tmp);
}
	

void	free_list(t_data *l)
{
	t_cmd	*tmp;

	tmp = l->begin;
	while (tmp)
	{
		tmp = pop_front_dlist(l);
		free(tmp);
	}
	free(l);
}