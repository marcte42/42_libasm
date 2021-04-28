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
	printf("###\n");
	printf("FT_STRLEN\n");
	printf("###\n");
	printf("\n");
	
	char *s1 = "";
	char *s2 = "abc";
	char *s3 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nullam imperdiet arcu ac tempus congue. Cras maximus vel neque finibus gravida.";

	printf("'%s' -> libasm : %lu\n", s1, ft_strlen(s1));
	printf("'%s' -> libasm : %lu\n", s2, ft_strlen(s2));
	printf("'%s' -> libasm : %lu\n", s3, ft_strlen(s3));

	
	
	printf("\n");
	printf("###\n");
	printf("FT_STRCPY\n");
	printf("###\n");
	printf("\n");
	
	char dest[150];
	char *ss1 = "";
	char *ss2 = "abc";
	char *ss3 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nullam imperdiet arcu ac tempus congue. Cras maximus vel neque finibus gravida.";

	printf("'%s' dest : %s\n", ss1, ft_strcpy(dest, ss1));
	printf("'%s' dest : %s\n", ss2, ft_strcpy(dest, ss2));
	printf("'%s' dest : %s\n", ss3, ft_strcpy(dest, ss3));

	
	
	printf("\n");
	printf("###\n");
	printf("FT_STRCMP\n");
	printf("###\n");
	printf("\n");
	
	printf("'', 'abc' : %d\n", ft_strcmp("", "abc"));
	printf("'abc', '' : %d\n", ft_strcmp("abc", ""));
	printf("'test', 'zest' : %d\n", ft_strcmp("test", "zest"));
	printf("'', '' : %d\n", ft_strcmp("", ""));



	printf("\n");
	printf("###\n");
	printf("FT_WRITE\n");
	printf("###\n");
	printf("\n");
	
	errno = 0;
	printf(" : %d\n", ft_write(1, "abc", 3));
	printf("ERRNO : %s\n", strerror(errno));
	errno = 0;
	printf(" : %d\n", ft_write(15, "abc", 3));
	printf("ERRNO : %s\n", strerror(errno));
	errno = 0;
	printf(" : %d\n", ft_write(1, "", 0));
	printf("ERRNO : %s\n", strerror(errno));
	errno = 0;
	printf(" : %d\n", ft_write(1, "Lorem ipsum dolor", 17));
	printf("ERRNO : %s\n", strerror(errno));



	printf("\n");
	printf("###\n");
	printf("FT_READ\n");
	printf("###\n");
	printf("\n");

	char buff[50];
	int fd;
	int ret;

	buff[49] = 0;
	fd = open("file", O_RDONLY);
	
	errno = 0;
	printf("%s : %d\n", buff, ret = ft_read(fd, buff, 50));
	printf("ERRNO : %s\n", strerror(errno));
	
	errno = 0;
	printf(" : %d\n", ret = ft_read(15, buff, 50));
	printf("ERRNO : %s\n", strerror(errno));
	
	errno = 0;
	printf("%s : %d\n", buff, ret = ft_read(fd, buff, 50));
	printf("ERRNO : %s\n", strerror(errno));
	
	errno = 0;
	printf("%s : %d\n", buff, ret = ft_read(fd, buff, 50));
	printf("ERRNO : %s\n", strerror(errno));

	errno = 0;
	printf("%s : %d\n", buff, ret = ft_read(fd, buff, 50));
	printf("ERRNO : %s\n", strerror(errno));

	errno = 0;
	printf("%s : %d\n", buff, ret = ft_read(0, buff, 50));
	printf("ERRNO : %s\n", strerror(errno));



	printf("\n");
	printf("###\n");
	printf("FT_STRDUP\n");
	printf("###\n");
	printf("\n");
	
	char *sss1 = "";
	char *sss2 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc eleifend facilisis turpis, id venenatis turpis tristique in. Nullam turpis mauris, ultricies id blandit nec, tincidunt nec ligula.";

	printf("%s\n", ft_strdup(sss1));
	printf("%s\n", ft_strdup(sss2));
}
