/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 15:00:48 by blomo             #+#    #+#             */
/*   Updated: 2019/04/15 14:40:11 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *ptr;
	t_list *ptr1;

	if (!alst || !*alst || !del)
		return ;
	ptr = *alst;
	while (ptr)
	{
		ptr1 = ptr;
		del((ptr)->content, (ptr)->content_size);
		free(ptr);
		ptr = ptr1->next;
	}
	*alst = NULL;
}
