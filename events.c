/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:58:09 by aindjare          #+#    #+#             */
/*   Updated: 2024/06/10 13:13:34 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "library.h"
#include <X11/X.h>
#include <X11/keysym.h>

int	prog_close(t_state *state)
{
	if (!state || !state->mlx)
		return (1);
	mlx_loop_end(state->mlx);
	return (0);
}

#include <stdio.h>

int	prog_keypress(int key, t_state *state)
{
	if (key == XK_Escape)
		return (prog_close(state));
	if (key == XK_KP_Add)
		fractol_zoom_in(state);
	if (key == XK_KP_Subtract)
		fractol_zoom_out(state);
	// TODO: Protect overflow
	state->iterations += ((key == XK_k) - (key == XK_j)) * 8;
	state->render |= (key == XK_j || key == XK_k);
	return (0);
}

int	prog_mousepress(int key, int x, int y, t_state *state)
{
	(void)x;
	(void)y;
	if (state->render == 1)
		return (1);
	if (key == XK_SCROLL_UP)
		fractol_zoom_in(state);
	if (key == XK_SCROLL_DOWN)
		fractol_zoom_out(state);
	return (0);
}
