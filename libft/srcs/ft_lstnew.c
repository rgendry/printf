/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 15:16:39 by blomo             #+#    #+#             */
/*   Updated: 2019/05/12 20:26:21 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new_lst;
	new_lst = (t_list *)malloc(sizeof(t_list));
	if (!new_lst)
		return (NULL);
	if (!(content))
	{
		new_lst->content = NULL;
		new_lst->content_size = 0;
	}
	else
	{
		if (!(new_lst->content = malloc(sizeof(content_size))))
		{
			ft_memdel((void **)&new_lst);
			return (NULL);
		}
		else
		{
			ft_memcpy(new_lst->content, content, content_size);
			new_lst->content_size = content_size;
		}
	}
	new_lst->next = NULL;
	return (new_lst);
}
