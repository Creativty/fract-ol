/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 10:06:07 by aindjare          #+#    #+#             */
/*   Updated: 2024/06/10 11:14:04 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

static int	char_is_space(const char c)
{
	return (c == ' '
		|| c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v');
}

static int	char_is_digit(const char c)
{
	return (c >= '0' && c <= '9');
}

static double	atof_mantissa(const char *a, double value)
{
	double	power;

	power = 10.0;
	while (char_is_digit(*a))
	{
		value += (*a - '0') / power;
		power *= 10.0;
		a++;
	}
	return (value);
}

/* http://www.leapsecond.com/tools/fast_atof.c */
double	atof(const char *a)
{
	double	sign;
	double	value;

	if (!a)
		return (0.0);
	while (char_is_space(*a))
		a++;
	sign = 1.0;
	if (*a == '-')
		sign = -1.0;
	if (*a == '-' || *a == '+')
		a++;
	while (char_is_digit(*a))
		value = value * 10.0 + (*(a++) - '0');
	if (*a == '.')
		value = atof_mantissa(++a, value);
	return (value);
}

double	atof_form_check(const char *a)
{
	int	i;

	i = 0;
	while (char_is_space(a[i]))
		i++;
	if (a[i] == '-' || a[i] == '+')
		i++;
	while (char_is_digit(a[i]))
		i++;
	if (a[i] == '.')
	{
		i++;
		while (char_is_digit(a[i]))
			i++;
	}
	return (a[i] == '\0');
}
