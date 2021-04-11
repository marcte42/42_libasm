/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 11:03:34 by marcte            #+#    #+#             */
/*   Updated: 2021/04/11 21:48:28 by marcte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_list
{
	void		*content;
	struct s_list	*next;
}		t_list;


int	ft_strlen(char *s);
char	*ft_strcpy(char *d, char *s);
int	ft_strcmp(char *s1, char *s2);
int	ft_write(int fd, char *s, int len);
int	ft_read(int fd, char *s, int len);
char	*ft_strdup(char *s);
int	ft_list_size(t_list *lst);
t_list	*ft_list_push_front(t_list **alst, t_list *new);
