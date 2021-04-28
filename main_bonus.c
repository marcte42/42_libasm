#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct	s_list
{
	void		*content;
	struct s_list	*next;
}		t_list;


size_t	ft_strlen(char *s);
char	*ft_strcpy(char *d, char *s);
int	ft_strcmp(char *s1, char *s2);
int	ft_write(int fd, char *s, int len);
int	ft_read(int fd, char *s, int len);
char	*ft_strdup(char *s);
int	ft_list_size(t_list *lst);
t_list	*ft_list_push_front(t_list **alst, t_list *new);


t_list	*ft_lstnew(void *content)

{

	t_list *node;



	if (!(node = (t_list *)malloc(sizeof(t_list))))

		return (NULL);

	node->next = 0;

	node->content = content;

	return (node);

}

int	main(void)
{
	printf("\n");
	printf("###\n");
	printf("LISTS\n");
	printf("###\n");
	printf("\n");
	
	t_list *lst;

	lst = 0;
	ft_list_push_front(&lst, ft_lstnew("a"));
	ft_list_push_front(&lst, ft_lstnew("b"));
	ft_list_push_front(&lst, ft_lstnew("c"));
	ft_list_push_front(&lst, ft_lstnew("d"));
	ft_list_push_front(&lst, ft_lstnew("e"));
	ft_list_push_front(&lst, ft_lstnew("f"));
	ft_list_push_front(&lst, ft_lstnew("g"));

	printf("list size : %d\n", ft_list_size(lst));
	while (lst)
	{
		printf("%s   ", (char *)lst->content);
		lst = lst->next;
	}
	printf("\n");
}
