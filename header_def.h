/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_def.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sickl8 <sickl8@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:27:44 by isaadi            #+#    #+#             */
/*   Updated: 2021/03/06 00:47:09 by sickl8           ###   ########.fr       */
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

#define PV(x, y) printf("%s = " y, #x, x)
#define HERE printf("here?: %s:%d\n", __FILE__, __LINE__)

#endif