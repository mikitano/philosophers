/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 16:19:07 by mkitano           #+#    #+#             */
/*   Updated: 2025/12/07 17:47:38 by mkitano          ###   ########.fr       */
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

long	ft_atol(const char *str)
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

/*static bool	valid_input(const char *str)
{
	while (is_space(*str))
		++str;
	if (*str == '+')
		++str;
	else if (*str == '-')
		return (false);
	if (!is_digit(*str))
		return (false);
	return (true);
}
long	ft_atol(const char *str)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || (str[i] == ' '))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-' || !ft_is_number(str))
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result);
}

bool	ft_is_number(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (false);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (false);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (false);
		i++;
	}
	return (true);
}*/
