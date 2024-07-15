/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:14:07 by aindjare          #+#    #+#             */
/*   Updated: 2024/07/15 10:40:36 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int	main(const int argc, const char **argv)
{
	int	mode;

	mode = prog_args(argc, argv);
	if (mode)
		return (prog_entry(argv, mode));
	return (1);
}
