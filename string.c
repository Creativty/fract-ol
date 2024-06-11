/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 10:18:19 by aindjare          #+#    #+#             */
/*   Updated: 2024/06/10 10:23:24 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	string_len(const char *str)
{
	int	i;

	i = 0;
	if (str)
		while (str[i])
			i++;
	return (i);
}

int	string_count(const char *str, const char c)
{
	int	i;
	int	count;
	
	i = 0;
	count = 0;
	if (str)
		while (str[i])
		{
			if (str[i] == c)
				count++;
			i++;
		}
	return (count);
}

int	string_index(const char *str, const char c)
{
	int	i;

	i = 0;
	if (str)
		while (str[i])
		{
			if (str[i] == c)
				return (i);
			i++;
		}
	return (-1);
}

int	string_match(const char *lhs, const char *rhs)
{
	int	i;

	i = 0;
	if (lhs && rhs)
		while (lhs[i] == rhs[i])
		{
			if (lhs[i] == '\0')
				return (1);
			i++;
		}
	return (0);
}
