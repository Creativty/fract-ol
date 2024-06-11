/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:42:21 by aindjare          #+#    #+#             */
/*   Updated: 2024/06/10 11:43:55 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	math_max(double *list, int elem_count)
{
	int		i;
	double	max;

	i = 0;
	if (!list || !elem_count)
		return (0.0);
	while (i < elem_count)
	{
		if (i == 0 || list[i] > max)
			max = list[i];
		i++;
	}
	return (max);
}

double	math_min(double *list, int elem_count)
{
	int		i;
	double	min;

	i = 0;
	if (!list || !elem_count)
		return (0.0);
	while (i < elem_count)
	{
		if (i == 0 || list[i] < min)
			min = list[i];
		i++;
	}
	return (min);
}
