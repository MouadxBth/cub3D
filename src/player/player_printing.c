/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_printing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:44:55 by mbouthai          #+#    #+#             */
/*   Updated: 2023/06/26 15:46:33 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_print_options(t_options *options)
{
	printf("scale: %d\n"
           "color: %d\n"
           "row_gap: %d\n"
           "column_gap: %d\n"
           "x_offset: %d\n"
           "y_offset: %d\n"
           "angle: %f\n",
           options->scale, options->color, options->row_gap, options->column_gap,
           options->x_offset, options->y_offset, options->angle);
}

void	ft_print_movement(t_movement *movement)
{
	printf("up: %d\n"
           "down: %d\n"
           "left: %d\n"
           "right: %d\n"
           "rotate_left: %d\n"
           "rotate_right: %d\n"
           "escape: %d\n"
           "speed: %f\n"
           "rotation_speed: %f\n",
           movement->up, movement->down, movement->left, movement->right,
           movement->rotate_left, movement->rotate_right, movement->escape,
           movement->speed, movement->rotation_speed);
}

void	ft_print_player(t_map *map, t_player *player)
{
	t_point	current;

	current = player->position;
	current.content = '1';
	printf("position: (%f, %f, %d, collision: %d)\n"
    "direction: (%f, %f)\n"
           "plane: (%f, %f)\n"
           "rays: %d\n"
           "dof: %d\n"
           "angle: %f\n",
		   player->position.x,player->position.y,player->position.content,
           ft_check_content(map, &current),
		   player->direction.x, player->direction.y,
		   player->plane.x, player->plane.y, player->rays, player->dof, player->angle);
	printf("\nMovement: \n");
	ft_print_movement(&player->movement);
	printf("\nOptions: \n");
	ft_print_options(&player->options);
}