/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 10:16:32 by dkaplan           #+#    #+#             */
/*   Updated: 2018/03/07 10:16:33 by dkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_H
# define UTILITY_H

int	ft_atoi(char *str);
int	ft_isdigit(char c);
int	ft_find_valid_char(char *str, char *empty, char *obs, char *square);
int	ft_find_map_start(char *str);

#endif
