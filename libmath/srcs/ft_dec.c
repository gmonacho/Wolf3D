/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dec.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/17 04:36:14 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/17 04:37:39 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libmath.h"

double	ft_dec(double nbr)
{
	return (ft_modulo(nbr, 1));
}
