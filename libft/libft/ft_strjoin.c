/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:15:45 by mtrullar          #+#    #+#             */
/*   Updated: 2024/06/24 14:36:28 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*result;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (free(s1), ft_strdup(s1));
	else
	{
		len_s1 = ft_strlen(s1);
		len_s2 = ft_strlen(s2);
		result = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
		if (!result)
			return (NULL);
		ft_strlcpy(result, s1, len_s1 + 1);
		ft_strlcpy(result + len_s1, s2, len_s1 + len_s2 + 1);
		free(s1);
	}
	return (result);
}
