/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ed_map_ui.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/08 20:41:13 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/14 17:51:53 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

int				ed_init_map_ui(t_win win, t_ui *map_ui, Uint32 *map_ui_color)
{
	int			lx;
	int			ly;
	int			u;

	lx = win.map.len_x;
	ly = win.map.len_y;
	u = win.map.unit;
	map_ui[ED_TDRAG] = ed_new_map_ui((t_rect){-1, -1, lx + 2, 1}, ED_TDRAG);
	map_ui_color[ED_TDRAG] = 0x88888800 + COLOR_OFF;
	map_ui[ED_RDRAG] = ed_new_map_ui((t_rect){lx, -1, 1, ly + 2}, ED_RDRAG);
	map_ui_color[ED_RDRAG] = 0x88888800 + COLOR_OFF;
	map_ui[ED_BDRAG] = ed_new_map_ui((t_rect){-1, ly, lx + 2, 1}, ED_BDRAG);
	map_ui_color[ED_BDRAG] = 0x88888800 + COLOR_OFF;
	map_ui[ED_LDRAG] = ed_new_map_ui((t_rect){-1, -1, 1, ly + 2}, ED_LDRAG);
	map_ui_color[ED_LDRAG] = 0x88888800 + COLOR_OFF;
	return (1);
}

t_ui			ed_new_map_ui(t_rect rect, int flag)
{
	t_ui		new_map_ui;

	new_map_ui.rect = rect;
	new_map_ui.flag = flag;
	return (new_map_ui);
}

void			ed_update_map_ui_color(Uint32 *map_ui_color, int flag)
{
	size_t		i;
	Uint32		*pcolor;

	i = 0;
	while (i < NB_MAP_UI)
	{
		pcolor = &map_ui_color[i];
		if ((int)i == flag)
			*pcolor = (*pcolor << 8) | COLOR_ON;
		else
			*pcolor = (*pcolor << 8) | COLOR_OFF;
		i++;
	}
}

int				ed_get_map_ui(t_dot_2d mpos, t_win *win, t_ui *map_ui)
{
	t_dot_2d	wp;
	int			u;
	t_rect		r;
	size_t		i;

	wp = win->editor.pos;
	u = win->map.unit;
	i = 0;
	while (i < NB_MAP_UI)
	{
		r = map_ui[i].rect;
		if (mpos.x >= -wp.x + r.x * u
				&& mpos.x <= -wp.x + (r.x + r.width) * u
				&& mpos.y >= -wp.y + r.y * u
				&& mpos.y <= -wp.y + (r.y + r.height) * u)
			return (map_ui[i].flag);
		i++;
	}
	return (-1);
}
