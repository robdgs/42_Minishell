/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfalchi <tfalchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by tfalchi           #+#    #+#             */
/*   Updated: 2024/09/02 10:58:30 by tfalchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	i;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	i = 0;
	if (size <= len_dst)
		return (size + len_src);
	while (src[i] != '\0' && len_dst + i < size - 1)
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}
/*#include <stdio.h>

int main() {
    char destination[200] = "Hello, ";
    const char *source = "world!";
    size_t result;

    result = ft_strlcat(destination, source, sizeof(destination));

    printf("Concatenated string: %s\n", destination);
    printf("Total length: %zu\n", result);

    return 0;
}
*/
