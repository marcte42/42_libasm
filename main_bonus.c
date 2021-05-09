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
void ft_list_push_front(t_list **alst, void *data);
int ft_atoi_base(char *str, char *base);



int	main(void)
{
	printf("\n");
	printf("###\n");
	printf("LISTS\n");
	printf("###\n");
	printf("\n");
	
	t_list *lst;

	lst = 0;
	ft_list_push_front(&lst, strdup("abc"));
	ft_list_push_front(&lst, strdup("bcd"));
	ft_list_push_front(&lst, strdup("cde"));
	ft_list_push_front(&lst, strdup("def"));
	ft_list_push_front(&lst, strdup("efg"));
	ft_list_push_front(&lst, strdup("fgh"));
	ft_list_push_front(&lst, strdup("ghi"));

	printf("list size : %d\n", ft_list_size(lst));
	while (lst)
	{
		printf("%s   ", (char *)lst->content);
		lst = lst->next;
	}
	printf("\n");
	#include <limits.h>
	printf("%d\n", ft_atoi_base("  -800000", "0123456789"));
}
