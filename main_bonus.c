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
void ft_list_sort(t_list **begin_list, int(*cmp)());

void	ft_list_sort_c(t_list **begin_list, int(*cmp)())
{
	t_list *lst;
	void *tmp;

	lst = *begin_list;

	while (lst->next)
	{
		if (strcmp(lst->content, lst->next->content) > 0)
		{
			tmp = lst->content;
			lst->content = lst->next->content;
			lst->next->content = tmp;
			lst = *begin_list;
		}
		else
			lst = lst->next;
	}
}

int	main(void)
{
	printf("\n");
	printf("###\n");
	printf("FT_ATOI_BASE\n");
	printf("###\n");
	printf("\n");

	printf("'-12a3' in decimal : %d\n", ft_atoi_base("-12a3", "0123456789"));
	printf("'1f40' in hex : %d\n", ft_atoi_base("1f40", "0123456789abcdef"));
	printf("INT_MAX in decimal : %d\n", ft_atoi_base("+2147483647", "0123456789"));
	printf("INT_MIN in decimal : %d\n", ft_atoi_base("-2147483648", "0123456789"));
	printf("' --7fffffff' in hex : %d\n", ft_atoi_base(" --7fffffff", "0123456789abcdef"));
	printf("'-+-+-+--80000000' in hex : %d\n", ft_atoi_base("-+-+-+--80000000", "0123456789abcdef"));
	printf("'-27a45' in decimal : %d\n", ft_atoi_base("-27a45", "0123456789"));
	printf("'-0' in decimal : %d\n", ft_atoi_base("-0", "0123456789"));
	printf("'-1' in decimal : %d\n", ft_atoi_base("-1", "0123456789"));
	printf("'-10' in decimal : %d\n", ft_atoi_base("-10", "0123456789"));
	printf("'a' in hex : %d\n", ft_atoi_base("a", "0123456789abcdef"));
	printf("'42' in hex : %d\n", ft_atoi_base("42", "0123456789abcdef"));

	printf("\n");
	printf("###\n");
	printf("LIST_PUSH_FRONT\n");
	printf("###\n");
	printf("\n");
	
	t_list *lst;
	t_list *ptr;

	lst = NULL;
	ft_list_push_front(&lst, strdup("albert"));
	ft_list_push_front(&lst, strdup("edouard"));
	ft_list_push_front(&lst, strdup("charles"));
	ft_list_push_front(&lst, strdup("maurice"));
	ft_list_push_front(&lst, strdup("laurent"));

	printf("LIST : ");
	ptr = lst;
	while (ptr)
	{
		printf("%s   ", (char *)ptr->content);
		ptr = ptr->next;
	}
	printf("\n");

	printf("\n");
	printf("###\n");
	printf("LIST_SIZE : ");
	printf("%d\n", ft_list_size(lst));
	printf("###\n");
	printf("\n");
	
	printf("###\n");
	printf("LIST_SORT\n");
	printf("###\n");
	printf("\n");

	ft_list_sort(&lst, &ft_strcmp);
	printf("SORTED LIST : ");
	
	ptr = lst;
	while (ptr)
	{
		printf("%s   ", (char *)ptr->content);
		ptr = ptr->next;
	}
	printf("\n");
}
