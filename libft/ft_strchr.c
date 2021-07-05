/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:10:54 by srakuma           #+#    #+#             */
/*   Updated: 2021/07/05 01:05:00 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	ch;

	i = ft_strlen(s) + 1;
	ch = (unsigned char)c;
	while (i > 0)
	{
		if (*s == ch)
			return ((char *)s);
		i--;
		s++;
	}
	return (0);
}
