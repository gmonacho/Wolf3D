/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ed_put_map.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 11:24:44 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/17 20:51:32 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

static void		ed_draw_tile(t_win *win, SDL_Texture **texture, int i, int j)
{
	SDL_Rect	rect;

	if (win->map.tab[i][j] != 0)
	{
		rect = (SDL_Rect){
				j * win->map.unit - (int)(win->editor.pos.x),
				i * win->map.unit - (int)(win->editor.pos.y),
				win->map.unit, win->map.unit};
		SDL_RenderCopy(win->rend, texture[win->map.tab[i][j] - 1], NULL, &rect);
	}
}

int				ed_put_map(t_win *win)
{
	int		imax;
	int		jmax;
	int		i;
	int		j;

	i = win->editor.pos.y / win->map.unit;
	if (i < 0)
		i = 0;
	j = win->editor.pos.x / win->map.unit;
	imax = i + 2 + win->height / win->map.unit;
	jmax = j + 2 + win->width / win->map.unit;
	while (i < imax && i < win->map.len_y)
	{
		j = win->editor.pos.x / win->map.unit;
		if (j < 0)
			j = 0;
		while (j < jmax && j < win->map.len_x)
		{
			ed_draw_tile(win, win->textures.ttab, i, j);
			j++;
		}
		i++;
	}
	return (1);
}
