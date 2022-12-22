/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:55:19 by engo              #+#    #+#             */
/*   Updated: 2022/12/22 21:23:28 by vloth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	char	*str;
	t_data	*data;
	t_cmd	*caca;

	(void)ac;
	(void)av;
	(void)env;
	str = NULL;
	while (1)
	{
		str = readline("mini> ");
		add_history(str);
		data = init_parsing(str);
		init_struct(str, data);
		if (cmd_trim(data))
			return (1);
		redir_all(data);
		caca = data->begin;
		while (caca != NULL)
		{
			printf("nb de r_in = %d\n", caca->r_in);
			printf("nb de r_out = %d\n", caca->r_out);
			printf("nb de rr_out = %d\n", caca->rr_out);
			printf("%s\n", caca->cmd);
			caca = caca->next;
		}
		//check_builtin(str, env);
		free_list(data);
		free(str);
	}
	rl_clear_history();
}
