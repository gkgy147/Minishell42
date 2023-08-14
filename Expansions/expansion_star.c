/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_star.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobert <georgerobert147@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:19:52 by gkmon             #+#    #+#             */
/*   Updated: 2023/08/08 13:04:28 by grobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

int	ft_check_star(char *str)
{
	int	i;
	int	cont;
	int	quotes;

	i = -1;
	cont = 0;
	while (str[++i])
	{
		quotes = ft_getquotes(str, i);
		if (quotes)
			continue ;
		if (str[i] == 42 && !cont)
			cont++;
	}
	return (cont);
}

char	*ft_joiner_sep(char **strs, const char *sep)
{
	char	*str;
	char	*tmp;
	int		i;

	i = -1;
	str = NULL;
	while (strs[++i])
	{
		tmp = ft_strjoin(str, strs[i]);
		ft_free((void **)&str);
		if (!tmp)
			return (0);
		if (strs[i + 1])
		{
			str = ft_strjoin(tmp, sep);
			ft_free((void **)&tmp);
			if (!str)
				return (0);
		}
		if (tmp)
			str = tmp;
	}
	tmp = ft_strtrim(str, " ");
	ft_free((void **)&str);
	return (tmp);
}

/*
This function is used to perform wildcard character expansion 
on a single element of the parsed array. 
It checks for the presence of the '*' character and 
matches it with files in the current directory. 
If there are matching files, it updates the file string with 
the expanded result, otherwise, it sets the file to an empty string.
*/
void	ft_check_exp(char **str, char **file)
{
	int	i;
	int	k;

	k = 0;
	i = -1;
	while ((*str)[++i])
	{
		while ((*str)[i] && (*str)[i] == 42 && (*str)[i + 1] == 42)
			i++;
		while ((*str)[i] == 42 && (*file)[k] && ((*file)[k] != (*str)[i + 1]
				|| ((*str)[i + 1] && (*file)[k + 1] != (*str)[i + 2]
					&& (*str)[i + 2] != 42)))
			k++;
		if ((*str)[i] == 42)
			i++;
		if ((*str)[i] != (*file)[k] || !(*file)[k])
			break ;
		k++;
	}
	if ((*str)[i] != (*file)[k])
		(*file) = ft_strdup("") + ft_free_a(&(*file), 0);
}

/*
If the string has the '*' character and is not enclosed within quotes, 
it calls the ft_do_exp_star function with a pointer to the string. 
The ft_do_exp_star function performs file name expansion 
for that specific string, replacing the string 
with the expanded result if matches are found.
*/
int	ft_do_exp_star(char **str)
{
	char	**fs;
	int		j;

	fs = ft_readdir_star(*str[0], ".");
	if (!fs)
		return (0);
	j = -1;
	while (fs[++j])
		ft_check_exp(str, &fs[j]);
	j = 0;
	while (fs[j] && !fs[j][0])
		j++;
	if (!fs[j])
	{
		ft_free_mat((void ***)&fs);
		return (1);
	}
	ft_free((void **)str);
	(*str) = ft_joiner_sep(fs, " ");
	ft_free_mat((void ***)&fs);
	return (1);
}

/*
The ft_exp_star function performs file name expansion using the '*' 
wildcard character in the parsed array. 
It iterates through each element of the parsed array and 
checks for the presence of the '*' character. 
If found, it calls ft_parser to split the element into separate strings. 
For each resulting string, it checks for the '*' character and 
expands file names using ft_do_exp_star. 
Finally, it updates the parsed array with the expanded result.
*/
void	ft_exp_star(t_shell *sh)
{
	int	i;
	int	j;

	j = -1;
	sh->exp.strs[3] = 0;
	while (sh->parsed[++j])
	{
		if (!ft_check_star(sh->parsed[j]))
			continue ;
		sh->exp.pd = ft_parser(sh, sh->parsed[j], MC);
		if (!sh->exp.pd)
			ft_die(sh, 1, 12);
		i = -1;
		while (sh->exp.pd[++i])
		{
			if (!sh->exp.pd[i][0] || !ft_in(42, sh->exp.pd[i])
				|| ft_getquotes(sh->exp.pd[i], ft_strlen(sh->exp.pd[i]) - 1))
				continue ;
			if (!ft_do_exp_star(&(sh->exp.pd[i])))
				ft_die(sh, 1, 12);
		}
		ft_free((void **)&sh->parsed[j]);
		sh->parsed[j] = ft_joiner(sh->exp.pd, 0);
		ft_free_exp(&sh->exp);
	}
}
