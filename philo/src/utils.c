/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 16:19:07 by mkitano           #+#    #+#             */
/*   Updated: 2025/12/21 16:09:28 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static bool	is_space(char c)
{
	if ((c >= '\t' && c <= '\r') || (c == ' '))
		return (true);
	return (false);
}

long	ft_atol(char *str)
{
	long	result;

	result = 0;
	while (is_space(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		return (0);
	if (!is_digit(*str))
		return (0);
	while (is_digit(*str))
	{
		result = (result * 10) + (*str - '0');
		if (result > INT_MAX)
			return (0);
		str++;
	}
	if (*str != '\0')
		return (0);
	return (result);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	len;

	if (size == 0 || count == 0)
		return (malloc(1));
	if (size && count > (size_t)-1 / size)
		return (NULL);
	len = count * size;
	mem = malloc(len);
	if (!mem)
		return (NULL);
	while (len--)
		((unsigned char *)mem)[len] = '\0';
	return (mem);
}

time_t	time_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1e3 + time.tv_usec / 1e3);
}
