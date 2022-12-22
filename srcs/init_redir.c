/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:04:58 by vloth             #+#    #+#             */
/*   Updated: 2022/12/22 21:25:21 by vloth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redir_in(t_cmd *com)
{
	int	i;

	i = -1;
	com->r_in = 0;
	while (com->cmd[++i])
	{
		if (com->cmd[i] == '<')
		{
			com->r_in = 1;
			return ;
		}
	}
}

void	redir_out(t_cmd *com)
{
	int	i;

	i = -1;
	com->rr_out = 0;
	com->r_out = 0;
	while (com->cmd[++i])
	{
		if (com->cmd[i] == '>')
		{
			if (com->cmd[i + 1] == '>')
			{
				i++;
				com->rr_out++;
			}
			else
				com->r_out++;
		}
	}
}

void	redir_all(t_data *l)
{
	t_cmd	*tmp;

	tmp = l->begin;
	while (tmp)
	{
		redir_in(tmp);
		redir_out(tmp);
		tmp = tmp->next;
	}
}
