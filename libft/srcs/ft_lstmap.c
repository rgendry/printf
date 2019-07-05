/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 15:09:12 by blomo             #+#    #+#             */
/*   Updated: 2019/04/15 14:41:26 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ptr;
	t_list *out;

	if (!lst || !f)
		return (NULL);
	out = ft_lstmap(lst->next, f);
	ptr = f(lst);
	if (!ptr)
		return (out);
	if (!out)
		return (ptr);
	ptr->next = out;
	return (ptr);
}
