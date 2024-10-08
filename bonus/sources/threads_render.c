/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jullopez <jullopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:54:35 by jullopez          #+#    #+#             */
/*   Updated: 2024/09/13 18:54:35 by jullopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minirt.h"

static void	calculate_pixel(t_render_thread *thread, uint64_t *x, uint64_t *y)
{
	init_ray(thread->scene, &thread->render.prime_ray, (float)*x, (float)*y);
	thread->render.color_ambiant = convert_rgb(&thread->scene->mlx,
			ambiant_color(&thread->render, thread->scene));
	new_mlx_pixel_put(&thread->scene->mlx, *x, *y,
		thread->render.color_ambiant);
}

static void	thread_render(t_render_thread *thread)
{
	uint64_t	x;
	uint64_t	y;

	thread->pixel_index = 0;
	x = thread->x_coords;
	y = thread->y_coords;
	while (y < thread->scene->screen.height)
	{
		while (x < thread->scene->screen.width)
		{
			calculate_pixel(thread, &x, &y);
			x++;
			thread->pixel_index++;
			if (thread->pixel_index >= thread->pixel_length)
				return ;
		}
		x = 0;
		y++;
	}
	return ;
}

void	*thread_routine(void *arg)
{
	t_render_thread	*thread;

	thread = arg;
	thread_render(thread);
	pthread_mutex_lock(&thread->container->data_lock);
	if (thread->container->do_exit)
	{
		pthread_mutex_unlock(&thread->container->data_lock);
		return (NULL);
	}
	pthread_mutex_unlock(&thread->container->data_lock);
	return (NULL);
}
