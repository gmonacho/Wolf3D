/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_addint.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 18:19:54 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 18:56:10 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	*ft_addint(int *tab, int nbr, size_t length)
{
	int		*newtab;
	size_t	i;

	newtab = (int *)malloc(sizeof(int) * (length + 1));
	i = -1;
	while (++i < length)
		newtab[i] = tab[i];
	newtab[i] = nbr;
	return (newtab);
}
