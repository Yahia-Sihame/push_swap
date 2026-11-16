/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebajja <ebajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 16:00:25 by ebajja            #+#    #+#             */
/*   Updated: 2026/11/16 16:37:05 by ebajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive(t_nums **head_a, t_nums **head_b, t_bench *bench,
		double disorder)
{
	if (disorder < 20.0)
		simple(head_a, head_b, bench);
	else if (disorder < 50.0)
		medium(head_a, head_b, bench);
	else
		complex(head_a, head_b, bench);
}
