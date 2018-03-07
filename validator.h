/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 10:16:50 by dkaplan           #+#    #+#             */
/*   Updated: 2018/03/07 10:16:52 by dkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATOR_H
# define VALIDATOR_H

int	ft_check_map_length(char *str);
int	ft_check_free_space(char *str);
int	ft_check_valid_char(char *str);
int	ft_count_line_length(char *str, int *i);
int	ft_get_rows(char *str);

#endif
