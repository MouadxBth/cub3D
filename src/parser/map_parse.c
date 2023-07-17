/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:29:55 by mnadir            #+#    #+#             */
/*   Updated: 2023/05/15 14:30:42 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_parser.h"

static void	ft_is_walled(char **lines, int inx, int jnx, t_map *cub)
{
	size_t	len;

	while ((inx == 0 || !lines[inx + 1]) && lines[inx][jnx])
		if (lines[inx][jnx++] != '1' && !ft_isspace(lines[inx][jnx - 1]))
			ft_yell_err("Map not closed by walls", cub->f_lines);
	if (!(inx == 0 || !lines[inx + 1]))
	{
		len = ft_strlen(lines[inx + 1]);
		while ((len < ft_strlen(lines[inx])) && lines[inx][len])
			if (lines[inx][len++] != '1' && !ft_isspace(lines[inx][len - 1]))
				ft_yell_err("Map not closed by walls", cub->f_lines);
		len = ft_strlen(lines[inx - 1]);
		while ((len < ft_strlen(lines[inx])) && lines[inx][len])
			if (lines[inx][len++] != '1' && !ft_isspace(lines[inx][len - 1]))
				ft_yell_err("Map not closed by walls", cub->f_lines);
		if ((!jnx || ft_isspace(lines[inx][jnx - 1])) && lines[inx][jnx] != '1')
			ft_yell_err("Map not closed by walls", cub->f_lines);
		while ((lines[inx][jnx + 1]) && !ft_isspace(lines[inx][jnx + 1]))
			jnx++;
		if (lines[inx][jnx] != '1')
			ft_yell_err("Map not closed by walls", cub->f_lines);
	}
}

static void	ft_unknown_char(char *line, int *plr_cnt, t_map *cub)
{
	int	inx;

	inx = 0;
	while (line[inx] && !ft_isspace(line[inx]))
	{
		if (line[inx] == '1' || line[inx] == '0' \
			|| line[inx] == 'N' || line[inx] == 'S' \
			|| line[inx] == 'E' || line[inx] == 'W')
		{
			if (line[inx] == 'N' || line[inx] == 'S' \
				|| line[inx] == 'E' || line[inx] == 'W')
				(*plr_cnt)++;
		}
		else
			ft_yell_err("Unknown character in the map", cub->f_lines);
		inx++;
	}
}

static void	ft_is_spc_in_nap(char **lines, int inx, int jnx, t_map *cub)
{
	while (lines[inx][jnx] && !ft_isspace(lines[inx][jnx]))
	{
		if (lines[inx][jnx] == '0' || lines[inx][jnx] == 'N' \
		|| lines[inx][jnx] == 'S' || lines[inx][jnx] == 'E' \
		|| lines[inx][jnx] == 'W')
			if (inx != 0 && lines[inx + 1] && jnx != 0)
				if (ft_isspace(lines[inx - 1][jnx]) || \
					ft_isspace(lines[inx + 1][jnx]) \
					|| ft_isspace(lines[inx][jnx - 1]) \
					|| ft_isspace(lines[inx][jnx + 1]))
					ft_yell_err("A space's inside the map", cub->f_lines);
		jnx++;
	}
}

static void	ft_calc_widtheight(t_map	*cub, char	**lines)
{
	int	inx;

	inx = 0;
	cub->height = 0;
	while (lines[inx])
		inx++;
	cub->height = inx;
	cub->width = ft_calloc(cub->height, sizeof(*(cub->width)));
	if (!cub->width)
		ft_yell_err("Allocation Error.", cub->f_lines);
	inx = 0;
	while (lines[inx])
	{
		cub->width[inx] = ft_strlen(lines[inx]);
		inx++;
	}
}

void	ft_resolve_map(char	**lines, t_map *cub)
{
	int	jnx;
	int	inx;
	int	plr_cnt;

	if (!ft_map_elems_check(cub, 0))
		ft_yell_err("Missing elements before the map", cub->f_lines);
	inx = 0;
	plr_cnt = 0;
	while (lines[inx])
	{
		jnx = 0;
		while (lines[inx][jnx] && ft_isspace(lines[inx][jnx]))
			jnx++;
		if (!(lines[inx][jnx]))
			ft_yell_err("Empty line in map", cub->f_lines);
		ft_unknown_char(&lines[inx][jnx], &plr_cnt, cub);
		ft_is_walled(lines, inx, jnx, cub);
		ft_is_spc_in_nap(lines, inx, jnx, cub);
		inx++;
	}
	if (plr_cnt != 1)
		ft_yell_err("One player is required in the map", cub->f_lines);
	cub->matrix = lines;
	ft_calc_widtheight(cub, lines);
}
