#include <stdio.h>
#include <errno.h>
#include "inc/libasm.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list *node;

	if (!(node = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	node->next = 0;
	node->content = content;
	return (node);
}

t_list	*ft_lstadd_front(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
	return (new);
}

size_t	ft_lstsize(t_list *begin_list)
{
	if (begin_list == NULL)
		return (0);
	return (ft_lstsize(begin_list->next) + 1);
}

int main()
{
	t_list	*lst;

	lst = NULL;
	lst = ft_lstadd_front(&lst, ft_lstnew("a"));
	lst = ft_lstadd_front(&lst, ft_lstnew("a"));
	lst = ft_lstadd_front(&lst, ft_lstnew("a"));
	lst = ft_lstadd_front(&lst, ft_lstnew("a"));
	lst = ft_lstadd_front(&lst, ft_lstnew("a"));
	lst = ft_lstadd_front(&lst, ft_lstnew("a"));
	lst = ft_lstadd_front(&lst, ft_lstnew("a"));
	lst = ft_lstadd_front(&lst, ft_lstnew("a"));
	lst = ft_list_push_front(&lst, ft_lstnew("a"));
	lst = ft_list_push_front(&lst, ft_lstnew("a"));
	lst = ft_list_push_front(&lst, ft_lstnew("a"));
	lst = ft_list_push_front(&lst, ft_lstnew("a"));
	printf("%lu\n", ft_lstsize(lst));
	printf("%d\n", ft_list_size(lst));
	return (0);
}
