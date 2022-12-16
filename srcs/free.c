/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:55:14 by vloth             #+#    #+#             */
/*   Updated: 2022/12/16 20:58:12 by vloth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*pop_front_dlist(t_data *l)
{
	t_cmd	*tmp;

	if (l->len == 1)
	{
		l->len--;
		tmp = l->begin;
		l->begin = NULL;
		l->end = NULL;
	}
	else if (l->len > 1)
	{
		l->len--;
		tmp = l->begin;
		l->begin = l->begin->next;
		l->begin->back = NULL;
		l->nbcmd--;
	}
	return (tmp);
}


void	free_list(t_data *l)
{
	t_cmd	*prout;

	while (l->len)
	{
		prout = pop_front_dlist(l);
		free(prout);
	}
	free(l);
}
