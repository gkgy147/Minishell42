/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_in_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkmon <gkmon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:41:33 by gkmon             #+#    #+#             */
/*   Updated: 2023/06/20 15:38:02 by gkmon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
/*
NAME: is the name of the variable you want to search
LVL: is the number of the subshell where you want to search the variable
RETURN
returns the pointer to the node of the variable at the level lvl,
if there's not the level you are searching for it will return the
closest smaller level to lvl. If the name is not in the list, return
value will be 0
*/
t_env	*ft_search_in_list(t_list *list, char *name, int lvl)
{
	t_env	*tmp;

	if (!list || !list->content)
		return (NULL);
	while (list->next && (ft_strncmp(list->content->name, name, ft_strlen(name))
			|| ft_strlen(name) != ft_strlen(list->content->name) - 1))
		list = list->next;
	if (ft_strncmp(list->content->name, name, ft_strlen(name))
		|| ft_strlen(name) != ft_strlen(list->content->name) - 1)
		return (NULL);
	tmp = list->content;
	while (tmp && tmp->next && tmp->level != lvl)
		tmp = tmp->next;
	if (tmp && tmp->level > lvl)
		return (NULL);
	return (tmp);
}
