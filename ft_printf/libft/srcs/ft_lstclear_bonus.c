/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 12:33:37 by tallaire          #+#    #+#             */
/*   Updated: 2019/12/23 11:14:15 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*tempnext;

	if (!(*lst) || !(*del))
		return ;
	temp = *lst;
	while (temp->next)
	{
		temp = *lst;
		(*del)(temp->content);
		tempnext = temp->next;
		free(temp);
		*lst = tempnext;
	}
}
