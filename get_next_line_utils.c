/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 23:59:22 by srakuma           #+#    #+#             */
/*   Updated: 2021/06/30 15:23:31 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup_for_gnl(const char *s1)
{
	size_t	len;
	int		i;
	char	*str;

	if (!s1)
		return (0);
	len = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	i = -1;
	while (++i < (int)len)
		str[i] = s1[i];
	str[i] = '\0';
	return (str);
}

char	*ft_substr_for_gnl(char const *start, char const *end)
{
	char	*ptr;
	char	*tmp;
	int		len;
	int		i;

	if (!start || !end)
		return (0);
	len = 0;
	tmp = (char *)start;
	while (tmp++ != end)
		len++;
	ptr = (char *)malloc(sizeof(char) * len + 1);
	if (ptr == 0)
		return (0);
	i = -1;
	while (++i < (int)len)
		ptr[i] = start[i];
	ptr[i] = '\0';
	return (ptr);
}
