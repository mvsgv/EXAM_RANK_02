#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 302
# endif

char	*ft_strdup(char *src)
{
	int i;
	char *dest;

	i = 0;
	while (src[i])
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	i = 0;
	while(src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	int	i;
	char	line[70000];
	static int buffer_pos;
	static int buffer_read;
	static char buffer[BUFFER_SIZE];
		
	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buffer_pos >= buffer_read)
		{
			buffer_read = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (buffer_read <= 0)
				break;
		}
		if (line[i] == '\n')
			break;
		line[i] = buffer[buffer_pos];
		i++;
		buffer_pos++;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}
