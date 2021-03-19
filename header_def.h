/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_def.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaadi <isaadi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:27:44 by isaadi            #+#    #+#             */
/*   Updated: 2021/03/19 01:42:36 by isaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_DEF_H
# define HEADER_DEF_H

# define TRUE 1
# define FALSE 0

# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

# define A 0
# define B 1

#define PV(x, y) printf("%s = " y, #x, x)
#define EPV(x, y) fprintf(stderr, "%s = " y, #x, x)
#define HERE printf("here?: %s:%d\n", __FILE__, __LINE__)
#define ITERATE_ON_STACK(x, y) for (t_stki y = init_stack_iterator(&y, x); !stack_iterator_end(&y); stack_iterator_advance(&y))

#endif