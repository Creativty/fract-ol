/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:40:20 by aindjare          #+#    #+#             */
/*   Updated: 2024/07/15 10:19:13 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	fractol_zoom_in(t_state *state)
{
	state->offset.real += ((float)SCREEN / 4.0f) / state->zoom;
	state->offset.imag += ((float)SCREEN / 4.0f) / state->zoom;
	state->zoom *= 2.0;
	state->render = 1;
}

void	fractol_zoom_out(t_state *state)
{
	if (state->zoom * 0.5 > 0.0001)
	{
		state->zoom *= 0.5;
		state->offset.real -= ((float)SCREEN / 4.0f) / state->zoom;
		state->offset.imag -= ((float)SCREEN / 4.0f) / state->zoom;
	}
	state->render = 1;
}
