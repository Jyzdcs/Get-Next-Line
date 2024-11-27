#include "get_next_line.h"
#include <stdio.h>

char	*settle_stash(char *stash)
{
	char	*new_stash;
	int			eol;

	eol = ft_strchr(stash, '\n') - stash + 1;
	if (eol == 0)
	{
		eol = ft_strchr(stash, '\0') - stash;
		if (eol == 0)
			return (NULL);
	}
	new_stash = ft_strdup(stash + eol);
	if (!new_stash)
		return (NULL);
	free(stash);
	return (new_stash);
}

char	*ft_fill_line(char *stash)
{
	if (ft_strchr(stash, '\n'))
		return (ft_substr(stash, 0, ft_strchr(stash, '\n') - stash + 1));
	else if (ft_strchr(stash, '\0'))
		return (ft_substr(stash, 0, ft_strchr(stash, '\0') - stash));
	return (NULL);
}

char	*get_next_line(int fd)
{
	char			buffer[BUFFER_SIZE];
	char			*line;
	static char		*stash = "";

	if (fd == -1)
		return (NULL);
	while (read(fd, buffer, BUFFER_SIZE))
	{
		stash = ft_strjoin(stash, buffer);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	line = ft_fill_line(stash); 
	stash = settle_stash(stash);
	return (line);
}

/*
if (!ft_strchr(stash, '\n') && ft_strchr(stash, '\0'))
	{
		line = ft_substr(stash, 0, ft_strchr(stash, '\0') - stash);
		stash = settle_stash(stash, ft_strchr(stash, '\0') - stash);
		if (ft_strlen(stash) == 0)
			return (NULL);
		return (line);
	}
*/

int	main()
{
	int	fd = open("test.txt", O_RDONLY, 1500);
	char *str = "salut";

	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	while(str = get_next_line(fd))
		printf("%s", str);
}