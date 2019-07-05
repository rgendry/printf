/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:43:13 by blomo             #+#    #+#             */
/*   Updated: 2019/04/15 17:16:02 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *alst)
{
	int		i;
	t_list	*temp;

	i = 0;
	if (!alst)
		return (i);
	temp = alst;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
