/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:38:29 by aindjare          #+#    #+#             */
/*   Updated: 2024/06/10 10:53:54 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "library.h"

t_complex	complex_new(long double real, long double imag)
{
	return ((t_complex){real, imag});
}

t_complex	complex_add(t_complex lhs, t_complex rhs)
{
	return ((t_complex){lhs.real + rhs.real, lhs.imag + rhs.imag});
}

t_complex	complex_conjugate(t_complex x)
{
	return ((t_complex){x.real, -x.imag});
}

double	complex_mod(t_complex x)
{
	return (sqrt(x.real * x.real + x.imag * x.imag));
}

t_complex	complex_square(t_complex x)
{
	double	real;
	double	imag;

	real = (x.real * x.real) - (x.imag * x.imag);
	imag = 2.0 * x.real * (x.imag);
	return ((t_complex){real, imag});
}
