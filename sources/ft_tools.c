/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 10:59:59 by jle-quel          #+#    #+#             */
/*   Updated: 2017/07/14 18:16:20 by jefferson        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int				ft_errno(int error)
{
	if (error == NO_ARGV)
		ft_putendl_fd("ft_select: Too few arguments.", 2);
	else if (error == NO_VAR)
		ft_putendl_fd("ft_select: Variable $TERM is not defined.", 2);
	else if (error == NO_ENTRY)
		ft_putendl_fd("ft_select: No such entry.", 2);
	else if (error == NO_DB)
		ft_putendl_fd("ft_select: Terminfo database could not be found.", 2);
	else if (error == NO_ID)
		ft_putendl_fd("ft_select: Numeric id is not available.", 2);
	else if (error == NO_STR)
		ft_putendl_fd("ft_select: String entry is not available.", 2);
	else if (error == NO_TMS)
		ft_putendl_fd("ft_select: Informations could not be found.", 2);
	else if (error == NO_SET)
		ft_putendl_fd("ft_select: Couldn't change value of struct termios.", 2);
	else if (error == NO_READ)
		ft_putendl_fd("ft_select: Error with function read", 2);
	else if (error == NO_CUR)
		ft_putendl_fd("ft_select: Couldn't use termcap function", 2);
	else if (error == NO_SIG)
		ft_putendl_fd("ft_select: Couldn't catch the signal", 2);
	return (-1);
}

t_list			*ft_populate_list(char **argv)
{
	size_t	index;
	t_list	*node;

	index = 1;
	node = ft_lstnew(argv[0], 0, ft_threejoin(SURLINE, argv[0], ENDLINE));
	while (argv[index])
	{
		ft_lstaddnext(&node, ft_lstnew(argv[index], 0,
		ft_threejoin(SURLINE, argv[index], ENDLINE)));
		index++;
	}
	return (node);
}

static void		ft_delete_node(t_list **node)
{
	t_list	*temp;

	temp = *node;
	ft_strdel(&temp->content);
	ft_strdel(&temp->color);
	free(temp);
	temp = NULL;
}

void			ft_delete_from_list(t_list **node, int height)
{
	int		index;
	t_list	*temp;
	t_list	*old;

	index = 0;
	temp = *node;
	if (height == 0)
	{
		*node = (*node)->next;
		ft_delete_node(&temp);
		return ;
	}
	while (temp)
	{
		old = temp;
		temp = temp->next;
		index++;
		if (index == height)
		{
			old->next = temp->next;
			ft_delete_node(&temp);
		}
	}
}

int				ft_longest_word(t_list *node)
{
	int		len;
	int		ret;
	t_list	*temp;

	len = 0;
	ret = 0;
	temp = node;
	while (temp)
	{
		len = ft_strlen(temp->color);
		if (ret < len)
			ret = len;
		temp = temp->next;
	}
	return (ret);
}
