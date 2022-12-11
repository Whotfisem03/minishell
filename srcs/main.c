/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:55:19 by engo              #+#    #+#             */
/*   Updated: 2022/12/11 15:08:31 by vloth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	char	*str;
	(void)ac;
	(void)av;
	(void)env;
	t_data	*data;

	str = NULL;
	while (1)
	{
		str = readline("mini> ");
		data = init_parsing(str);
		init_struct(str, data);
		t_cmd *caca;
		
		caca = data->begin;
		while (caca)
		{
			printf("%s\n", caca->cmd);
			caca = caca->next;
		}
		add_history(str);
		free_list(data);
	}
}
