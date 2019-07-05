/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:19:56 by blomo             #+#    #+#             */
/*   Updated: 2019/04/15 17:15:39 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *alst)
{
	if (!alst->content && !alst)
		return ;
	while (alst)
	{
		ft_putstr((char const *)alst->content);
		alst = alst->next;
	}
}
