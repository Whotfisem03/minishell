/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 01:56:12 by engo              #+#    #+#             */
/*   Updated: 2022/12/13 01:15:57 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pipe_or_not(char *str)
{
	int	i;
	int pipe;

	pipe = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '|')
		{
			if (str[i + 1] == 0)
				return (-1);
			if (str[i + 1] == '|')
			{
				if (str[i + 1] == 0)
					return (-1);
				i++;
			}
			pipe++;
		}
	}
	return (pipe);
}

t_data	*init_parsing(char *str)
{
	t_data	*init;

	init = malloc(sizeof(*init));
	if (!init)
		return (NULL);
	init->nbpipe = pipe_or_not(str);
	init->nbcmd = init->nbpipe + 1;
	init->len = 0;
	init->begin = NULL;
	init->end = NULL;
	return (init);
}

void	init_cmd(t_data *data, char *str)
{
	t_cmd	*tmp;

	tmp = malloc(sizeof(t_cmd));
	if (!tmp)
		return ;
	if (data->len == 0)
	{
		data->len++;
		tmp->cmd = str;
		data->begin = tmp;
		data->end = tmp;
		tmp->back = NULL;
		tmp->next = NULL;
	}
	else if (data->nbcmd > 1 && data->len >= 1)
	{
		data->len++;
		tmp->cmd = str;
		data->end->next = tmp;
		tmp->back = data->end;
		data->end = tmp;
	}
}

void	init_struct(char *str, t_data *data)
{
	int	i;
	char	**cmd_pipe;

	i = -1;
	if (data->nbcmd == -1 || data->nbcmd == 0)
		return ;
	else if (data->nbcmd == 1)
		init_cmd(data, str);
	else if (data->nbcmd > 1)
	{
		cmd_pipe = ft_split(str, '|');
		while (cmd_pipe[++i])
			init_cmd(data, cmd_pipe[i]);	
	}
}