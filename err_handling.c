/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:52:00 by ahassan           #+#    #+#             */
/*   Updated: 2023/03/11 16:04:13 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int syntax_err(t_infra *shell)
{
	if(!right_quotes(shell->trim_rd))
		return(printf("error quoets\n"), 0);
	if(!check_redirect(shell->trim_rd))
		return(printf("error redirect\n"), 0);
	if(!check_pipes(shell->trim_rd))
		return(printf("error pipe\n"), 0);	
	return 1;		
}
